#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int getint(){
  int r=0; char c=getchar();
  while(c<'0' or c>'9') c=getchar();
  while(c>='0' and c<='9') r=r*10+(c-'0'), c=getchar();
  return r;
}
const int N=404;
const int M=250025;
int n, m, a[N], s[M], f[M], c[M], r[M];
vector<int> wt[N];
LL dp[2][N][N];
// dp[ri][si][fi]=
// min( max(dp[ri-1][si][k], a[fi]-a[k]) )
void solve(){
  LL ans=0;
  for(int i=0; i<m; i++)
    wt[r[i]].push_back(i);
  for(int i=1; i<=n; i++)
    for(int j=i; j<=n; j++)
      dp[0][i][j]=a[j]-a[i];
  for(auto qid: wt[0])
    ans=max(ans, dp[0][s[qid]][f[qid]]*(LL)c[qid]);
  for(int rr=1; rr<=n; rr++){
    int now=rr&1, pre=1^now;
    for(int i=1; i<=n; i++){
      int bst=i;
      dp[now][i][i]=0;
      for(int j=i+1; j<=n; j++){
        if(bst+1<j and 
           max(dp[pre][i][bst+1], (LL)a[j]-a[bst+1])<
           max(dp[pre][i][bst], (LL)a[j]-a[bst])) bst++;
        dp[now][i][j]=max(dp[pre][i][bst], (LL)a[j]-a[bst]);
      }
    }
    //for(int i=1; i<=n; i++)
      //for(int j=i+1; j<=n; j++)
        //printf("dp %d %d %d : %lld\n", rr, i, j, dp[now][i][j]);
    for(auto qid: wt[rr])
      ans=max(ans, dp[now][s[qid]][f[qid]]*(LL)c[qid]);
  }
  printf("%lld\n", ans);
}
int main(){
  n=getint();
  m=getint();
  for(int i=1; i<=n; i++)
    a[i]=getint();
  for(int i=0; i<m; i++){
    s[i]=getint();
    f[i]=getint();
    c[i]=getint();
    r[i]=getint();
  }
  solve();
}