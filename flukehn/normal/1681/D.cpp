#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=unsigned long long;
#ifdef flukehn
#include "algo/debug.h"
#else
#define dbg(...) 0
#define debug(...) 0
#endif
int n;
int ans;
int cnt;
string s;
void dfs(int d,ll x){
  //dbg(d,x);
  ++cnt;
  if(d>=ans||cnt>10'000'000)
    return;
  
  s=to_string(x);
  int m=s.size();
  if(d+n-m>=ans) 
    return;
  if(m>=n) {
    ans=d;
    return;
  }
  int f=0;
  for(char c:s)
    f|=1<<(c-'0');
  for(int i=9;i>=2;--i)
    if(f>>i&1)dfs(d+1,x*i);
}
int main(){
#ifdef flukehn
  freopen("D.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n;
  ll x;
  cin>>x;
  ans=n*10;
  dbg(n,x,ans);
  dfs(0,x);
  if(ans>4*n)ans=-1;
  cout<<ans<<'\n';
}