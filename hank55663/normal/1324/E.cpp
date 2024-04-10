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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
int dp[2005][2005];
int main(){
    int n,h,l,r;
    scanf("%d %d %d %d",&n,&h,&l,&r);
    int a[2005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<2005;i++){
        for(int j=0;j<2005;j++)
            dp[i][j]=-1e9;
    }
    dp[0][0]=0;
    int ans=0;
    for(int i = 1;i<=n;i++){
        for(int j=0;j<h;j++){
         //   printf("%d ",dp[i-1][j]);
            if((j+a[i])%h>=l&&(j+a[i])%h<=r)
            dp[i][(j+a[i])%h]=max(dp[i][(j+a[i])%h],dp[i-1][j]+1);//,printf("!!!\n");
            else
            dp[i][(j+a[i])%h]=max(dp[i][(j+a[i])%h],dp[i-1][j]);
            if((j+a[i]-1+h)%h>=l&&(j+a[i]-1+h)%h<=r)
            dp[i][(j+a[i]-1)%h]=max(dp[i][(j+a[i]-1)%h],dp[i-1][j]+1);//,printf("!!!\n");
            else
            dp[i][(j+a[i]-1)%h]=max(dp[i][(j+a[i]-1)%h],dp[i-1][j]);
            ans=max(ans,dp[i][(j+a[i])%h]);
            ans=max(ans,dp[i][(j+a[i]-1)%h]);
        }
      //  printf("\n");
    }
    printf("%d\n",ans);
}
/*
4+3+3+4+3+2+2+1
*/