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
int a[N];
int n;
int f[N][2];
void solve(){
  cin>>n;
  for(int i=1;i<=n;++i)cin>>a[i];
  a[n+1]=0;
  int cnt=0;
  for(int i=2;i<n;++i){
    if(a[i]>a[i-1]&&a[i]>a[i+1]){
      a[i+1]=max(a[i],a[i+2]);   
      cnt+=1;
    }
  }
  cout<<cnt<<"\n";
  for(int i=1;i<=n;++i)cout<<a[i]<<" \n"[i==n];
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}