#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m,x[11],p[11][10001],c[11],d[10001],a[10001],maxn,ans[10001];
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
inline bool cmp(int x,int y)
{
    return d[x]>d[y];
}
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        maxn=-1e9;
        for(int i=1;i<=n;++i)
            cin>>x[i];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                p[i][j]=getchar()^48;
                while(p[i][j]<0||p[i][j]>1)
                    p[i][j]=getchar()^48;
            }
        for(int s=0;s<1<<n;++s)
        {
            for(int i=1;i<=n;++i)
                c[i]=s&(1<<(i-1))? 1:-1;
            for(int i=1;i<=m;++i)
            {
                a[i]=i;
                d[i]=0;
                for(int j=1;j<=n;++j)
                    d[i]+=p[j][i]*c[j];
            }
            sort(a+1,a+m+1,cmp);
            int res=0;
            for(int i=1;i<=n;++i)
                res+=c[i]*x[i];
            for(int i=1;i<=m;++i)
                res-=i*d[a[i]];
            if(res>maxn)
            {
                maxn=res;
                for(int i=1;i<=m;++i)
                    ans[a[i]]=i;
            }
        }
        for(int i=1;i<=m;++i)
            cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}