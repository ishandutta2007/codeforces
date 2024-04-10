#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct edge
{
    int nxt,to;
}e[100001<<1];
int n,block,tot,h[100001],dp[100001],ans[100001],cnt,dfn[100001],fa[100001],res;
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
void print(int x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs(int k,int f)
{
    dfn[k]=++cnt;
    fa[cnt]=dfn[f];
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k);
    }
}
inline void check(int len)
{
    res=0;
    for(int i=1;i<=n;++i)
        dp[i]=1;
    for(int i=n;i;--i)
    {
        if(dp[i]==-1)
            continue;
        if(dp[i]>=len)
        {
            ++res;
            dp[i]=-1;
            continue;
        }
        if(!fa[i]||dp[fa[i]]==-1)
            continue;
        if(dp[fa[i]]+dp[i]>=len)
        {
            ++res;
            dp[fa[i]]=-1;
        }
        else
            dp[fa[i]]=max(dp[fa[i]],dp[i]+1);
    }
}
int main()
{
    n=read();
    block=sqrt(n*log2(n));
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    for(int i=1;i<=block;++i)
    {
        check(i);
        ans[i]=res;
        if(!ans[i])
            break;
    }
    for(int i=1,p=n,l,r,mid,tmp;i<=n/block+1;++i)
    {
        l=block+1,r=p,tmp=p+1;
        while(l<=r)
        {
            mid=(l+r)>>1;
            check(mid);
            if(res>=i)
                l=mid+1;
            else
            {
                tmp=mid;
                r=mid-1;
            }
        }
        if(i^1)
            for(int j=tmp;j<=p;++j)
                ans[j]=i-1;
        p=tmp-1;
    }
    for(int i=1;i<=n;++i)
    {
        print(ans[i]);
        putchar('\n');
    }
    return 0;
}