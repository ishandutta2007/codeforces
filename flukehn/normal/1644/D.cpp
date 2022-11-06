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
const int mo=998244353;
const int N=2e5+11;
int n,m,k,q;
int r[N],c[N];
int x[N],y[N];
int cnt;
int solve(){
  cin>>n>>m>>k>>q;
  for(int i=1;i<=q;++i) cin>>x[i]>>y[i];
  cnt+=1;
  int ans=1;
  int R=0,C=0;
  for(int i=q;i>=1;--i) {
    if(R==n||C==m) continue;
    if(r[x[i]]!=cnt || c[y[i]]!=cnt) ans=1LL*ans*k%mo;
    if(r[x[i]]!=cnt) {
      R+=1;
      r[x[i]]=cnt;
    }
    if(c[y[i]]!=cnt){
      C+=1;
      c[y[i]]=cnt;
    }
  }
  return ans;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    cout<<solve()<<"\n";
  }
}