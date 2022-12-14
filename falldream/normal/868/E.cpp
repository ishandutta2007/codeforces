#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 50
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[MN+5][MN+5][MN+5][MN+5],n,m,cnt=0,head[MN+5],sz[MN+5],S,vis[MN+5][MN+5][MN+5];
struct edge{int to,next,w;}e[MN*2+5];
inline void ins(int f,int t,int w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
	e[++cnt]=(edge){f,head[t],w};head[t]=cnt;
}

void Dfs(int x,int fa)
{
	for(int i=head[x];i;i=e[i].next) 
		if(e[i].to!=fa) Dfs(e[i].to,x),sz[x]+=sz[e[i].to];	
}
inline void U(int&x,int y){y>x?x=y:0;}
inline void R(int&x,int y){y<x?x=y:0;}
void Dp(int N,int fa,int x)
{
	//cout<<"DP"<<N<<" "<<fa<<" "<<x<<endl;
	if(vis[N][fa][x]) return;vis[N][fa][x]=1; 
	int son=0;
	for(int i=0;i<=N;++i) f[N][fa][x][i]=-1e7;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa)
		{
			++son;Dp(N,x,e[i].to);
			for(int j=N;j;--j)
			{
				U(f[N][fa][x][j],f[N][x][e[i].to][j]+e[i].w);
				for(int k=1;k<j;++k) 
					U(f[N][fa][x][j],min(f[N][fa][x][j-k],f[N][x][e[i].to][k]+e[i].w));
			}
		}
	if(!son) 
		for(int i=0;i<=N;++i) f[N][fa][x][i]=f[N-i][0][x][N-i];
//	for(int j=0;j<=N;++j) printf("%d %d %d %d = %d\n",N,fa,x,j,f[N][fa][x][j]);
}

int main()
{
	n=read();
	for(int i=1,j,k;i<n;++i) j=read(),k=read(),ins(j,k,read());
	S=read();m=read();
	for(int i=1;i<=m;++i) ++sz[read()];
	Dfs(S,0);int ans=1e9;
	for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) Dp(i,0,j);
	for(int i=head[S];i;i=e[i].next) if(sz[e[i].to]) R(ans,f[m][S][e[i].to][sz[e[i].to]]+e[i].w); 
	printf("%d\n",ans);
	return 0;
}