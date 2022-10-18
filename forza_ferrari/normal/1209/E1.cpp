#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,a[13][2001],maxn[2001],id[2001],tmp[1<<12],val[13][1<<12],dp[13][1<<12];
int main()
{
    cin>>t;
    while(t--)
    {
        memset(val,0,sizeof val);
        memset(dp,0,sizeof dp);
        cin>>n>>m;
        for(int i=1;i<=m;++i)
        {
            id[i]=i;
            maxn[i]=0;
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                cin>>a[i][j];
                maxn[j]=max(maxn[j],a[i][j]);
            }
        sort(id+1,id+m+1,[&](int x,int y){return maxn[x]>maxn[y];});
        for(int i=1;i<=min(n,m);++i)
        {
            for(int j=1;j<=n;++j)
            {
                int w=a[1][id[i]];
                for(int j=1;j<n;++j)
                    a[j][id[i]]=a[j+1][id[i]];
                a[n][id[i]]=w;
                for(int s=0;s<1<<n;++s)
                    tmp[s]=0;
                for(int s=1;s<1<<n;++s)
                {
                    tmp[s]=max(tmp[s],tmp[s^(s&-s)]+a[__builtin_ctz(s)+1][id[i]]);
                    val[i][s]=max(val[i][s],tmp[s]);
                }
            }
            for(int s=0;s<1<<n;++s)
                for(int t=s;;t=(t-1)&s)
                {
                    dp[i][s]=max(dp[i][s],dp[i-1][t]+val[i][s^t]);
                    if(!t)
                        break;
                }
        }
        cout<<dp[min(n,m)][(1<<n)-1]<<'\n';
    }
    return 0;
}