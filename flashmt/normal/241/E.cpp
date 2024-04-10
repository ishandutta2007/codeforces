#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int oo = 1<<29;

int c[1010][1010],n,f[1010],d[1010],e[1010];

void dfs1(int x)
{
	if (d[x]) return;
	d[x]=1;
	for (int i=1;i<=n;i++)
		if (c[x][i]) dfs1(i);
}

void dfs2(int x)
{
	if (e[x]) return;
	e[x]=1;
	for (int i=1;i<=n;i++)
		if (c[i][x]) dfs2(i);
}

int main()
{
	int m,x[5555],y[5555],ans[5010];
	cin >> n >> m;
	for (int i=0;i<m;i++)
	{
		cin >> x[i] >> y[i]; 
		c[x[i]][y[i]]=1;
	}

	dfs1(1);
	dfs2(n);
	
	for (int i=2;i<=n;i++) f[i]=oo;
	f[1]=0;
	
	for (int i=0;i<n+5;i++)
		for (int j=0;j<m;j++)
		{
			int u=x[j],v=y[j];
			if (d[u] && e[u] && d[v] && e[v])
			{
				f[v]=min(f[v],f[u]+2);
				f[u]=min(f[u],f[v]-1);
			}
		}
		
	int ok=1;
	for (int i=0;i<m;i++)
	{
		int u=x[i],v=y[i];
		if (d[u] && e[u] && d[v] && e[v]) ans[i]=f[v]-f[u];
		else ans[i]=1;
		if (ans[i]<1 || ans[i]>2) ok=0;
	}
	
	if (!ok) puts("No");
	else
	{
		puts("Yes");
		for (int i=0;i<m;i++) cout << ans[i] << endl;
	}
}