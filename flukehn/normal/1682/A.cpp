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
const int N=100111;
char s[N];
int n;
int solve(){
  cin>>n;
  cin>>s;
  int ret=0;
  if(n%2==0){
    int i;
    for(i=0;i<n/2;++i)
      if(s[n/2-1-i]!=s[n/2-1+i]) break;
    ret+=i;
    for(i=0;i<n/2;++i)
      if(s[n/2-i]!=s[n/2+i]) break;
    ret+=i;
  }else{
    ret=1;
    int i;
    for(i=0;i<n/2;++i)
      if(s[n/2-i]!=s[n/2+1+i]) break;
    ret+=i;
    for(i=0;i<n/2;++i)
      if(s[n/2-i-1]!=s[n/2+i]) break;
    ret+=i;
  }
  return ret;
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