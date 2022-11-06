#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair <int, int> Pii;
#define N 100000 + 5
#define M 300
#define K 340 + 5
#define mp make_pair

int n, m, p, tot, cnt, Ord[N], Cnt[N], E[N][3], Ask[N][2], Id[N], Head[N], q[N], Fa[K][N];
map <Pii, bool> Flag;
map <Pii, int> Map;

struct Edge
{
	int next, node;
}h[N << 1];

inline bool cmp(int u, int v)
{
	return mp(Cnt[E[u][2]], E[u][2]) < mp(Cnt[E[v][2]], E[v][2]);
}

inline void addedge(int u, int v)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v;
	h[++ tot].next = Head[v], Head[v] = tot;
	h[tot].node = u;
}

inline void dfs(int z, int col)
{
	if (Id[z] == col) return ;
	q[++ q[0]] = z, Id[z] = col;
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		dfs(d, col);
	}
}

inline int Find(int id, int x)
{
	return Fa[id][x] == x ? x : Fa[id][x] = Find(id, Fa[id][x]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v, c; i <= m; i ++)
	{
		scanf("%d%d%d", &u, &v, &c);
		E[i][0] = u, E[i][1] = v, E[i][2] = c;
		Ord[i] = i, Cnt[c] ++;
	}
	scanf("%d", &p);
	for (int i = 1, u, v; i <= p; i ++)
	{
		scanf("%d%d", &u, &v);
		Flag[mp(u, v)] = 1;
		Ask[i][0] = u, Ask[i][1] = v;
	}
	sort(Ord + 1, Ord + m + 1, cmp);
	for (int i = 1, t = 1; i <= m; i = t)
	{
		for (; t <= m && E[Ord[t]][2] == E[Ord[i]][2]; t ++) ;
		if (Cnt[E[Ord[i]][2]] <= M)
		{
			tot = 0;
			for (int j = i; j < t; j ++)
				Head[E[Ord[j]][0]] = Head[E[Ord[j]][1]] = 0;
			for (int j = i; j < t; j ++)
				addedge(E[Ord[j]][0], E[Ord[j]][1]);
			for (int j = i; j < t; j ++)
				if (Id[E[Ord[j]][0]] != E[Ord[i]][2])
				{
					q[0] = 0;
					dfs(E[Ord[j]][0], E[Ord[i]][2]);
					for (int u = 1; u <= q[0]; u ++)
						for (int v = 1; v <= q[0]; v ++)
							if (Flag.find(mp(q[u], q[v])) != Flag.end())
								Map[mp(q[u], q[v])] ++;
				}
		}
		else
		{
			cnt ++;
			for(int j = 1; j <= n; j ++)
				Fa[cnt][j] = j;
			for (int j = i; j < t; j ++)
			{
				int u = Find(cnt, E[Ord[j]][0]);
				int v = Find(cnt, E[Ord[j]][1]);
				if (u != v) Fa[cnt][u] = v;
			}
		}
	}
	for (int i = 1; i <= p; i ++)
	{
		int u = Ask[i][0], v = Ask[i][1];
		int res = Map[mp(u, v)];
		for (int j = 1; j <= cnt; j ++)
			if (Find(j, u) == Find(j, v))
				res ++;
		printf("%d\n", res);
	}
	return 0;
}