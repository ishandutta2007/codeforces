#include<bits/stdc++.h>
using namespace std;
const int N=400,M=30;
int n,m,d[M][N],f[N*M],x[M][N],y[M][N];
int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
char b[10];
void sol()
{
	scanf("%d",&n);
	m=0;
	for(int i=1;i<=21;i++)
		for(int j=0;j<360;j++)
			d[i][j]=++m;
	for(int i=1;i<=m;i++)
		f[i]=i;
	for(int i=1;i<=21;i++)
		for(int j=0;j<360;j++)
			x[i][j]=y[i][j]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",b);
		int vl,vr,v;
		if(b[0]=='S')
		{
			scanf("%d%d%d",&vl,&vr,&v);
			v=(v?v-1:359);
			for(int i=vl+1;i<=vr;i++)
				x[i][v]=1;
		}
		else
		{
			scanf("%d%d%d",&v,&vl,&vr);
			if(vl<=vr)
			{
				for(int i=vl;i<vr;i++)
					y[v][i]=1;
			}
			else
			{
				for(int i=vl;i<360;i++)
					y[v][i]=1;
				for(int i=0;i<vr;i++)
					y[v][i]=1;
			}
		}
	}
	auto mg=[&](int u,int v)
	{
		u=fa(u),v=fa(v);
		if(u!=v)
			f[u]=v;
	};
	for(int i=1;i<=21;i++)
	{
		for(int j=0;j<360;j++)
			if(!x[i][j])
				mg(d[i][j],d[i][(j+1)%360]);
		if(i<=20)
		{
			for(int j=0;j<360;j++)
				if(!y[i][j])
					mg(d[i][j],d[i+1][j]);
		}
	}
	int z=0;
	for(int i=0;i<360;i++)
		if(fa(d[1][0])==fa(d[21][i]))
			z=1;
	puts(z?"YES":"NO");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}