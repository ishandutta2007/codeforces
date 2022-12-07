#include <bits/stdc++.h>
using namespace std;

int n, i, j, a, b, g, out;
int sieve [200001];
vector <int> e [200001];
vector <int> s [200001];
bool vis [200001];

int dfs (int u)
	{
	int res = 0, max1 = 0, max2 = 0;
	vis[u]=true;
	for (int v : e[u])
		{
		if (vis[v]==true)
			continue;
		auto it = lower_bound(s[g].begin(), s[g].end(), v);
		if (it==s[g].end() || (*it)!=v)
			continue;
		res = dfs(v);
		if (res > max1)
			{
			max2 = max1;
			max1 = res;
			}
		else if (res > max2)
			max2 = res;
		}
	out = max(out, max1+max2+1);
	return max1+1;
	}

int main ()
	{
	scanf ("%d",&n);
	for (i=2; i<=200000; i++)
		if (sieve[i]==0)
			for (j=i; j<=200000; j+=i)
				sieve[j]=i;
	for (i=1; i<=n; i++)
		{
		scanf ("%d",&j);
		while (j!=1)
			{
			s[sieve[j]].push_back(i);
			j/=sieve[j];
			}
		}
	for (i=1; i<n; i++)
		{
		scanf ("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
		}
	for (g=2; g<=200000; g++)
		if (!s[g].empty())
			{
			sort(s[g].begin(), s[g].end());
			for (int u : s[g])
				if (vis[u]==false)
					dfs(u);
			for (int u : s[g])
				vis[u]=false;
			}
	printf ("%d\n",out);
	return 0;
	}