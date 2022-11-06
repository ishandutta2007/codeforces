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
const int N=300'011;
int n;
int h[N];
ll calc(int s) {
  ll x[2]={0};
  For(i,0,n-1) {
    ll y=h[n-1]-h[i];
    if(!y)break;
    x[1]+=y/2;
    y%=2;
    if(y) x[0]+=1;
  }
  ll l=0,r=1e18;
  while(l<r) {
    ll m=(l+r)/2;
    auto chk=[&](ll m){
      ll y[2];
      y[s]=(m+1)/2;
      y[s^1]=(m)/2;
      if(y[0]<x[0]) return false;
      y[0]-=x[0];
      y[1]+=y[0]/2;
      return y[1]>=x[1];
    };
    if(chk(m)) r=m;
    else l=m+1;
  }
  return l;
}
ll solve(){
  cin>>n;
  For(i,0,n)cin>>h[i];
  sort(h,h+n);
  ll ans=calc(0);
  h[n-1]+=1;
  ans=min(ans,calc(1)+1);
  return ans;
}
int main(){
#ifdef flukehn
  freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--) {
    cout<<solve()<<"\n";
  }
}