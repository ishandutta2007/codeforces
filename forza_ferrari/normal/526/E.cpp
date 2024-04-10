#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m,a[2000001],pos[2000001];
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
signed main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        a[i]=a[i+n]=read();
    for(int i=1;i<=n<<1;++i)
        a[i]+=a[i-1];
    while(m--)
    {
        int len=read(),node=0,ans=1e18;
        if(a[n]<=len)
        {
            puts("1");
            continue;
        }
        for(int i=1,j=1;i<=n;++i)
        {
            while(j<=n<<1&&a[j+1]-a[i-1]<=len)
                ++j;
            pos[i]=j;
            pos[i+n]=j+n;
        }
        for(int i=1;i<=n;++i)
            if(!node||a[pos[i]]-a[i-1]<a[pos[node]]-a[node-1])
                node=i;
        for(int i=node+1;i<=pos[node]+1;++i)
        {
            int sum=0,l=(i-1)%n+1,r=l+n-1;
            for(;l<=r;++sum,l=pos[l]+1);
            ans=min(ans,sum);
        }
        cout<<ans<<'\n';
    }
    return 0;
}