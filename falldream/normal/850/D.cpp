#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MN 62
#define S 0
#define T 3783
#define INF 2000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,mx,w[MN+5],f[MN+5][MN+5][MN*MN/2],F[MN+5][MN+5][MN*MN/2],g[65][65];
int head[T+5],c[T+5],q[T+5],d[T+5],top,cnt=1;
struct edge{int to,next,w;}e[T*100];

inline void ins(int f,int t,int w)
{
    e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
    e[++cnt]=(edge){f,head[t],0};head[t]=cnt;
}

int dfs(int x,int f)
{
    if(x==T) return f;
    int used=0;
    for(int&i=c[x];i;i=e[i].next)
        if(e[i].w&&d[e[i].to]==d[x]+1)
        {
            int w=dfs(e[i].to,min(f-used,e[i].w));
            used+=w;e[i].w-=w;e[i^1].w+=w;
            if(used==f) return used;
        }
    return d[x]=-1,used;
}

bool bfs()
{
    memset(d,0,sizeof(d));int i,j;
    for(d[q[top=i=1]=S]=1;i<=top;++i)
        for(j=c[q[i]]=head[q[i]];j;j=e[j].next)
            if(e[j].w&&!d[e[j].to]) d[q[++top]=e[j].to]=d[q[i]]+1;
    return d[T];
}


bool Solve(int m)
{
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			for(int k=0;k<=m*(m-1)/2;++k)
				f[i][j][k]=0;
	f[0][0][0]=1;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			for(int k=max(w[j],i*(i-1)/2);k<=m*(m-1)/2;++k)
			{
				if(f[i-1][j][k-w[j]]) f[i][j][k]=1,F[i][j][k]=0;
				if(f[i-1][j-1][k-w[j]]) f[i][j][k]=1,F[i][j][k]=1;
			}
	if(!f[m][n][m*(m-1)/2])	return false;	
	for(int i=1,a=m,b=n,c=m*(m-1)/2;i<=m;++i)
	{
		ins(S,m*m+i,w[b]);
		for(int j=1;j<=m;++j)
		{
			if(i<j) ins((i-1)*m+j,T,1);
			if(i!=j) ins(m*m+i,(min(i,j)-1)*m+max(i,j),1);
		}
		int nc=c-w[b];b-=F[a][b][c];--a;c=nc;
	}
	while(bfs()) dfs(S,INF);printf("%d\n",m);
	for(int i=1;i<=m;++i)
		for(int j=head[m*m+i];j;j=e[j].next)
			if(e[j].to!=S&&!e[j].w) 
			{
				int t=e[j].to,a=(t-1)%m+1,b=(t-1)/m+1;	
				g[i][a==i?b:a]=1;
			}
	for(int i=1;i<=m;++i,puts(""))
		for(int j=1;j<=m;++j)
			printf("%d",g[i][j]); 
	return true;
}

int main()
{
    n=read();mx=n-1;for(int i=1;i<=n;++i) mx=max(mx,w[i]=read());
    sort(w+1,w+n+1); 
    for(++mx;mx<=61;++mx)if(Solve(mx))return 0;
    puts("=(");
    return 0;
}