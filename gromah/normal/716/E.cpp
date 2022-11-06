#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <int, int> Pii;
#define N 100000 + 5
#define mp make_pair
#define node first
#define fix second

int n, m, Inv_10, Size[N], Pow[N], Inv[N], Hash[2][N], Max[N], Min[N], T[N];
LL ans;
bool Done[N];
vector <Pii> Vec[N];
map <int, int> Map;

inline int Phi(int x)
{
	int res = 1, _x = x;
	for (int i = 2; i * i <= x; i ++)
		if (_x % i == 0)
		{
			_x /= i, res *= i - 1;
			for (; _x % i == 0; _x /= i) res *= i;
		}
	if (_x > 1) res *= _x - 1;
	return res;
}

inline int Power(int u, int v)
{
	int res = 1;
	for (; v; v >>= 1)
	{
		if (v & 1) res = 1LL * res * u % m;
		u = 1LL * u * u % m;
	}
	return res;
}

inline void dfs(int rt, int z, int fa, int dep, int op)
{
	if (!~op) Size[z] = 1, Max[z] = 0;
	else if (!Min[rt] || max(Size[rt] - Size[z], Max[z]) < max(Size[rt] - Size[Min[rt]], Max[Min[rt]]))
		Min[rt] = z;
	if (Map.find(Hash[1][z]) != Map.end()) ans += Map[Hash[1][z]];
	if (~op && !Hash[0][z]) ans ++;
	T[++ T[0]] = 1LL * (m - Hash[0][z]) * Inv[dep] % m;
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i].node, w = Vec[z][i].fix;
		if (Done[d] || d == fa) continue ;
		Hash[0][d] = (1LL * Hash[0][z] * 10 + w) % m;
		Hash[1][d] = (1LL * Pow[dep] * w + Hash[1][z]) % m;
		dfs(rt, d, z, dep + 1, op);
		if (!~op) Size[z] += Size[d], Max[z] = max(Max[z], Size[d]);
	}
}

inline void Solve(int z, int sz)
{
	Hash[0][z] = Hash[1][z] = 0, Done[z] = 1;
	if (sz == 1) return ;
	for (int op = -1; op <= 1; op += 2)
	{
		Map.clear();
		if (!~op) Map[0] ++;
		int st = ~op ? 0 : Vec[z].size() - 1;
		int ed = ~op ? Vec[z].size() : -1;
		for (int i = st; i != ed; i += op)
		{
			int d = Vec[z][i].node, w = Vec[z][i].fix;
			if (Done[d]) continue ;
			Hash[0][d] = Hash[1][d] = w;
			T[0] = Min[d] = 0;
			dfs(d, d, z, 1, op);
			for (int j = 1; j <= T[0]; j ++)
				Map[T[j]] ++;
		}
	}
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i].node;
		if (Done[d]) continue ;
		Solve(Min[d], Size[d]);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	Pow[0] = Inv[0] = 1, Inv[1] = Power(10, Phi(m) - 1);
	for (int i = 1; i <= n; i ++)
		Pow[i] = 1LL * Pow[i - 1] * 10 % m;
	for (int i = 2; i <= n; i ++)
		Inv[i] = 1LL * Inv[i - 1] * Inv[1] % m;
	for (int i = 1, u, v, w; i < n; i ++)
	{
		scanf("%d%d%d", &u, &v, &w);
		u ++, v ++, w %= m;
		Vec[u].push_back(mp(v, w));
		Vec[v].push_back(mp(u, w));
	}
	if (m == 1)
		printf("%I64d\n", 1LL * n * (n - 1));
	else
	{
		Solve(1, n);
		printf("%I64d\n", ans);
	}
	return 0;
}