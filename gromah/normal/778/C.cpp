#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int n, tot, p, ans, Head[N], Dep[N], Son[N][26];
vector <int> Vec[N], Stack[N];

struct Edge
{
	int next, node, w;
}h[N << 1];

inline void addedge(int u, int v, int w)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].w = w;
}

void dfs(int z)
{
	Vec[Dep[z]].push_back(z);
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node, w = h[i].w;
		if (Dep[d]) continue ;
		Dep[d] = Dep[z] + 1, Son[z][w] = d;
		dfs(d);
	}
}

int DFS(int dep)
{
	int res = 0;
	for (int c = 0; c < 26; c ++)
	{
		Stack[dep + 1].clear();
		int cnt = 0;
		for (int i = 0; i < Stack[dep].size(); i ++)
		{
			int d = Stack[dep][i];
			if (Son[d][c])
			{
				Stack[dep + 1].push_back(Son[d][c]);
				cnt ++;
			}
		}
		res += max(0, cnt - 1);
		if (cnt > 1) res += DFS(dep + 1);
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i ++)
	{
		char ch = '\n';
		scanf("%d%d", &u, &v);
		for (; ch > 'z' || ch < 'a'; ch = getchar()) ;
		addedge(u, v, ch - 'a');
		addedge(v, u, ch - 'a');
	}
	Dep[1] = 1;
	dfs(1);
	p = 0, ans = n;
	for (int d = 1; Vec[d + 1].size(); d ++)
	{
		int tmp = n - Vec[d + 1].size();
		for (int i = 0; i < Vec[d].size(); i ++)
		{
			int x = Vec[d][i];
			Stack[0].clear();
			for (int j = Head[x]; j; j = h[j].next)
			{
				int nd = h[j].node;
				if (Dep[nd] != d + 1) continue ;
				Stack[0].push_back(nd);
			}
			tmp -= DFS(0);
		}
		if (tmp < ans) ans = tmp, p = d;
	}
	printf("%d\n%d\n", ans, p);
	return 0;
}