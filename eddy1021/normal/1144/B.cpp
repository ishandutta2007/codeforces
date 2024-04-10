#include <bits/stdc++.h>
using namespace std;
const int N=(1<<12);
int n;
int main(){
  cin>>n;
  vector<int> a[2];
  for(int i=0, x; i<n; i++){
    cin>>x;
    a[x%2].push_back(x);
  }
  sort(a[0].begin(), a[0].end());
  sort(a[1].begin(), a[1].end());
  while(a[0].size() and a[1].size()){
    a[0].pop_back();
    a[1].pop_back();
  }
  if(a[0].size()) a[0].pop_back();
  if(a[1].size()) a[1].pop_back();
  cout<<accumulate(a[0].begin(), a[0].end(), 0)+
        accumulate(a[1].begin(), a[1].end(), 0);

}