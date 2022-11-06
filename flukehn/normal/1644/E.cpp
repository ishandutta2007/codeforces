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
int n;
ll solve(){
  string s;
  cin>>n>>s;
  int m=s.size();
  int x=1,y=1;
  for(auto c:s) if(c=='R')x+=1;
  else y+=1;
  ll ans=m+1;
  int i;
  for(i=0;i<m;++i)
    if(s[i]=='R')break;
  while(i+1<m&&s[i+1]=='R')++i;
  int t=i;
  int r=0,d=0;
  for(int j=i+1;j<m;++j)if(s[j]=='D')d+=1;
  if(i<m) ans+=1LL*(n-x)*(d+1);
  for(i=0;i<m;++i)
    if(s[i]=='D')break;
  while(i+1<m&&s[i+1]=='D')++i;
  for(int j=i+1;j<m;++j)if(s[j]=='R')r+=1;
  if(i<m) {
    ans+=1LL*(n-y)*(r+1);
    if(t<m) ans+=1LL*(n-y)*(n-x);
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