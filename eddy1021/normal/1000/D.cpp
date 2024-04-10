#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=998244353;
inline int mul(LL a, int b){
  a*=b;
  return a>=mod?a%mod:a;
}
const int N=1021;
int n, a[N], dp[N], sdp[N], c[N][N];
int main(){
  for(int i=0; i<N; i++) c[i][0]=c[i][i]=1;
  for(int i=2; i<N; i++)
    for(int j=1; j<i; j++)
      c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d", &a[i]);
  dp[n]=sdp[n]=1;
  for(int i=n-1; i>=0; i--){
    if(a[i]>0 and i+a[i]<n){
      for(int j=i+a[i]; j<n; j++)
        dp[i]=(dp[i]+mul(c[j-i][a[i]], dp[j+1]))%mod;
    }
    sdp[i]=(sdp[i+1]+dp[i])%mod;
  }
  sdp[0]=(sdp[0]+mod-1)%mod;
  printf("%d\n", sdp[0]);
}