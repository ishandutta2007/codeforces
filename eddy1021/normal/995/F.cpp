#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3030;
const int mod=1000000007;
inline int add(int a, int b){
  a+=b;
  return a>=mod?a-mod:a;
}
inline int mul(LL a, int b){
  a*=b;
  return a>=mod?a%mod:a;
}
inline int mpow(int a, int b){
  int ret=1;
  while(b){
    if(b&1) ret=mul(ret,a);
    a=mul(a,a);
    b>>=1;
  }
  return ret;
}
int n, d, p[N], dp[N][N];
vector<int> son[N];
int _inv[N+N], *inv;
int main(){
  inv=_inv+N;
  cin>>n>>d;
  d--;
  for(int i=2; i<=n; i++){
    cin>>p[i];
    son[p[i]].push_back(i);
  }
  for(int i=n; i>=1; i--){
    for(int j=0; j<=n; j++)
      dp[i][j]=1;
    for(int s: son[i]){
      for(int j=0; j<=n; j++)
        dp[i][j]=mul(dp[i][j], dp[s][j]);
    }
    for(int j=1; j<=n; j++)
      dp[i][j]=add(dp[i][j], dp[i][j-1]);
  }
  if(d<=n){
    printf("%d\n", dp[1][d]);
    exit(0);
  }
  for(int i=-n; i<=n; i++)
    inv[i]=mpow(i<0?mod+i:i, mod-2);
  int ans=0;
  for(int i=0; i<=n; i++){
    int tans=dp[1][i];
    for(int j=0; j<=n; j++){
      if(i==j) continue;
      tans=mul(tans,d-j);
      tans=mul(tans,inv[i-j]);
    }
    ans=add(ans, tans);
  }
  cout<<ans<<endl;
}