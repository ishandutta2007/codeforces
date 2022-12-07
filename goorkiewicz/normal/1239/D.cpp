#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N = 2000005;
int q, n, m, i, j, cnt;
bool vis [N];
bool col [N];
vector <int> e [N];

void dfs (int u)
	{
	cnt++;
	int v;
	if (col[u]==false)
		{
		if (u<=n)
			v = u+n;
		else
			v = u-n;
		if (vis[v]==false)
			{
			col[v] = true;
			vis[v] = true;
			dfs(v);
			}
		return;
		}

	for (int v : e[u])
		if (vis[v]==false)
			{
			col[v] = false;
			vis[v] = true;
			dfs(v);
			}
	}

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d%d",&n,&m);

		for (i=1; i<=n+n; i++)
			e[i].clear();
		
		while (m--)
			{
			int a, b;
			scanf ("%d%d",&a,&b);
			b += n;
			e[a].push_back(b);
			e[b].push_back(a);
			}

		for (i=1; i<=n+n; i++)
			{
			col[i] = false;
			vis[i] = false;
			}

		cnt = 0;
		col[1] = true;
		vis[1] = true;
		dfs(1);
		assert(cnt%2==0);
		
		if (cnt!=n+n)
			{
			printf ("Yes\n");
			printf ("%d %d\n", cnt/2, n-cnt/2);
			for (i=1; i<=n; i++)
				if (vis[i]==true)
					printf ("%d ", i);
			
			printf ("\n");
			for (i=1; i<=n; i++)
				if (vis[i]==false)
					printf ("%d ", i);
			printf ("\n");
			continue;
			}
	
		for (i=1; i<=n+n; i++)
			{
			col[i] = false;
			vis[i] = false;
			}

		cnt = 0;
		col[1] = false;
		vis[1] = true;
		dfs(1);
		assert(cnt%2==0);
		
		if (cnt!=n+n)
			{
			printf ("Yes\n");
			printf ("%d %d\n", n-cnt/2, cnt/2);
			for (i=1; i<=n; i++)
				if (vis[i]==false)
					printf ("%d ",i);

			printf ("\n");
			for (i=1; i<=n; i++)
				if (vis[i]==true)
					printf ("%d ",i);
			printf ("\n");
			continue;
			}

		printf ("No\n");
		}
	
	return 0;
	}