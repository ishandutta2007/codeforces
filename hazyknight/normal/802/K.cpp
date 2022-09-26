#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
const int INF = 1 << 30;

struct Edge
{
	int to, next, c;
	Edge() {}
}e[MAXN << 1];
int head[MAXN], te = 1;

inline void insert(int u, int v, int c)
{
	e[++te].to = v;
	e[te].c = c;
	e[te].next = head[u];
	head[u] = te;
}

int f[MAXN][2]; // f[v][0] -> not return, f[v][1] -> return
int sum[MAXN];
pair<int, int> w[MAXN];

int n, k, u, v, c;

void dfs(int u, int fa)
{
	for (int j = head[u]; j != 0; j = e[j].next)
	{
		int v = e[j].to;
		if (v != fa)
			dfs(v, u);
	}
	int N = 0;
	for (int j = head[u]; j != 0; j = e[j].next)
	{
		int v = e[j].to;
		if (v != fa)
			w[++N] = make_pair(f[v][0] + e[j].c, j);
	}
	sort(w + 1, w + N + 1);
	reverse(w + 1, w + N + 1);
	sum[0] = 0;
	for (int i = 1; i <= N; i++)
		sum[i] = sum[i - 1] + w[i].first;
	// return
	if (k == 1)
		f[u][0] = 0;
	else
		f[u][0] = sum[min(N, k - 1)];
	// not return
	if (N > k - 1)
	{
		f[u][1] = 0;
		for (int i = 1; i <= N; i++)
		{
			int v = e[w[i].second].to, c = e[w[i].second].c, val = w[i].first;
			if (i <= k - 1)
				f[u][1] = max(f[u][1], sum[k] - val + f[v][1] + c);
			else
				f[u][1] = max(f[u][1], sum[k - 1] + f[v][1] + c);
		}
	}
	else
	{
		f[u][1] = 0;
		for (int i = 1; i <= N; i++)
		{
			int v = e[w[i].second].to, c = e[w[i].second].c, val = w[i].first;
			f[u][1] = max(f[u][1], sum[N] - val + f[v][1] + c);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	memset(f, 0, sizeof(f));
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v >> c;
		insert(u + 1, v + 1, c);
		insert(v + 1, u + 1, c);
	}
	dfs(1, 0);
	cout << max(f[1][0], f[1][1]) << endl;
	return 0;
}