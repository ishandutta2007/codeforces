#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
#define MXN 2000005
LL dp[105][105][105];
LL Min[105][105][105];
int c[105];
int main(){
    int n,m,K;
    scanf("%d %d %d",&n,&m,&K);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    int p[105][105];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&p[i][j]);
  //  printf("!\n");
    for(int i = 0;i<=n;i++)
        for(int j=0;j<=K;j++)
            for(int k=0;k<=m;k++)
                Min[i][j][k]=1e18;
   // printf("?\n");
    for(int k=0;k<=m;k++)
    Min[0][0][k]=0;
    for(int i =1;i<=n;i++){
        for(int j=1;j<=K;j++){
            for(int k=1;k<=m;k++){
              ///  printf("%d %d %d\n",i,j,k);
                LL sum=0;
                dp[i][j][k]=1e18;
                for(int t=i;t>0;t--){
                    if(c[t]==0)sum+=p[t][k];
                    else if(c[t]!=k)break;
                    dp[i][j][k]=min(dp[i][j][k],sum+Min[t-1][j-1][k]);
                }
                for(int t=1;t<=m;t++){
                    if(t!=k)
                    Min[i][j][t]=min(Min[i][j][t],dp[i][j][k]);
                }
            }
        }
    }
    LL ans=1e18;
    for(int i=1;i<=m;i++)
    ans=min(ans,dp[n][K][i]);
    if(ans==1e18)ans=-1;
    printf("%lld\n",ans);
    return 0;
}