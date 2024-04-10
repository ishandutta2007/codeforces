#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,tot,dp[(1<<17)+5],nxt[20][200005];
char f[100005];
bool check(int x)
{
    for(int i=1;i<=m;i++)
    {
        int Now=0,Lst=n+1;
        for(int j=n;j>=0;j--)
        {
            if(f[j]=='a'+i-1 || f[j]=='?') Now++;
            else Now=0;
            nxt[i][j]=Lst; 
            if(Now>=x) Lst=j+x-1;
        }
        nxt[i][n+1]=n+1;
    }
    dp[0]=0;
    for(int i=1;i<tot;i++)
    {
        dp[i]=n+1;
        for(int j=1;j<=m;j++)
        {
            if((i&(1<<(j-1)))==0) continue;
            dp[i]=min(dp[i],nxt[j][dp[i-(1<<(j-1))]]);
        }
    }
    return dp[tot-1]!=n+1;
}
int main()
{
    scanf("%d%d",&n,&m);
    tot=(1<<m);
    for(int i=1;i<=n;i++)
    {
        scanf(" %c",&f[i]);
    }
    int L=0,R=n/m+1;
    while(L<R)
    {
        int Mid=(L+R+1)/2;
        if(check(Mid)) L=Mid;
        else R=Mid-1;
    }
    printf("%d\n",L);
}