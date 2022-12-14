#include<iostream>
#include<cstdio>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,head[MN+5],cnt=0,col[MN+5],X[MN+5],Y[MN+5];
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt; 
}

void dfs(int x)
{
	for(int i=head[x];i;i=e[i].next)
		if(!col[e[i].to]) col[e[i].to]=col[x]^3,dfs(e[i].to);	
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read(),y=read();
		if(X[x]) ins(i,X[x]),X[x]=0; else X[x]=i;
		if(Y[y]) ins(i,Y[y]),Y[y]=0; else Y[y]=i;	
	}
	for(int i=1;i<=n;++i) if(!col[i]) col[i]=1,dfs(i);
	for(int i=1;i<=n;++i) printf(col[i]==1?"r":"b");
	return 0;
}