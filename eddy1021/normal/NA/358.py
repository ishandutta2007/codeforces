#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=55;
int n, a[N], b[N];
vector<pair<LL,LL>> v;
#define P first
#define C second
const LL inf=1e18;
LL dp[N][N][N], vl[N];
bool good(LL goal){
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      for(int k=0; k<N; k++)
        dp[i][j][k]=inf;
  dp[0][0][0]=0;
  for(int i=0; i<n; i++){
    LL g=v[i].P-goal*v[i].C;
    for(int jj=0; jj<=i; jj++)
      for(int kk=0; jj+kk<=i; kk++){
        if(dp[i][jj][kk] == inf) continue;
        int nj=jj, nk=kk;
        if(i==0 or v[i].P!=v[i-1].P)
          nj+=nk, nk=0;
        dp[i+1][nj][nk+1]=min(dp[i+1][nj][nk+1], dp[i][jj][kk]+g);
        if(nj)
          dp[i+1][nj-1][nk]=min(dp[i+1][nj-1][nk], dp[i][jj][kk]);
      }
  }
  LL ans=inf;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      ans=min(ans, dp[n][i][j]);
  return ans<=0;
}
int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d", &a[i]);
  for(int i=0; i<n; i++)
    scanf("%d", &b[i]);
  for(int i=0; i<n; i++)
    v.push_back({a[i]*1000LL, b[i]});
  sort(v.begin(), v.end(),
       [&](pair<LL,LL>& p1, pair<LL,LL>& p2){
        if(p1.P != p2.P) return p1.P > p2.P;
        return p1.C > p2.C;
       });
  LL bl=0, br=1e12, ans=1;
  while(bl <= br){
    LL bmid=(bl+br)>>1;
    if(good(bmid)) br=bmid-1, ans=bmid;
    else bl=bmid+1;
  }
  printf("%lld\n", ans);
}