#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <int, int> Pii;
typedef pair <Pii, int> PPi;
#define N 5000 + 5
#define mp make_pair
#define price first
#define amount second

int n, m, w, Q, Dis[N][N], q[N];
PPi A[N];
vector <int> Vec[N];

inline void BFS(int st)
{
	for (int i = 1; i <= n; i ++)
		Dis[st][i] = n;
	int l = 1, r = 0;
	Dis[st][st] = 0, q[++ r] = st;
	while (l <= r)
	{
		int z = q[l ++];
		for (int i = 0; i < Vec[z].size(); i ++)
		{
			int d = Vec[z][i];
			if (Dis[st][d] != n) continue ;
			Dis[st][d] = Dis[st][z] + 1;
			q[++ r] = d;
		}
	}
}

inline bool Check(int pos, int req, LL b, int lim)
{
	for (int i = 1; req && i <= w; i ++)
	{
		if (Dis[pos][A[i].second] > lim) continue ;
		int t = min(req, A[i].first.amount);
		b -= 1LL * t * A[i].first.price;
		req -= t;
		if (b < 0) return 0;
	}
	return !req;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++)
		BFS(i);
	scanf("%d", &w);
	for (int i = 1, id, k, p; i <= w; i ++)
	{
		scanf("%d%d%d", &id, &k, &p);
		A[i] = mp(mp(p, k), id);
	}
	sort(A + 1, A + w + 1);
	for (scanf("%d", &Q); Q; Q --)
	{
		int pos, req, b;
		scanf("%d%d%d", &pos, &req, &b);
		int l = 0, r = n;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (Check(pos, req, b, mid)) r = mid;
			else l = mid + 1;
		}
		if (l == n)
			puts("-1");
		else printf("%d\n", l);
	}
	return 0;
}