#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[100005],b[100005],dp[100005],p[100005],f[100005],g[100005];
bool vis[100005],tag[100005];
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
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        f[i]=1e9;
    }
    a[++n]=1e9;
    f[n]=1e9;
    m=read();
    for(int i=1;i<=m;++i)
        b[i]=read();
    sort(b+1,b+m+1);
    for(int i=1;i<=n;++i)
        if(a[i]!=-1)
        {
            tag[i]=1;
            int pos=lower_bound(f+1,f+n+1,a[i])-f-1;
            dp[i]=pos+1;
            p[i]=g[pos];
            f[pos+1]=a[i];
            g[pos+1]=i;
        }
        else
        {
            int pos=n;
            for(int j=m;j>=1;--j)
            {
                while(pos>=1&&f[pos]>=b[j])
                    --pos;
                f[pos+1]=b[j];
                g[pos+1]=i;
            }
        }
    for(int i=dp[n]-1,j=n,val=a[n];i>=1;--i)
    {
        //cout<<j<<'\n';
        if(tag[j])
        {
            if(a[p[j]]!=-1)
            {
                j=p[j];
                val=a[j];
            }
            else
            {
                int pos=lower_bound(b+1,b+m+1,val)-b-1;
                vis[pos]=1;
                val=a[p[j]]=b[pos];
                j=p[j];
            }
        }
        else
        {
            bool flag=0;
            for(int k=j-1;k>=1;--k)
                if(a[k]!=-1&&dp[k]==i&&a[k]<val)
                {
                    val=a[k];
                    j=k;
                    flag=1;
                    break;
                }
            if(!flag)
                for(int k=j-1;k>=1;--k)
                    if(a[k]==-1)
                    {
                        int pos=lower_bound(b+1,b+m+1,val)-b-1;
                        val=a[k]=b[pos];
                        vis[pos]=1;
                        j=k;
                        break;
                    }
        }
    }
    int pos=1;
    for(int i=1;i<n;++i)
    {
        if(a[i]==-1)
        {
            while(pos<=m&&vis[pos])
                ++pos;
            vis[pos]=1;
            a[i]=b[pos];
        }
        cout<<a[i]<<" ";
    }
    cout<<'\n';
    return 0;
}