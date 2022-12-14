#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 5000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,dfn[MN+5],low[MN+5],q[MN+5],top,d[MN+5],head[MN+5],cnt,ans;
int dn,mn[MN+5],Mn[MN+5],cc,bel[MN+5],inq[MN+5],flag[MN+5];
struct edge{int to,next;}e[MN+5];
inline void ins(int f,int t){e[++cnt]=(edge){t,head[f]};head[f]=cnt;}
int Solve(int x)
{
    memset(d,40,sizeof(d));d[q[top=1]=x]=0;
    for(int i=1;i<=top;++i)
    {
        for(int j=head[q[i]];j;j=e[j].next)
            if(d[q[i]]+1<d[e[j].to]) d[q[++top]=e[j].to]=d[q[i]]+1;
        if(i==1) d[x]=1e9;
    }
    return d[x];
}
void Tarjan(int x)
{
    dfn[x]=low[x]=++dn;inq[q[++top]=x]=1;
    for(int i=head[x];i;i=e[i].next)
        if(!dfn[e[i].to]) Tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
        else if(inq[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
    if(low[x]==dfn[x])
    {
        for(q[top+1]=0,Mn[++cc]=1e9;q[top+1]!=x;--top)
            Mn[cc]=min(Mn[cc],mn[q[top]]),bel[q[top]]=cc,inq[q[top]]=0;
    }
}
int main()
{
    n=read();m=read();
    for(int i=1,j;i<=m;++i) j=read(),ins(j,read());
    for(int i=1;i<=n;++i) mn[i]=head[i]?Solve(i):0;top=0;
    for(int i=1;i<=n;++i) if(!dfn[i]) Tarjan(i);
    for(int i=1;i<=n;++i)
        for(int j=head[i];j;j=e[j].next)
            if(bel[e[j].to]!=bel[i]) flag[bel[i]]=1;
    for(int i=1;i<=cc;++i)if(!flag[i])ans+=Mn[i]?Mn[i]*998+1:0;
    cout<<ans+n;
    return 0;
}