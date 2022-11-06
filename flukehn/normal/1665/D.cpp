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
const int INF=2000'000'000;
ll qry(ll a,ll b){
 // dbg(a,b);
 // assert(a<b);
  assert(a!=b);
  assert(a>=1&&a<=INF);
  assert(b>=1&&b<=INF);
  cout<<"? "<<a<<" "<<b<<endl;
  ll g;
  cin>>g;
  return g;
}
void solve() {
  ll x=0;
  ll t=1;
  for(int i=0;i<30;++i) {
    t<<=1;
    if(i<30-1 || 1){
      ll r=qry(t/2-x,t/2*3-x);
      if(r>=t) x|=1<<i;
    }/*else{
      auto chk=[](ll x,ll t){
        ll a=x;
        ll b=2*x;
        if(!x) return true;
        if(__builtin_popcount(x)!=1) {
          return qry(a,b) !=x;
        }
        if(2*t-x<=INF) return qry(t-x,2*t-x) !=t;
        return qry(37-x%37, 37*2-x%37) % 37 !=0;
      };
      if(chk(x,t)) x|=1<<i;
    } */
//    dbg(i,t,r,x);
  }
  cout<<"! "<<x<<endl;
}
int main(){
  ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}