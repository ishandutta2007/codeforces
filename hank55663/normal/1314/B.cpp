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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
int dp[17][200005][4];
int main(){
    for(int i = 0;i<17;i++){
        for(int j=0;j<200005;j++){
            for(int k=0;k<4;k++)
                dp[i][j][k]=-1e9;
            dp[i][j][0]=0;
        }
    }
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i<k;i++){
        int x;
        scanf("%d",&x);
        dp[0][(x-1)>>1][3]=dp[0][(x-1)>>1][1];
        dp[0][(x-1)>>1][1]=1;
        dp[0][(x-1)>>1][2]=1;
    }
    int ans=0;
    for(int i  = 1 ;i<n;i++){
        for(int j=0;j<(1<<(n-i-1));j++){
            dp[i][j][0]=max(dp[i][j][0],dp[i-1][(j<<1)+1][0]+dp[i-1][(j<<1)][0]);

            dp[i][j][1]=max(dp[i][j][1],dp[i-1][(j<<1)+1][0]+dp[i-1][(j<<1)][1]+1);
            dp[i][j][2]=max(dp[i][j][2],dp[i-1][(j<<1)+1][0]+dp[i-1][(j<<1)][1]+2);
            dp[i][j][0]=max(dp[i][j][0],dp[i-1][(j<<1)+1][0]+dp[i-1][(j<<1)][1]+2);

            dp[i][j][0]=max(dp[i][j][0],dp[i-1][(j<<1)+1][0]+dp[i-1][(j<<1)][2]+2);
            dp[i][j][2]=max(dp[i][j][2],dp[i-1][(j<<1)+1][0]+dp[i-1][(j<<1)][2]+2);

            dp[i][j][0]=max(dp[i][j][0],dp[i-1][(j<<1)+1][0]+dp[i-1][(j<<1)][3]+3);
            dp[i][j][1]=max(dp[i][j][1],dp[i-1][(j<<1)+1][0]+dp[i-1][(j<<1)][3]+3);
            dp[i][j][2]=max(dp[i][j][2],dp[i-1][(j<<1)+1][0]+dp[i-1][(j<<1)][3]+3);
            dp[i][j][3]=max(dp[i][j][3],dp[i-1][(j<<1)+1][0]+dp[i-1][(j<<1)][3]+3);

            dp[i][j][1]=max(dp[i][j][1],dp[i-1][(j<<1)+1][1]+dp[i-1][(j<<1)][0]+1);
            dp[i][j][2]=max(dp[i][j][2],dp[i-1][(j<<1)+1][1]+dp[i-1][(j<<1)][0]+2);
            dp[i][j][0]=max(dp[i][j][0],dp[i-1][(j<<1)+1][1]+dp[i-1][(j<<1)][0]+2);

            dp[i][j][1]=max(dp[i][j][1],dp[i-1][(j<<1)+1][1]+dp[i-1][(j<<1)][1]+2);
            dp[i][j][3]=max(dp[i][j][3],dp[i-1][(j<<1)+1][1]+dp[i-1][(j<<1)][1]+2);

            dp[i][j][0]=max(dp[i][j][0],dp[i-1][(j<<1)+1][1]+dp[i-1][(j<<1)][2]+3);
            dp[i][j][1]=max(dp[i][j][1],dp[i-1][(j<<1)+1][1]+dp[i-1][(j<<1)][2]+3);
            dp[i][j][2]=max(dp[i][j][2],dp[i-1][(j<<1)+1][1]+dp[i-1][(j<<1)][2]+3);
            dp[i][j][3]=max(dp[i][j][3],dp[i-1][(j<<1)+1][1]+dp[i-1][(j<<1)][2]+3);

            dp[i][j][1]=max(dp[i][j][1],dp[i-1][(j<<1)+1][1]+dp[i-1][(j<<1)][3]+3);
            dp[i][j][3]=max(dp[i][j][3],dp[i-1][(j<<1)+1][1]+dp[i-1][(j<<1)][3]+3);

            dp[i][j][0]=max(dp[i][j][0],dp[i-1][(j<<1)+1][2]+dp[i-1][(j<<1)][0]+2);
            dp[i][j][2]=max(dp[i][j][2],dp[i-1][(j<<1)+1][2]+dp[i-1][(j<<1)][0]+2);

            dp[i][j][0]=max(dp[i][j][0],dp[i-1][(j<<1)+1][2]+dp[i-1][(j<<1)][1]+3);
            dp[i][j][1]=max(dp[i][j][1],dp[i-1][(j<<1)+1][2]+dp[i-1][(j<<1)][1]+3);
            dp[i][j][2]=max(dp[i][j][2],dp[i-1][(j<<1)+1][2]+dp[i-1][(j<<1)][1]+3);
            dp[i][j][3]=max(dp[i][j][3],dp[i-1][(j<<1)+1][2]+dp[i-1][(j<<1)][1]+3);

            dp[i][j][0]=max(dp[i][j][0],dp[i-1][(j<<1)+1][2]+dp[i-1][(j<<1)][2]+2);
            dp[i][j][2]=max(dp[i][j][2],dp[i-1][(j<<1)+1][2]+dp[i-1][(j<<1)][2]+2);

            dp[i][j][1]=max(dp[i][j][1],dp[i-1][(j<<1)+1][2]+dp[i-1][(j<<1)][3]+3);
            dp[i][j][2]=max(dp[i][j][2],dp[i-1][(j<<1)+1][2]+dp[i-1][(j<<1)][3]+3);
            dp[i][j][3]=max(dp[i][j][3],dp[i-1][(j<<1)+1][2]+dp[i-1][(j<<1)][3]+3);

            dp[i][j][0]=max(dp[i][j][0],dp[i-1][(j<<1)+1][3]+dp[i-1][(j<<1)][0]+3);
            dp[i][j][1]=max(dp[i][j][1],dp[i-1][(j<<1)+1][3]+dp[i-1][(j<<1)][0]+3);
            dp[i][j][2]=max(dp[i][j][2],dp[i-1][(j<<1)+1][3]+dp[i-1][(j<<1)][0]+3);
            dp[i][j][3]=max(dp[i][j][3],dp[i-1][(j<<1)+1][3]+dp[i-1][(j<<1)][0]+3);

            dp[i][j][1]=max(dp[i][j][1],dp[i-1][(j<<1)+1][3]+dp[i-1][(j<<1)][1]+3);
            dp[i][j][3]=max(dp[i][j][3],dp[i-1][(j<<1)+1][3]+dp[i-1][(j<<1)][1]+3);

            dp[i][j][1]=max(dp[i][j][1],dp[i-1][(j<<1)+1][3]+dp[i-1][(j<<1)][2]+3);
            dp[i][j][2]=max(dp[i][j][2],dp[i-1][(j<<1)+1][3]+dp[i-1][(j<<1)][2]+3);
            dp[i][j][3]=max(dp[i][j][3],dp[i-1][(j<<1)+1][3]+dp[i-1][(j<<1)][2]+3);

            dp[i][j][3]=max(dp[i][j][3],dp[i-1][(j<<1)+1][3]+dp[i-1][(j<<1)][2]+3);
            ans=max(ans,dp[i][j][0]);
            ans=max(ans,dp[i][j][1]);
            ans=max(ans,dp[i][j][2]);
            ans=max(ans,dp[i][j][3]);
         //   printf("%d %d %d %d %d %d\n",i,j,dp[i][j][0],dp[i][j][1],dp[i][j][2],dp[i][j][3]);
        }
    }
    if(k)ans++;
    printf("%d\n",ans);
    return 0;
}