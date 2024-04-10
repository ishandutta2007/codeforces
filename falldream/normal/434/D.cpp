#include<bits/stdc++.h>
#define S 0
#define T 10051
#define MN 50
#define INF 2000000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,l[MN+5],r[MN+5],A[MN+5],B[MN+5],C[MN+5],ans,en,cnt=1;
int c[T+5],d[T+5],head[T+5],q[T+5],top,id[MN+5][205];
struct edge{int to,next,w;}e[2000005];
inline void ins(int f,int t,int w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
	e[++cnt]=(edge){f,head[t],0};head[t]=cnt;	
}
bool bfs()
{
    memset(d,0,sizeof(d));int i,j;
    for(d[q[top=i=1]=S]=1;i<=top;++i)
        for(j=c[q[i]]=head[q[i]];j;j=e[j].next)
            if(e[j].w&&!d[e[j].to]) d[q[++top]=e[j].to]=d[q[i]]+1;
    return d[T];    
}
int dfs(int x,int f)
{
    if(x==T) return f;int used=0;    
    for(int&i=c[x];i;i=e[i].next)
        if(e[i].w&&d[e[i].to]==d[x]+1)
        {
            int w=dfs(e[i].to,min(f-used,e[i].w));
            e[i].w-=w;e[i^1].w+=w;used+=w;
            if(used==f) return f;    
        }
    return d[x]=-1,used;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) A[i]=read(),B[i]=read(),C[i]=read();
	for(int i=1;i<=n;++i)
	{
		l[i]=read(),r[i]=read();int mx=-1e9;
		for(int j=l[i];j<=r[i];++j) 
			mx=max(mx,A[i]*j*j+B[i]*j+C[i]),id[i][j+100]=++en;
		ans+=mx;ins(S,id[i][l[i]+100],INF);
		for(int j=l[i];j<=r[i];++j)
			ins(id[i][j+100],j<r[i]?id[i][j+101]:T,mx-(A[i]*j*j+B[i]*j+C[i]));
	}
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),d=read();
		for(int j=l[u];j<=r[u];++j) 
			if(j-d>r[v]) ins(id[u][j+100],T,INF);
			else if(j-d>=l[v]) ins(id[u][j+100],id[v][j-d+100],INF);
	}
	while(bfs()) ans-=dfs(S,INF);
	cout<<ans;
	return 0;
}