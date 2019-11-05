#include <iostream> //to print operation
#include <fstream>  //to read file
#include <vector>   //to store data
#include <time.h>   //to check run times of the implementations


using namespace std;


void readFile(vector<int> &list, string filename, int N){

  string line;
  ifstream file;
  file.open(filename);

  for(int i = 0; i < N; i++){
    getline(file, line);
    list.push_back(stoi(line));
  }

  file.close();
}


void BubbleSort(vector<int> &list, int N){

  int temp;
  for(int i = 1; i < N; i++){
    int j = i;
    while(j > 0 && list[j] < list[j-1]){
      //swap the element with the left one until it's no longer lesser one.
      temp = list[j];
      list[j] = list[j-1];
      list[j-1] = temp;
      j--;
    }
  }
}


void Merge(vector<int> &list, int low, int mid, int high){
  int i = low;  //index for low part
  int j = mid;  //index for mid part
  vector<int> temp;

  while(i < mid && j < high) {
    if(list[i] < list[j]){
      temp.push_back(list[i]);
      i++;
    }
    else{
      temp.push_back(list[j]);
      j++;
    }
  }
  //we reached to the end of the either low part, or high port

  if(i >= mid){
    //low part is the drained one, so assigh rest of the high part to the end of the temp
    while(j < high){
      temp.push_back(list[j]);
      j++;
    }
  }
  else{
    //high part is the drained one, so assigh rest of the low part to the end of the temp
    while(i < mid){
      temp.push_back(list[i]);
      i++;
    }
  }

  for(int k=0; k < high - low; k++){
    //copy sorted temp to the where it belongs.
    list[low + k] = temp[k];
  }
}


void MergeSort(vector<int> &list, int low, int high){
  if(high - low > 1){
    int mid = (low + high) / 2; //integer division already cover the round() functionality

    MergeSort(list, low, mid);
    MergeSort(list, mid, high);
    Merge(list, low, mid, high);
  }
}


int main(int argc, char *argv[]){

  string algoType = argv[1];
  string strN = argv[2];
  int N = stoi(strN);
  string  fileName = argv[3];

  cout << "algotype: " << algoType << "\tstrN:" << strN << "\tfileName:" << fileName << endl;

  vector<int> intVector;
  //readFile(intVector, "unsorted.txt", N);
  readFile(intVector, fileName, N);

  if(algoType.compare("m") == 0){
    cout << "Merge Sort in progress for:\t" << N << "\telement" << endl;
    clock_t clk;
    clk = clock();
    MergeSort(intVector, 0, N);
    //give size of the array as a high, bcs in my implementation high points very end of the array.(it doesnt point any element at all.)
    clk = clock() - clk;
    cout << N << "\tInput took:\t" << clk << "\tcloak" << endl;
  }
  else if(algoType.compare("b") == 0){
    cout << "Bubble Sort in progress for:\t" << N << "\telement"<< endl;
    clock_t clk;
    clk = clock();
    BubbleSort(intVector, N);
    clk = clock() - clk;
    cout << N << "\tInput took:\t" << clk << "\tcloak" << endl;
  }

  /*
  cout << "Sorted version" << endl;

  for(int i = 0; i < N; i++){
    cout << intVector[i] << endl;
  }
  */

  return 0;
}
