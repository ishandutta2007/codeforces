#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<bitset>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define ll long long
#define MN 200000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,d[MN+5],fa[MN+5],head[MN+5],cnt=0,Ans[MN+5],ans,rt,f[MN+5],g[MN+5],flag=1,a[MN+5],b[MN+5],c[MN+5];
struct edge{int to,next;}e[MN+5];
inline void ins(int f,int t){e[++cnt]=(edge){t,head[f]};head[f]=cnt;}
void dfs(int x)
{
    int num1=0,num2=0,num3=0;
    for(int i=head[x];i;i=e[i].next)
    {
        dfs(e[i].to);
        if(f[e[i].to]&&g[e[i].to]) num3=1;
        else if(f[e[i].to]) num1^=1;
        else if(g[e[i].to]) num2^=1;
        else flag=0;
    }
    a[x]=num1;b[x]=num2;c[x]=num3;
    if(num2!=(d[x]^1))
    {
        if(num3) f[x]=1;
        else f[x]=0;
    }
    else f[x]=1;
    if(num2!=d[x])
    {
        if(num3) g[x]=1;
        else g[x]=0;
    }
    else g[x]=1;
    //cout<<x<<" "<<f[x]<<" "<<g[x]<<endl;
}
void Solve(int x,int s)
{
   // cout<<"Solve"<<x<<" "<<s<<endl;
    int myd=d[x]^s,need=0;
    if(myd!=b[x]) need=1;
    for(int i=head[x];i;i=e[i].next)
    {
        if(f[e[i].to]&&g[e[i].to])
        {
            if(need) Solve(e[i].to,0),need=0,f[e[i].to]=0;
        }
        else if(g[e[i].to]) Solve(e[i].to,0);
    }
    Ans[++ans]=x;
    for(int i=head[x];i;i=e[i].next)
        if(f[e[i].to]) Solve(e[i].to,1);
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        fa[i]=read();
        if(fa[i]) ins(fa[i],i),d[i]^=1,d[fa[i]]^=1; else rt=i;
    }
    dfs(rt);
    if(!flag||!g[rt]) return 0*puts("NO");
    Solve(rt,0);puts("YES");
    for(int i=1;i<=n;++i) printf("%d\n",Ans[i]);
    return 0;
}