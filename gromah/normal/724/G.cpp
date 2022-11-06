#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define M 400000 + 5
#define Mod 1000000007
#define Inv2 500000004
#define LOGN 62

int n, m, tot, ans, sz, Head[N], Pow[M];
bool all_zero = 1, Flag[N];
LL Val[N], A[M];
vector <int> Vec[N];

struct Edge
{
	int next, node;
	LL w;
}h[M];

inline int Inc(int a, int b)
{
	return a + b - (a + b >= Mod ? Mod : 0);
}

inline void addedge(int u, int v, LL w)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].w = w;
}

inline void dfs(int st, int z)
{
	Flag[z] = 1;
	Vec[st].push_back(z);
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		LL w = h[i].w;
		if (!Flag[d])
		{
			Val[d] = Val[z] ^ w;
			dfs(st, d);
		}
		else A[++ sz] = Val[z] ^ Val[d] ^ w;
	}
}

inline int Gauss()
{
	int k = 0;
	for (int i = LOGN - 1, j; ~i; i --)
	{
		for (j = k + 1; j <= sz && !((A[j] >> i) & 1); j ++) ;
		if (j > sz) continue ;
		swap(A[j], A[++ k]);
		for (j = k + 1; j <= sz; j ++)
			if ((A[j] >> i) & 1)
				A[j] ^= A[k];
	}
	return k;
}

int main()
{
	scanf("%d%d", &n, &m);
	Pow[0] = 1;
	for (int i = 1, u, v; i <= m; i ++)
	{
		LL x;
		scanf("%d%d%I64d", &u, &v, &x);
		addedge(u, v, x), addedge(v, u, x);
		Pow[i] = Inc(Pow[i - 1], Pow[i - 1]);
		all_zero &= (x == 0);
	}
	if (all_zero)
	{
		puts("1");
		return 0;
	}
	for (int i = 1; i <= n; i ++)
		if (!Flag[i])
		{
			sz = 0;
			dfs(i, i);
			int tmp = Gauss();
			sz = Vec[i].size();
			for (int j = 0; j < LOGN; j ++)
			{
				bool exist = 0;
				for (int k = 1; !exist && k <= tmp; k ++)
					exist = (A[k] >> j) & 1;
				if (exist)
					ans = Inc(ans, 1LL * Pow[tmp - 1] * sz % Mod * (sz - 1) % Mod * Inv2 % Mod * Pow[j] % Mod);
				else
				{
					int cnt = 0;
					for (int k = 0; k < sz; k ++)
					{
						int d = Vec[i][k];
						cnt += ((Val[d] >> j) & 1);
					}
					ans = Inc(ans, 1LL * Pow[tmp] * cnt % Mod * (sz - cnt) % Mod * Pow[j] % Mod);
				}
			}
		}
	printf("%d\n", ans);
	return 0;
}