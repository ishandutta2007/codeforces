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
const int N=200'011;
vector<int> e[N];
int p[N];
int n;
int solve() {
  cin>>n;
  for(int i=1;i<=n;++i) e[i].clear();
  for(int i=2;i<=n;++i) cin>>p[i];
  for(int i=2;i<=n;++i) {
    e[p[i]].push_back(i);
  }
  vector<int> d;
  for(int i=1;i<=n;++i)
    if(e[i].size()) d.push_back((int)e[i].size());
  d.push_back(1);
  sort(d.begin(),d.end());
  reverse(d.begin(),d.end());
  int m=d.size();
  int l=m,r=2*n;
  while(l<r) {
    int w=(l+r)/2;
    ll tot=0;
    For(i,0,m) {
      if(w<=i) {
        tot=1e9;
        break;
      }
      int c=1;
      if(d[i]>w-i) c+=d[i]-(w-i);
      tot+=c;
    }
    dbg(w,tot);
    if(tot<=w) r=w;
    else l=w+1;
  }
  return l;
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