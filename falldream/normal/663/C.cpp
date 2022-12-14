#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char Kind[10];
int n,m,head[MN+5],flag,cnt=0,vis[MN+5],a[MN+5],num=0;
struct edge{int to,next,w;}e[MN*2+5];
inline void ins(int f,int t,int w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
	e[++cnt]=(edge){f,head[t],w};head[t]=cnt;	
}
void dfs(int x,int k,int c)
{
	vis[x]=k;num+=a[x]==1;
	for(int i=head[x];i;i=e[i].next)
		if(vis[e[i].to]!=k) a[e[i].to]=e[i].w^c^a[x],dfs(e[i].to,k,c);
		else flag&=(a[x]^a[e[i].to]^e[i].w^c^1);	
}
int Solve(int c)
{
	memset(vis,-1,sizeof(vis));
	memset(a,0,sizeof(a));int res=0;
	for(int i=1;i<=n;++i) if(vis[i]==-1)
	{
		num=0;a[i]=0;flag=1;dfs(i,0,c);int t=flag?num:1e9;
		num=0;a[i]=1;flag=1;dfs(i,1,c);int T=flag?num:1e9;
		if(t==1e9&&T==1e9) return 1e9;
		if(t<T) a[i]=0,dfs(i,2,c),res+=t;
		else res+=T;
	}
	return res;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read();scanf("%s",Kind+1);
		ins(x,y,Kind[1]=='R');	
	}
	int res=0;
	if(Solve(0)<Solve(1)) res=Solve(0);
	else res=Solve(1);
	if(res>n) return 0*puts("-1");
	printf("%d\n",res);
	for(int i=1;i<=n;++i) if(a[i]) printf("%d ",i);
	return 0;
}