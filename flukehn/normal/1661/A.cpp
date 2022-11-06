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
const int N=30;
ll f[N][2];
ll a[N][2];
int n;
ll solve() {
  cin>>n;
  For(i,0,n)cin>>a[i][0];
  For(i,0,n)cin>>a[i][1];
  memset(f,0x3f,sizeof f);
  f[0][0]=f[0][1]=0;
  For(i,1,n) {
    For(u,0,2)For(v,0,2) {
      f[i][u]=min(f[i][u], f[i-1][v]+
          abs(a[i][u]-a[i-1][v]) + abs(a[i][u^1]-a[i-1][v^1])
          );
    }
  }
    return min(f[n-1][0],f[n-1][1]);
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