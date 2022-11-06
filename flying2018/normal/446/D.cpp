#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 510
#define M 100010
#define eps 1e-7
using namespace std;
int nxt[M<<1],to[M<<1],head[N],in[N],cnt;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
	in[v]++;
}
int n;
static struct matrix{
	double num[N][N];
	matrix(int u=0){for(int i=1;i<=n;i++) num[i][i]=u;}
}p;
matrix swp;
matrix operator *(const matrix &a,const matrix &b)
{
	memset(swp.num,0,sizeof(swp.num));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			swp.num[i][j]+=a.num[i][k]*b.num[k][j];
	return swp;
}
matrix res;
matrix ksm(matrix a,long long k)
{
	if(k==0) return 1;
	if(k==1) return a;
	res=ksm(a,k>>1);
	if(k&1) return res*res*a;
	else return res*res;
}
double num[N][N],val[N][N];
bool ban[N];
int hban[N],tot;
int cont[N];
double f[N][N];
int main()
{
	int m;
	long long k;
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ban[i]);
		if(ban[i]) hban[++tot]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++) num[i][i]=1;
	for(int i=1;i<=n;i++)
	{
		val[i][i]=-1;
		for(int j=head[i];j;j=nxt[j])
		{
			int v=to[j];
			if(!ban[v])
			val[i][v]+=1.0/in[v];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int u=i;
		for(int j=i+1;j<=n;j++)
		if(abs(val[u][i])<abs(val[j][i]))
		u=j;
		for(int j=i;j<=n;j++)
		swap(val[i][j],val[u][j]);
		for(int j=1;j<=n;j++)
		if(j!=i)
		{
			double t=val[j][i]/val[i][i];
			for(int k=1;k<=n;k++)
			{
				num[j][k]-=num[i][k]*t;
				val[j][k]-=val[i][k]*t;
			}
		}
	}
	hban[tot+1]=1;
	for(int i=1;i<=tot+1;i++)
	{
		memset(cont,0,sizeof(cont));
		int u=hban[i];
		for(int j=head[u];j;j=nxt[j]) cont[to[j]]++;
		for(int j=1;j<=n;j++)
		if(abs(val[j][j])>eps)
		{
			for(int k=1;k<=n;k++)
				f[u][j]+=-1.0/in[u]*cont[k]*num[j][k]/val[j][j];
		}
	}
	if(k==2){printf("%lf",f[1][n]);return 0;}
	n=tot;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		p.num[i][j]=f[hban[i]][hban[j]];
	p=ksm(p,k-2);
	double ans=0;
	for(int i=1;i<=n;i++) ans+=f[1][hban[i]]*p.num[i][n];
	printf("%.10lf",ans);
	return 0;
}