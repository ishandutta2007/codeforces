#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
int n, i;
ll out;
ll dp [N];
int s [N];
int h [N];
vector <int> v [N];

void dfs (int u, int f)
	{
	s[u] = 1;
	for (int v : v[u])
		if (v!=f)
			{
			h[v] = h[u]+1;
			dfs(v, u);
			s[u] += s[v];
			dp[u] += dp[v];
			}
	dp[u] += h[u];
	}

void go (int u, int f)
	{
	out = max(out, dp[u]);
	for (int v : v[u])
		if (v!=f)
			{
			dp[v] = dp[u]-s[v]+n-s[v];
			go(v, u);
			}
	}

int main()
	{
	scanf ("%d",&n);
	for(i=1; i<n; i++)
		{
		int a, b;
		scanf ("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
		}
	h[1] = 1;
	dfs(1, 0);
	go(1, 0);
	printf ("%lld\n",out);
	return 0;
	}