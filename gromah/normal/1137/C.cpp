#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <int, int> Pii;
#define N 100000 + 5
#define K 50 + 5
#define mp make_pair
#define INF 0x3f3f3f3f

int n, m, d, cnt, tot, ans, Dfn[N], Low[N], Stack[N], Num[N], Dp[N][K], Head[N], Gcd[N], V[N][K], Del[N], Deg[N], Q[N];
bool Flag[N], Vis[N][K];
char str[N][K];
vector <int> Vec[N], Scc[N];
set <int> Set[N];
Pii q[(N) * (K)];

struct Edge
{
	int next, node, pre, nxt;
}h[N];

void dfs(int z)
{
	static int ord = 0, sz = 0;
	Dfn[z] = Low[z] = ++ ord;
	Stack[++ sz] = z;
	Flag[z] = 1;
	for (int u : Vec[z])
	{
		if (!Dfn[u])
		{
			dfs(u);
			Low[z] = min(Low[z], Low[u]);
		}
		else if (Flag[u])
			Low[z] = min(Low[z], Dfn[u]);
	}
	if (Dfn[z] == Low[z])
	{
		cnt ++;
		int j;
		do
		{
			j = Stack[sz --];
			Flag[j] = 0;
			Scc[cnt].push_back(j);
			Num[j] = cnt;
		} while (j != z);
	}
}

void BFS(int st, int id)
{
	Flag[id] = 1;
	int l = 1, r = 0;
	q[++ r] = mp(st, 0), Vis[st][0] = 1;
	while (l <= r)
	{
		Pii x = q[l ++];
		int z = x.first, t = x.second, _t = t == d - 1 ? 0 : t + 1;
		for (int u : Vec[z])
			if (Num[u] == id && !Vis[u][_t])
			{
				q[++ r] = mp(u, _t);
				Vis[u][_t] = 1;
			}
	}
	Gcd[id] = d;
	for (int i = 1; i < d; i ++)
		if (Vis[st][i])
		{
			Gcd[id] = i;
			break ;
		}
	for (int x : Scc[id])
		for (Del[x] = 0; Vis[x][Del[x]] == 0; Del[x] ++) ;
	for (int i = 0; i < d; i ++)
	{
		if (i >= Gcd[id])
		{
			V[id][i] = V[id][i - Gcd[id]];
			continue ;
		}
		for (int x : Scc[id])
		{
			bool get = 0;
			int _i = (i + Del[x]) % Gcd[id];
			for (int j = 0; !get && _i + j * Gcd[id] < d; j ++)
				get = str[x][_i + j * Gcd[id]] == '1';
			V[id][i] += get;
		}
	}
}

void addedge(int u, int v, int pre, int nxt)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].pre = pre, h[tot].nxt = nxt;
}

void BFS(int st)
{
	int l = 1, r = 0;
	for (int i = 1; i <= cnt; i ++)
	{
		if (!Deg[i])
			Q[++ r] = i;
		for (int j = 0; j < d; j ++)
			Dp[i][j] = -INF;
	}
	Dp[st][0] = 0;
	while (l <= r)
	{
		int z = Q[l ++];
		for (int i = Head[z]; i; i = h[i].next)
		{
			int u = h[i].node;
			if (!(-- Deg[u]))
				Q[++ r] = u;
		}
	}
	for (int t = 1; t <= r; t ++)
	{
		int z = Q[t];
		for (int j = Gcd[z]; j < d; j ++)
			Dp[z][j] = Dp[z][j - Gcd[z]];
		for (int j = 0; j < d; j ++)
		{
			Dp[z][j] += V[z][j];
			ans = max(ans, Dp[z][j]);
		}
		for (int i = Head[z]; i; i = h[i].next)
		{
			int u = h[i].node, pre = h[i].pre, nxt = h[i].nxt;
			for (int j = 0; j < d; j ++)
			{
				int dst = (j + pre + 1 + d - nxt) % Gcd[u];
				Dp[u][dst] = max(Dp[u][dst], Dp[z][j]);
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
	}
	for (int i = 1; i <= n; i ++)
		scanf("%s", str[i]);
	for (int i = 1; i <= n; i ++)
		if (!Dfn[i])
			dfs(i);
	for (int i = 1; i <= n; i ++)
		Flag[i] = 0;
	for (int i = 1; i <= n; i ++)
		if (!Flag[Num[i]])
			BFS(i, Num[i]);
	for (int x = 1; x <= n; x ++)
		for (int u : Vec[x])
			if (Num[x] != Num[u] && Set[Num[x]].find(Num[u]) == Set[Num[x]].end())
			{
				Set[Num[x]].insert(Num[u]);
				addedge(Num[x], Num[u], Del[x], Del[u]);
				Deg[Num[u]] ++;
			}
	BFS(Num[1]);
	printf("%d\n", ans);
	return 0;
}