#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
int n,m,k,p,a[1001][1001],sum[1001][2],f[1000001][2];
priority_queue<int> q;
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
signed main()
{
    n=read(),m=read(),k=read(),p=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            a[i][j]=read();
            sum[i][0]+=a[i][j];
            sum[j][1]+=a[i][j];
        }
    for(int i=1;i<=n;++i)
        q.push(sum[i][0]);
    for(int i=1;i<=k;++i)
    {
        f[i][0]=f[i-1][0]+q.top();
        q.push(q.top()-p*m);
        q.pop();
    }
    while(!q.empty())
        q.pop();
    for(int i=1;i<=m;++i)
        q.push(sum[i][1]);
    for(int i=1;i<=k;++i)
    {
        f[i][1]=f[i-1][1]+q.top();
        q.push(q.top()-p*n);
        q.pop();
    }
    int ans=-1ll<<60;
    for(int i=0;i<=k;++i)
        ans=max(ans,f[i][0]+f[k-i][1]-p*i*(k-i));
    printf("%lld\n",ans);
    return 0;
}