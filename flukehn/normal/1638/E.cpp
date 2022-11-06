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
const int N=1e6+11;
ll c[N], ad[N];
int n;
void add(int x,ll v){
  for(;x<=n;x+=x&-x)
    c[x]+=v;
}
ll qry(int x){
  ll r=0;
  for(;x;x-=x&-x)
    r+=c[x];
  return r;
}
void add(int l,int r,ll v){
  add(l,v);
  add(r+1,-v);
}
using pa=pair<int,int>;
map<int,pa> f;
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int Q;
  cin>>n>>Q;
  f[1]=pa(n+1,1);
#define fi first
#define se second
  while(Q--){
    string op;
    cin>>op;
    if(op=="Color"){
      int l,r,c;
      cin>>l>>r>>c;
      int rr=r;
      while(r>=l){
        auto p=f.upper_bound(r);
        if(p==f.begin()) break;
        --p;
        int L=p->fi;
        auto [R,C]=p->se;
        if(l<=L){
          add(L,r,ad[C]-ad[c]);
          f.erase(p);
          if(r<R)f[r+1]=pa(R,C);
          r=L-1;
        }else{
          add(l,r,ad[C]-ad[c]);
          p->se=pa(l-1,C);
          if(r<R) f[r+1]=pa(R,C);
          break;
        }
      }

      f[l]=pa(rr,c);
    }else if(op=="Add"){
      int c,x;
      cin>>c>>x;
      ad[c]+=x;
    }else{
      int i;
      cin>>i;
      auto p=f.upper_bound(i);
      --p;
      cout<<ad[p->se.se]+qry(i)<<"\n";
    }
  }
}