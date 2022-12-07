#include <bits/stdc++.h>
using namespace std;

int n, i, a, b, out;
int seiz [100001];
vector <int> v [100001];

void dfs (int u, int from)
	{
	seiz[u]=1;
	for (int i=0; i!=v[u].size(); i++)
		if (v[u][i]!=from)
			{
			dfs(v[u][i],u);
			seiz[u]+=seiz[v[u][i]];
			}
	if (u!=1 && seiz[u]%2==0)
		out++;
	}

int main ()
	{
	scanf ("%d",&n);
	for (i=1; i!=n; i++)
		{
		scanf ("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
		}
	if (n%2==1)
		{
		printf ("-1\n");
		return 0;
		}
	dfs (1,1);
	printf ("%d\n",out);
	return 0;
	}