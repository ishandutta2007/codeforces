#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];

int main(){
  
  cin>>n;
  
  for (int x=0;x<n;x++){
    cin>>arr[x];
  }
  
  int curr=n-1;
  while (curr){
    if (arr[curr-1]<arr[curr]) curr--;
    else break;
  }
  cout<<curr<<endl;
}