#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define MN 2000
#define pa pair<long long,int> 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
priority_queue<pa,vector<pa>,greater<pa> >q;
int n,m,S,T,p[MN+5],q1[MN+5],q2[MN+5],head[MN+5],cnt=0,rk1[MN+5],rk2[MN+5],num1[MN+5][MN+5],num2[MN+5][MN+5];
long long P[MN+5][MN+5],d1[MN+5],d2[MN+5],f[2][MN+5][MN+5];
struct edge{int to,next,w;}e[200005];
inline void ins(int f,int t,int w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
	e[++cnt]=(edge){f,head[t],w};head[t]=cnt;	
}
void Dij(int s,long long*d,int*Q)
{
	memset(d,63,sizeof(long long)*(n+2));q.push(make_pair(d[s]=0,s));int num=0;
	while(!q.empty())
	{
		while(!q.empty()&&d[q.top().second]!=q.top().first) q.pop();
		if(q.empty()) return;
		int x=q.top().second;q.pop();Q[++num]=x;
		for(int i=head[x];i;i=e[i].next)
			if(d[x]+e[i].w<d[e[i].to]) q.push(make_pair(d[e[i].to]=d[x]+e[i].w,e[i].to));
	}
}
inline void U(long long&x,long long y){y>x?x=y:0;}
inline void D(long long&x,long long y){y<x?x=y:0;}
int main()
{
	n=read();m=read();T=read(),S=read();long long tot=0;
	for(int i=1;i<=n;++i) tot+=(p[i]=read());
	for(int i=1,j,k;i<=m;++i) j=read(),k=read(),ins(j,k,read());
	Dij(S,d1,q1);Dij(T,d2,q2);
	memset(f[1],200,sizeof(f[1]));
	memset(f[0], 40,sizeof(f[0]));
	for(int i=1;i<=n;++i) rk1[q1[i]]=rk2[q2[i]]=i;
	for(int i=0;i<=n;++i) for(int j=1;j<=n;++j) 
		P[i][j]=P[i][j-1]+(rk1[q2[j]]>i?p[q2[j]]:0),
		num1[i][j]=num1[i][j-1]+(rk1[q2[j]]>i),
		num2[i][j]=num2[i][j-1]+(rk2[q1[j]]>i);
	for(int i=0;i<=n;++i) for(int j=0;j<2;++j) f[j][i][n]=f[j][n][i]=0; 
	for(int i=n-1;~i;--i) if(d1[q1[i]]!=d1[q1[n]])
	{
		int nxi=n,nxj=n;
		int j=n-1;for(;num1[i][j]==num1[i][n];--j);
		for(int j=n-1;~j;--j)
		{
			for(;num2[j][nxi-1]!=num2[j][i];--nxi);
			for(;num1[i][nxj-1]!=num1[i][j];--nxj);
			f[0][i][j]=min(f[0][nxi][j],f[1][nxi][j]);
			f[1][i][j]=max(f[1][i][nxj],f[0][i][nxj])+P[i][nxj]-P[i][j];
		}
	}
//	for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) printf("f[0][%d][%d]=%lld f[1][%d][%d]=%lld\n",i,j,f[0][i][j],i,j,f[1][i][j]);
	//cout<<ans<<endl;
	long long ans=f[1][0][0];
	if(ans<-1e16) cout<<ans<<endl;
	if(ans==tot-ans) puts("Flowers");
	else if(ans>tot-ans) puts("Break a heart");
	else puts("Cry");
	return 0;
}