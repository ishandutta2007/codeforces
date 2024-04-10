//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m;
bool g[2111][2111],l[2111][2111],r[2111][2111],u[2111][2111],d[2111][2111];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        getchar();
        for(int j=1;j<=m;j++)
        {
            if(getchar()=='.')g[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)u[i][j]=(i==1?1:u[i-1][j])&g[i][j];
    for(int i=n;i>=1;i--)for(int j=1;j<=m;j++)d[i][j]=(i==n?1:d[i+1][j])&g[i][j];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)l[i][j]=(j==1?1:l[i][j-1])&g[i][j];
    for(int i=1;i<=n;i++)for(int j=m;j>=1;j--)r[i][j]=(j==m?1:r[i][j+1])&g[i][j];
    ll ans=0;
    for(int i=2;i<n;i++)ans+=r[i][1];
    for(int i=2;i<m;i++)ans+=d[1][i];
    for(int i=2;i<n;i++)for(int j=2;j<m;j++)
    {
        if(u[i][j]&&r[i][j])ans++;
        if(d[i][j]&&l[i][j])ans++;
        if(l[i][j]&&u[i][j])ans++;
        if(r[i][j]&&d[i][j])ans++;
    }
    for(int i=2;i<n;i++)
    {
        int lt=2,rt=1,cnt1=0,cnt2=0,cnt3=0;
        for(int j=2;j<m;j++)
        {
            if(g[i][j])
            {
                rt=j;
                if(u[i][j])ans+=cnt1-(j==2?0:u[i][j-1]),cnt1++;
                if(d[i][j])ans+=cnt2-(j==2?0:d[i][j-1]),cnt2++;
                if(u[i][j]&&d[i][j])cnt3++;
            }
            if(!g[i][j]&&lt<rt||g[i][j]&&j==m-1)
            {
                ans+=cnt1*cnt2-cnt3;
            }
            if(!g[i][j])lt=j+1,cnt1=cnt2=cnt3=0;
        }
    }
    for(int j=2;j<m;j++)
    {
        int lt=2,rt=1,cnt1=0,cnt2=0,cnt3=0;
        for(int i=2;i<n;i++)
        {
            if(g[i][j])
            {
                rt=i;
                if(l[i][j])ans+=cnt1-(i==2?0:l[i-1][j]),cnt1++;
                if(r[i][j])ans+=cnt2-(i==2?0:r[i-1][j]),cnt2++;
                if(l[i][j]&&r[i][j])cnt3++;
            }
            if(!g[i][j]&&lt<rt||g[i][j]&&i==n-1)
            {
                ans+=cnt1*cnt2-cnt3;
            }
            if(!g[i][j])lt=i+1,cnt1=cnt2=cnt3=0;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}