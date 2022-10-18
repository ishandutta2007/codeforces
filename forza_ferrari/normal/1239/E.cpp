#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans[31][2],a[51],pre[31][2500001],sum;
bool dp[31][2500001],vis[51];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        sum+=a[i]=read();
    for(int i=1;i<=n;++i)
        sum+=a[i+n]=read();
    sort(a+1,a+n+n+1);
    ans[1][0]=a[1];
    ans[n][1]=a[2];
    sum-=a[1]+a[2];
    dp[0][0]=1;
    for(int i=3;i<=n+n;++i)
        for(int j=n-1;j;--j)
            for(int k=a[i];k<=sum;++k)
                if(!dp[j][k]&&dp[j-1][k-a[i]])
                {
                    dp[j][k]=1;
                    pre[j][k]=i;
                }
    for(int i=sum>>1;~i;--i)
        if(dp[n-1][i])
        {
            int s=i;
            for(int j=n-1;j;--j)
            {
                ans[j+1][0]=a[pre[j][s]];
                vis[pre[j][s]]=1;
                s-=a[pre[j][s]];
            }
            int pos=1;
            for(int j=n+n;j>=3;--j)
                if(!vis[j])
                    ans[pos++][1]=a[j];
            break;
        }
    for(int i=1;i<=n;++i)
        cout<<ans[i][0]<<" ";
    cout<<'\n';
    for(int i=1;i<=n;++i)
        cout<<ans[i][1]<<" ";
    cout<<'\n';
    return 0;
}