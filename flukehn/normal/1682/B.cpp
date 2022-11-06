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
const int N=200111;
int n;
int p[N];
int solve(){
  cin>>n;
  For(i,0,n)cin>>p[i];
  int ans=~0u>>1;
  For(i,0,n)if(p[i]!=i) ans&=p[i];
  return ans;
}
int main(){
#ifdef flukehn
  freopen("B.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    cout<<solve()<<"\n";
  }
}