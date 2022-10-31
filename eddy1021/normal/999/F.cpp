#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=101010;
int n, k, c[N], f[N], h[N];
const int K=514;
int dp[10*K];
int cal(int x){
  if(f[x] == 0) return 0;
  int atmst=min(f[x]*k, c[x]);
  for(int i=0; i<=atmst; i++)
    dp[i]=0;
  while(f[x]--){
    for(int i=atmst; i>=0; i--)
      for(int j=1; j<=k and i-j>=0; j++)
        dp[i]=max(dp[i], dp[i-j]+h[j]);
  }
  return dp[atmst];
}
int main(){
  scanf("%d%d", &n, &k);
  for(int i=0; i<n*k; i++){
    int ci; scanf("%d", &ci);
    c[ci]++;
  }
  for(int i=0; i<n; i++){
    int fi; scanf("%d", &fi);
    f[fi]++;
  }
  for(int i=1; i<=k; i++) scanf("%d", &h[i]);
  int ans=0;
  for(int i=0; i<N; i++)
    ans+=cal(i);
  cout<<ans<<endl;
}