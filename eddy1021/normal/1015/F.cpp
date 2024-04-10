#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline int add(int a, int b){
  a+=b;
  return a>=mod?a-mod:a;
}
const int N=222;
int n, len, f[N];
char c[N];
int dp[2][N][N];
int nxtk[N][2];
char cval(int bb){
  return ")("[bb];
}
int main(){
  scanf("%d", &n);
  n<<=1;
  scanf("%s", c);
  len=strlen(c);
  f[0]=-1;
  for(int i=1, ff=-1; i<len; i++){
    while(ff >= 0 and c[ff+1] != c[i]) ff=f[ff];
    if(c[ff+1] == c[i]) ff++;
    f[i]=ff;
  }
  for(int i=0; i<=len; i++)
    for(int b=0; b<2; b++){
      if(i == len){
        nxtk[i][b]=len;
        continue;
      }
      int reali=i-1;
      while(reali >= 0 and c[reali+1] != cval(b)) reali=f[reali];
      if(c[reali+1] == cval(b)) reali++;
      nxtk[i][b]=reali+1;
    }

  dp[0][0][0]=1;
  int atmst=n>>1;
  for(int i=0; i<n; i++){
    int now=i&1, nxt=1^now;
    for(int j=0; j<=atmst; j++)
      for(int k=0; k<=len; k++)
        dp[nxt][j][k]=0;

    for(int j=0; j<=min(i, atmst); j++)
      for(int k=0; k<=len; k++){
        if(dp[now][j][k] == 0) continue;
        for(int b=0; b<2; b++){
          int nj=j+(b==0?-1:+1);
          if(nj >= 0 and nj <= atmst){
            int nk=nxtk[k][b];
            dp[nxt][nj][nk]=add(dp[nxt][nj][nk],
                                dp[now][j][k]);
          }
        }
      }
  }
  printf("%d\n", dp[n&1][0][len]);
}