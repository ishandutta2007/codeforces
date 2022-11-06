#include<iostream>
#include<cstdio>
#include<cstring>
#define N 510
#define ll long long
using namespace std;
ll mod;
int ksm(int a,int b=mod-2)
{
	int r=1;
	for(;b;b>>=1)
	{
		if(b&1) r=1ll*r*a%mod;
		a=1ll*a*a%mod;
	}
	return r;
}
int fa[N*N],n,m;
int find(int x){return x==fa[x]?fa[x]:(fa[x]=find(fa[x]));}
void merge(int x,int y){fa[find(x)]=find(y);}
int a[N*N];
inline int id(int x,int y){return (x-1)*(m+1)+y;}
struct matrix{
	int num[N][N],n;
	int operator ++(void){return ++n;}
	void add(int u,int v){num[u][u]++;num[v][v]++;num[u][v]--;num[v][u]--;}
	int gauss()
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) num[i][j]=(num[i][j]+mod)%mod;
		int f=1;
		for(int i=1;i<n;i++)
		{
			int u=i;
			for(;u<n;u++) if(num[u][i]) break;
			if(u>=n) continue;
			if(u!=i) f*=-1,swap(num[u],num[i]);
			int iv=ksm(num[i][i]);
			for(int j=i+1;j<n;j++)
			{
				int res=1ll*iv*num[j][i]%mod;
				for(int k=i;k<n;k++) num[j][k]=(num[j][k]-1ll*num[i][k]*res%mod+mod)%mod;
			}
		}
		f=(f+mod)%mod;
		for(int i=1;i<n;i++) f=1ll*f*num[i][i]%mod;
		return f;
	}
}g[2];
char s[N][N];
int main()
{
	scanf("%d%d%lld",&n,&m,&mod);
	for(int i=1;i<=(n+1)*(m+1);i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='/') merge(id(i+1,j),id(i,j+1));
			else if(s[i][j]=='\\') merge(id(i,j),id(i+1,j+1));
		}
	}
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=m+1;j++)
			if(find(id(i,j))==id(i,j)) a[id(i,j)]=++g[(i+j)&1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(s[i][j]=='*')
		{
			int x1=a[find(id(i,j))],y1=a[find(id(i+1,j))],x2=a[find(id(i+1,j+1))],y2=a[find(id(i,j+1))];
			g[(i+j)&1].add(x1,x2);
			g[(i+j+1)&1].add(y1,y2);
		}
	printf("%d",(g[0].gauss()+g[1].gauss())%mod);
	return 0;
}