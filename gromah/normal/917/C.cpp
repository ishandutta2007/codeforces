#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mp make_pair
#define INF 1234567890987654321LL

int x, k, n, q, id, w = 1, C[9], Num[256], State[256];

struct Stone
{
	int u, w;
	Stone (int _u = 0, int _w = 0)
	{
		u = _u, w = _w;
	}
	bool operator < (const Stone& a) const
	{
		return mp(u, w) < mp(a.u, a.w);
	}
}S[30];

struct Rec
{
	int r, c;
	LL num[70][70];
	Rec () {r = c = 0; memset(num, 0, sizeof(num));}
	Rec operator * (const Rec& a)
	{
		Rec res;
		res.r = r, res.c = a.c;
		for (int i = 0; i < r; i ++)
			for (int j = 0; j < a.c; j ++)
			{
				res.num[i][j] = INF;
				for (int u = 0; u < c; u ++)
					res.num[i][j] = min(res.num[i][j], num[i][u] + a.num[u][j]);
			}
		return res;
	}
}f, g, _g;

void dfs(int last, int dep, int cur)
{
	if (dep == x)
	{
		Num[cur] = id;
		State[id] = cur;
		id ++;
		return ;
	}
	for (int i = last + 1; i < k; i ++)
		dfs(i, dep + 1, cur | (1 << i));
}

int Find(int pos)
{
	int l = 1, r = q;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (pos == S[mid].u) return S[mid].w;
		else if (pos < S[mid].u) r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}

LL Calc(int u, int v, bool op = 0)
{
	u = State[u], v = State[v];
	u >>= 1, v ^= u;
	if (!v) return 0;
	for (int i = 0; i < k; i ++)
		if (v == (1 << i)) return C[i + 1] + (op ? Find(w + i + 1) : 0);
	return INF;
}

void Run(int v)
{
	if (v <= 0) return ;
	for (w += v, g = _g; v; v >>= 1)
	{
		if (v & 1) f = f * g;
		g = g * g;
	}
}

int main()
{
	scanf("%d%d%d%d", &x, &k, &n, &q);
	for (int i = 1; i <= k; i ++)
		scanf("%d", C + i);
	for (int i = 1, u, w; i <= q; i ++)
	{
		scanf("%d%d", &u, &w);
		S[i] = Stone(u, w);
	}
	sort(S + 1, S + q + 1);
	dfs(-1, 0, 0);
	f.r = 1, f.c = g.r = g.c = id;
	for (int i = 1; i < f.c; i ++)
		f.num[0][i] = INF;
	for (int i = 0; i < id; i ++)
		for (int j = 0; j < id; j ++)
			g.num[i][j] = Calc(i, j);
	_g = g;
	for (int i = 1; i <= q; i ++)
	{
		Run(S[i].u - k - w);
		for (; w <= n - x && w <= S[i].u; w ++)
		{
			for (int i = 0; i < id; i ++)
				for (int j = 0; j < id; j ++)
					g.num[i][j] = Calc(i, j, 1);
			f = f * g;
		}
	}
	Run(n - x + 1 - w);
	printf("%lld\n", f.num[0][0]);
	return 0;
}