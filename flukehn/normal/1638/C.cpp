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
const int N=1e5+11;
int n,a[N];
int b[N];
int solve(){
  cin>>n;
  for(int i=1;i<=n;++i)cin>>a[i];
  int t=0;
  for(int i=1;i<=n;++i){
    if(t&&b[t]>a[i]){
      int w=b[t];
      while(t&&b[t]>a[i])t-=1;
      b[++t]=w;
    }else{
      b[++t]=a[i];
    }
    //for(int j=1;j<=t;++j) debug(b[j]<<" \n"[j==t]);
  }
  return t;
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