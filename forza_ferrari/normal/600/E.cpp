#include<iostream>
#include<cstdio>
using namespace std;
struct edge
{
    int nxt,to;
}e[100001<<1];
int n,a[100001],tot,h[100001],t[100001];
long long ans[100001],s[100001],son[100001];
long long sum,maxn;
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
void print(long long x)
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
void dfs1(int k,int f)
{
    s[k]=1;
    int maxson=-1;
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs1(e[i].to,k);
        s[k]+=s[e[i].to];
        if(s[e[i].to]>maxson)
        {
            maxson=s[e[i].to];
            son[k]=e[i].to;
        }
    }
}
void dfs2(int k,int f)
{
    --t[a[k]];
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs2(e[i].to,k);
    }
}
void dfs3(int k,int f,int ban)
{
    ++t[a[k]];
    if(t[a[k]]==maxn)
        sum+=a[k];
    if(t[a[k]]>maxn)
    {
        maxn=t[a[k]];
        sum=a[k];
    }
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f||e[i].to==ban)
            continue;
        dfs3(e[i].to,k,ban);
    }
}
void dfs4(int k,int f)
{
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f||e[i].to==son[k])
            continue;
        dfs4(e[i].to,k);
        dfs2(e[i].to,k);
        maxn=sum=0;
    }
    if(son[k])
        dfs4(son[k],k);
    dfs3(k,f,son[k]);
    ans[k]=sum;
}
int main()
{
    n=read();
    for(register int i=1;i<=n;++i)
        a[i]=read();
    for(register int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    dfs1(1,0);
    dfs4(1,0);
    for(register int i=1;i<=n;++i)
    {
        print(ans[i]);
        putchar(' ');
    }
    puts("");
    return 0;
}