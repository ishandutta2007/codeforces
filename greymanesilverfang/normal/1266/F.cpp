#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 6e5;
std::vector<int> adj[N];
int h[N], p[N];
std::vector<int> event[N];
int mark[N]; // reset chk[] in O(1)
int cnt[N], maxc[N]; // max count of child

int& maxi(int &x, const int &y)
{
	return x < y ? x = y : x;
}

int dfs1(int u, int x) // set height
{
	h[u] = 0;
	p[u] = x;
	for (int v : adj[u])
		if (v != x)
			maxi(h[u], dfs1(v, u) + 1);
	return h[u];
}

void dfs2(int u, int x) // set event
{
	event[0].push_back(u);
	bool max = false;
	int max2 = x;
	for (int v : adj[u])
		if (h[v] < h[u])
		{
			int tmp = h[v] + 1;
			event[tmp].push_back(u);
			if (!max && tmp == h[u])
				max = true;
			else 
				maxi(max2, tmp);
		}
	for (int v : adj[u])
		if (h[v] < h[u])
		{
			int tmp = h[v] + 1 == h[u] ? max2 + 1 : h[u] + 1;
			dfs2(v, tmp);
			event[tmp].push_back(v);
		}
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	std::vector<int> res(2 * n, 1);
	int ans1 = 1, ans2 = 1;
	int time = 0;
	for (int i = n; i--;)
	{
		++time;
		for (int x : event[i])
		{
			++cnt[x];
			maxi(ans1, cnt[x]);
			maxi(ans2, std::max(cnt[p[x]] + maxi(maxc[p[x]], cnt[x]), cnt[x] + maxc[x]) - 2);
			if (mark[x] < time)
			{
				mark[x] = time;
				maxi(res[2 * i + 1], cnt[x]);
			}
		}
		maxi(res[2 * i - 1], ans1);
		maxi(res[2 * i], std::max(ans1, ans2));
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
	puts("");
}