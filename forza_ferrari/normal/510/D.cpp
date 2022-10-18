#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
int n,c[305],l[305],cnt[305],p[305][11],ans,dp[1005];
int main()
{
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)
        scanf("%d",&l[i]);
    for(register int i=1;i<=n;++i)
        scanf("%d",&c[i]);
    ans=1061109567;
    for(register int i=1;i<=n;++i)
    {
        for(register int j=2;j*j<=l[i];++j)
        {
            if(l[i]%j)
                continue;
            while(l[i]%j==0)
                l[i]/=j;
            p[i][++cnt[i]]=j;
        }
        if(l[i]^1)
            p[i][++cnt[i]]=l[i];
    }
    for(register int i=1;i<=n;++i)
    {
        memset(dp,0x3f,sizeof dp);
        dp[(1ll<<cnt[i])-1]=c[i];
        for(register int j=1;j<=n;++j)
            if(i^j)
            {
                int w=0;
                for(register int l=1;l<=cnt[i];++l)
                    for(register int r=1;r<=cnt[j];++r)
                        if(p[i][l]==p[j][r])
                        {
                            w|=(1<<(l-1));
                            break;
                        }
                for(register int k=0;k<(1ll<<cnt[i]);++k)
                    dp[k&w]=min(dp[k&w],dp[k]+c[j]);
            }
        ans=min(ans,dp[0]);
    }
    printf("%d\n",ans^1061109567? ans:-1);
    return 0;
}