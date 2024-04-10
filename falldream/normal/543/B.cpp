#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 3000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,head[MN+5],cnt=0,ans=1e9,d[MN+5][MN+5],q[MN+5],top;
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt; 
}	
int main()
{
	n=read();m=read();
	memset(d,40,sizeof(d));
	for(int i=1;i<=m;++i) ins(read(),read());
	for(int i=1;i<=n;++i) 
	{
		d[i][i]=0;q[top=1]=i;
		for(int j=1;j<=top;++j)
			for(int k=head[q[j]];k;k=e[k].next)
				if(d[i][e[k].to]>n*10) d[i][q[++top]=e[k].to]=d[i][q[j]]+1;
	}	
	int s=read(),t=read(),l=read();
	int S=read(),T=read(),L=read();
	if(d[s][t]>l||d[S][T]>L) return 0*puts("-1");
	ans=d[s][t]+d[S][T];
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=n;++j)
		{
			if(d[s][i]+d[i][j]+d[j][t]<=l&&d[S][i]+d[i][j]+d[j][T]<=L) 
				ans=min(ans,d[i][j]+d[s][i]+d[j][t]+d[S][i]+d[j][T]);
			if(d[s][i]+d[i][j]+d[j][t]<=l&&d[S][j]+d[i][j]+d[i][T]<=L)
				ans=min(ans,d[i][j]+d[s][i]+d[j][t]+d[S][j]+d[i][T]);
		}
	printf("%d\n",m-ans);
	return 0;
}