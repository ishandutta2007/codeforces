#include<iostream>
#include<cstdio>
#include<vector>
#define MN 400000
#define pa pair<int,int>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,X[MN+5],Y[MN+5],d[MN+5],ans=0,vis[MN+5],head[MN+5],cnt=0;
struct edge{int to,next,w;}e[MN*2+5];
inline void ins(int f,int t,int w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;++d[f];
	e[++cnt]=(edge){f,head[t],w};head[t]=cnt;++d[t];
}
void dfs(int x)
{	
	for(int&i=head[x];i;i=e[i].next)
		if(!vis[e[i].w]) 
		{
			vis[e[i].w]=1;
			int v=e[i].to;
			dfs(v);	
			X[++ans]=x;Y[ans]=v;
			if(ans&1) swap(X[ans],Y[ans]);
		}
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i) ins(read(),read(),i);
	for(int i=1,j=0;i<=n;++i) if(d[i]&1) j?(ins(j,i,++m),j=0):j=i; 
	if(m&1) ins(1,1,++m);dfs(1);printf("%d\n",ans);
	for(int i=1;i<=ans;++i) printf("%d %d\n",X[i],Y[i]);
	return 0;
}