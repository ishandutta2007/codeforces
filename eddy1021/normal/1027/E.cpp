#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=998244353;
inline int add(int a, int b){
  a+=b;
  return a>=mod?a-mod:a;
}
inline int mul(LL a, int b){
  a*=b;
  return a>=mod?a%mod:a;
}
const int N=514;
int n, K;
int dp[2][N][N][2], way[N];
int main(){
  cin>>n>>K;
  dp[1][1][1][1]=1;
  for(int i=1; i<n; i++){
    int now=i&1, nxt=1^now;
    for(int j=0; j<=i+1; j++)
      for(int k=0; k<=i+1; k++)
        for(int b=0; b<2; b++)
          dp[nxt][j][k][b]=0;
    for(int j=0; j<=i; j++)
      for(int k=0; k<=i; k++)
        for(int b=0; b<2; b++){
          if(dp[now][j][k][b] == 0) continue;
          int val=dp[now][j][k][b];
          for(int nb=0; nb<2; nb++){
            int nk=(nb==b)?k+1:1;
            int nj=max(j, nk);
            int& ndp=dp[nxt][nj][nk][nb];
            ndp=add(ndp, val);
          }
        }
  }
  int ans=0;
  for(int j=0; j<=n; j++)
    for(int k=0; k<=n; k++)
      for(int b=0; b<2; b++)
        way[j]=add(way[j], dp[n&1][j][k][b]);
  for(int j=1; j<=n; j++)
    for(int k=1; k<=n and j*k<K; k++)
      ans=add(ans, mul(way[j], way[k]));
  ans=add(ans, ans);
  printf("%d\n", ans);
}