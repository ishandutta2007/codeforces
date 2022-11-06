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
const int N=55;
int p[N],n;
int ans[N][N];
void solve(){
  cin>>n;
  for(int i=1;i<=n;++i) {
    if(i==1){
      for(int j=1;j<=n;++j) ans[i][j]=j;
    }else {
      for(int j=1;j<=n;++j) ans[i][j]=ans[i-1][j];
      while(true){
        next_permutation(ans[i]+1,ans[i]+n+1);
        int j;
        for(j=3;j<=n;++j)
          if(n-ans[i][j]+1==2*n+2-ans[i][j-1]-ans[i][j-2]) break;
        if(j>n)break;
      }
    }
  }
  for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)cout<<n-ans[i][j]+1<<" \n"[j==n];
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
  srand(time(0));
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}