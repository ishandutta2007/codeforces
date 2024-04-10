#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct edge
{
    int nxt,to;
}e[100001<<1];
int t,tot,n,m,p[100001],s[100001],h[100001],val[100001],gd[100001];
bool flag;
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
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs(int k,int f)
{
    if(!flag)
        return;
    s[k]=p[k];
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k);
        if(!flag)
            return;
        s[k]+=s[e[i].to];
    }
    gd[k]=s[k]+val[k];
    if(gd[k]&1||gd[k]<0)
    {
        flag=0;
        return;
    }
    gd[k]>>=1;
    if(gd[k]>s[k])
    {
        flag=0;
        return;
    }
}
bool check(int k,int f)
{
    int sum=0;
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        if(!check(e[i].to,k))
            return 0;
        sum+=gd[e[i].to];
    }
    if(sum>min(gd[k],s[k]-p[k]))
        return 0;
    return 1;
}
int main()
{
    t=read();
    while(t--)
    {
        memset(e,0,sizeof e);
        memset(p,0,sizeof p);
        memset(s,0,sizeof s);
        memset(h,0,sizeof h);
        memset(val,0,sizeof val);
        memset(gd,0,sizeof gd);
        tot=0;
        n=read(),m=read();
        flag=1;
        for(register int i=1;i<=n;++i)
            p[i]=read();
        for(register int i=1;i<=n;++i)
            val[i]=read();
        for(register int i=1;i<n;++i)
        {
            int x=read(),y=read();
            add(x,y);
            add(y,x);
        }
        dfs(1,0);
        if(!flag)
        {
            puts("NO");
            continue;
        }
        puts(check(1,0)? "YES":"NO");
    }
    return 0;
}