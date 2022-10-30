#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <array>
#include <cmath>
using namespace std;


int main (){
  int n, k, it;
  cin >> n >> k;
  int *mass;
  mass = new int[n];
  for (int i=0; i<n; i++){
	  cin >> mass[i];
  }
  int sum=1000000000;
  for (int i=0; i<k; i++){
	  int t=0;
	  for (int j=0; j<n/k; j++){
		t+=mass[i+j*k];  
	  }
	  if (t<sum){
		  it = i;
		  sum=t;
	  }
  }
  cout << it+1;
  return(0);



}