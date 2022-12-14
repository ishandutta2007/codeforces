#include<iostream>
#include<cstdio>
#define MN 100000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct edge{int to,next,w;}e[MN*2+5];
int n,m,head[MN+5],cnt=0,vis[MN+5],w[MN+5],flag=1,ans=(mod+1)/2;
inline void ins(int f,int t,int w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
	e[++cnt]=(edge){f,head[t],w};head[t]=cnt;
}
void dfs(int x)
{
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(!vis[e[i].to]) w[e[i].to]=w[x]^e[i].w^1,dfs(e[i].to);
		else if(w[x]^w[e[i].to]^e[i].w^1) flag=0;	
}
int main()
{
	n=read();m=read();
	for(int i=1,j,k;i<=m;++i) j=read(),k=read(),ins(j,k,read());
	for(int i=1;i<=n;++i) if(!vis[i]) dfs(i),ans=ans*2%mod;
	printf("%d\n",flag*ans);
	return 0;
}