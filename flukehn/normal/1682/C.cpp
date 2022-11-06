#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifdef flukehn
#include "algo/debug.h"
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
int a[N],n;
int solve(){
  cin>>n;
  For(i,0,n)cin>>a[i];
  sort(a,a+n);
  int s1=0,s2=0;
  for(int i=0,j;i<n;i=j){
    for(j=i;j<n&&a[j]==a[i];++j);
    if(j-i>1)s2+=1;
    else s1+=1;
  }
  return s2+(s1+1)/2;
}
int main(){
#ifdef flukehn
  freopen("C.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    cout<<solve()<<"\n";
  }
}