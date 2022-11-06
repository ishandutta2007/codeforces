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
const int N=1e5+11;
int n,p[N];
void solve(){
  cin>>n;
  for(int i=1;i<=n;++i)cin>>p[i];
  int i;
  for(i=1;i<=n;++i)
    if(p[i]!=i)break;
  if(i<=n){
    int j;
    for(j=i;j<=n;++j)
      if(p[j]==i)break;
    reverse(p+i,p+j+1);
  }
  for(int i=1;i<=n;++i)cout<<p[i]<<" \n"[i==n];
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