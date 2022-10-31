#include<cstdio>
#include<iostream>
#include<map>
#define MP make_pair
using namespace std;
const int N=1010,T=10;
typedef pair<pair<int,int>,int> PIII;
struct rec{int in,out,w,s,v;};
int n,S,num;
map<PIII,int> F;
int f[N][N];
int g[N];
rec a[N];
struct Edge {int y,z,ne;};
Edge e[N];int last[N];
void add(int x,int y,int z)
{
	e[++num].y=y;e[num].z=z;e[num].ne=last[x];last[x]=num;
}
int dp(int i,int S)
{
	if (f[i][S]!=-1) return f[i][S];
	for (int j=1;j<=n;j++)
		if (j!=i&&a[i].in<=a[j].in&&a[j].out<=a[i].out&&a[j].w<=S)
		{
			dp(j,min(S-a[j].w,a[j].s));
		}
	
	for (int j=1;j<=n;j++)
		if (j!=i&&a[i].in<=a[j].in&&a[j].out<=a[i].out&&a[j].w<=S)
			add(a[j].out,a[j].in,f[j][min(S-a[j].w,a[j].s)]);
	g[a[i].in]=0;
	for (int j=a[i].in+1;j<=a[i].out;j++)
	{
		g[j]=g[j-1];
		for (int k=last[j];k;k=e[k].ne)
			g[j]=max(g[j],g[e[k].y]+e[k].z);
		last[j]=0;
	}
	num=0;
	f[i][S]=g[a[i].out]+a[i].v;
	return f[i][S];
}
int main()
{
	scanf("%d%d",&n,&S);
	for (int i=1;i<=n;i++) scanf("%d%d%d%d%d",&a[i].in,&a[i].out,&a[i].w,&a[i].s,&a[i].v);
	for (int i=0;i<=n;i++)
	for (int j=0;j<=S;j++)
		f[i][j]=-1;
	a[0].in=0;a[0].out=n*2+1;
	printf("%d\n",dp(0,S));
	return 0;
}