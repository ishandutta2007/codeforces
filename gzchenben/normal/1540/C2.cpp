#include<cstdio>
#include<map>
#include<algorithm>
#define mod (1000000007)
using namespace std;
int n,k,b[105],lc[105],rc[105],Sum,SumL,SumR;

int dp[105][10005],pf[105][10005],tag[105];
map<int,int> mp;
int getPF(int x,int y)
{
    if(y<tag[x]) return 0;
    if(y>10000+tag[x]) return pf[x][10000];
    return pf[x][y-tag[x]];
}
int DP(int x)
{
//    printf("DP:x=%d ---------------------------",x);
//    for(int i=1;i<=n;i++) printf("L=%d R=%d\n",lc[i]-x,rc[i]-x);
    if(mp[x]) return mp[x]-mod;
    for(int i=0;i<=n;i++) for(int j=0;j<=10000+1;j++) dp[i][j]=pf[i][j]=0;
    for(int i=0;i<=n;i++) tag[i]=0;
    dp[0][0]=1;
    for(int i=0;i<=10000;i++) pf[0][i]=1;
    for(int i=1;i<=n;i++)
    {
        tag[i]=tag[i-1]+lc[i]-x;
        for(int j=max(tag[i],0);j<=tag[i]+10000;j++)
        {
            dp[i][j-tag[i]]=(getPF(i-1,j-lc[i]+x)-getPF(i-1,j-rc[i]+x-1)+mod)%mod;
//            printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
        }
        pf[i][0]=dp[i][0];
        for(int j=1;j<=10000;j++)
        {
            pf[i][j]=(pf[i][j-1]+dp[i][j])%mod;
        }
    }
    mp[x]=pf[n][10000]+mod;
    return pf[n][10000];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&rc[i]);
    }
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d",&b[i]);
        Sum+=b[i];
        rc[i+1]-=Sum;
        lc[i+1]-=Sum;
    }
    for(int i=1;i<=n;i++)
    {
        SumL+=lc[i];
        SumR+=rc[i];
    }
    int Minn=SumL/n-1,Maxn=SumR/n+1;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        x=min(x,Maxn);
        x=max(x,Minn);
        printf("%d\n",DP(x));
    }
}