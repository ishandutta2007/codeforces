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
const int N=3e5+11;
int n,Q;
int x[N],w[N];
ll ans[N];
using pa=pair<int,int>;
vector<pa> e[N];
int p[N];

const ll INF=~0uLL>>2;
ll c[N];
void add(int x,ll v){
  for(;x<=n;x+=x&-x)
    c[x]=min(c[x],v);
}
ll qry(int x){
  ll r=INF;
  for(;x;x-=x&-x)
    r=min(r,c[x]);
  return r;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n>>Q;
  for(int i=1;i<=n;++i){
    cin>>x[i]>>w[i];
  }
  for(int i=1;i<=Q;++i){
    int l,r;
    cin>>l>>r;
    e[l].emplace_back(r,i);
  }
  for(int i=1;i<=n;++i) c[i]=INF;
  int t=0;
  for(int i=n;i>=1;--i) {
    while(t&&w[p[t]]>=w[i]){
      add(p[t], 1LL*(w[i]+w[p[t]]) * (x[p[t]]-x[i]));
      t-=1;
    }
    if(t) add(p[t], 1LL*(w[i]+w[p[t]]) * (x[p[t]]-x[i]));
    p[++t]=i;
    for(auto [r,id]:e[i]){
      ans[id]=qry(r);
    }
  }
  for(int i=1;i<=Q;++i)cout<<ans[i]<<"\n";
}