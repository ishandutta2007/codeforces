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
const int N=5011;
//const int INF=~0u>>1;
int a[N],x,n,s[N];
int f[N],g[N];
void solve(){
  cin>>n>>x;
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
  f[0]=0;
  g[n+1]=0;
  for(int i=1;i<=n;++i) {
    f[i]=0;
    int now=0;
    for(int j=i;j>=1;--j){
      now+=a[j];
      f[i]=max(f[i],now);
    }
    g[i]=0;
    now=0;
    for(int j=i;j<=n;++j){
      now+=a[j];
      g[i]=max(g[i],now);
    }
  }
  ll now=0;
  for(int k=0;k<=n;++k) {
    int mx=-INT_MAX;
    for(int i=k;i<=n;++i)
      mx=max(mx,g[i+1]+f[i-k]+s[i]-s[i-k]);
    now=max(now,mx+1LL*x*k);
    cout<<now<<" \n"[k==n];  
  }
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