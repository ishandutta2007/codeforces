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
string to_string(__int128 x){ 
  int t=x<0;
  string s;
  do s+=x%10+'0';while(x/=10);
  if(t)s+='-';
  reverse(s.begin(),s.end());
  return s;
}
ostream& operator<<(ostream &out,__int128 x){ 
  out<<to_string(x);
  return out;
}
using L=__int128;
const int N=300'011;
int n,K;
ll b[N];
L s[N],t[N];
L a[N];
L solve() {
  for(int i=1;i<=n;++i)cin>>b[i];
  For(i,0,n+2) s[i]=t[i]=0; 
  L ans=0;
  for(int i=n;i>=1;--i) {
    s[i]+=s[i+1];
    t[i]+=t[i+1];
    a[i]=s[i]+t[i]*i;
    if(a[i]>=b[i]) continue;
    dbg(i);
    if(i>=K){
      ll w=(b[i]-a[i]-1)/K+1;
      ans+=w;
      s[i] += w*(K-i);
      t[i] += w;
      s[i-K] -= w*(K-i);
      t[i-K] -= w;
    }else{
      ll w=(b[i]-a[i]-1)/i+1;
      ans+=w;
      t[i]+=w;
    }
  }
  return ans;
}
int main(){
#ifdef flukehn
  freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  while(cin>>n>>K) {
    cout<<solve()<<endl;
  }
}