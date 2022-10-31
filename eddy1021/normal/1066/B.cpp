#include <bits/stdc++.h>
using namespace std;
const int N=1021;
int n, r, a[N];
int main(){
  cin>>n>>r;
  for(int i=0; i<n; i++) cin>>a[i];
  int ans=0, nd=0;
  while(nd < n){
    int cand=-1;
    for(int j=max(0, nd-r+1); j<min(n, nd+r); j++)
      if(a[j]) cand=j;
    if(cand == -1){
      puts("-1");
      exit(0);
    }
    nd=cand+r;
    ans++;
  }
  cout<<ans<<endl;
}