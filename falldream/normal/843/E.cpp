#include<bits/stdc++.h>
#define S 0
#define T 101
#define INF 1000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,cnt=1,s,t,ans,head[T+5],c[T+5],d[T+5],q[T+5],top,in[T+5],bel[T+5],Ans[1005];
struct edge{int to,next,w;}e[10005];
struct Edge{int x,y,g;}a[1005];
inline void ins(int f,int t,int w)
{
    e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
    e[++cnt]=(edge){f,head[t],0};head[t]=cnt;
}
int dfs(int x,int to,int f)
{
    if(x==to) return f;int used=0;
    for(int&i=c[x];i;i=e[i].next)
        if(e[i].w&&d[e[i].to]==d[x]+1)
        {
            int w=dfs(e[i].to,to,min(e[i].w,f-used));
            used+=w;e[i].w-=w;e[i^1].w+=w;
            if(used==f) return f;
        }
    return d[x]=-1,used;
}
bool bfs(int s,int t)
{
    memset(d,0,sizeof(d));int i,j;
    for(d[q[top=i=1]=s]=1;i<=top;++i)
        for(j=c[q[i]]=head[q[i]];j;j=e[j].next)
            if(e[j].w&&!d[e[j].to]) d[q[++top]=e[j].to]=d[q[i]]+1;
    return d[t];
}
int main()
{
    n=read();m=read();s=read();t=read();
    for(int i=1;i<=m;++i)
    {
        a[i].x=read();a[i].y=read();a[i].g=read();
        if(a[i].x==s&&a[i].y==t) ++ans;
        else 
        {
            ins(a[i].x,a[i].y,a[i].g?1:INF);
            if(a[i].g) ins(a[i].y,a[i].x,INF);
        }
    }
    while(bfs(s,t)) ans+=dfs(s,t,INF);
    printf("%d\n",ans);
    for(int i=1;i<=n;++i) bel[i]=bool(d[i]);
    memset(head,0,sizeof(head));cnt=1;
    for(int i=1;i<=m;++i)
        if(a[i].g) Ans[i]=cnt+1,ins(a[i].x,a[i].y,10000),++in[a[i].y],--in[a[i].x];
    for(int i=1;i<=n;++i) if(in[i]>0) ins(S,i,in[i]); else if(in[i]<0) ins(i,T,-in[i]);
    ins(t,s,INF);
    while(bfs(S,T)) dfs(S,T,INF);
    for(int i=1;i<=m;++i)
        if(a[i].x==s&&a[i].y==t) puts("1 1");
        else if(!a[i].g) puts("0 1"); else 
        {
            int W=10001-e[Ans[i]].w;
            printf("%d %d\n",W,bel[a[i].x]>bel[a[i].y]?W:INF);
        }
    return 0;
}