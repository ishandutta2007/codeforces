#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long double LD;
#define N 400 + 5
#define INF 401

int n, m, Dis[N][N], A[N];
vector <int> Vec[N], T[N];
bool Flag[N];
LD Max, P[N], P_Max[N];

inline LD Get(int s1, int d1)
{
	for (int i = 1; i <= n; i ++)
		P[i] = 0.0, Flag[i] = 0;
	int sz = 0;
	for (int i = 0; i < T[d1].size(); i ++)
	{
		int z = T[d1][i];
		for (int j = 0; j < Vec[z].size(); j ++)
		{
			int d = Vec[z][j];
			P[d] += 1.0 / n / Vec[z].size();
			if (!Flag[d]) A[++ sz] = d, Flag[d] = 1;
		}
	}
	LD res = 0.0;
	for (int s2 = 1; s2 <= n; s2 ++)
	{
		for (int i = 1; i <= sz; i ++)
			P_Max[Dis[s2][A[i]]] = max(P_Max[Dis[s2][A[i]]], P[A[i]]);
		LD tmp = 0.0;
		for (int i = 1; i <= sz; i ++)
		{
			tmp += P_Max[Dis[s2][A[i]]];
			P_Max[Dis[s2][A[i]]] = 0;
		}
		res = max(res, tmp);
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			Dis[i][j] = i == j ? 0 : INF;
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
		Dis[u][v] = Dis[v][u] = 1;
	}
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				Dis[i][j] = min(Dis[i][j], Dis[i][k] + Dis[k][j]);
	for (int s1 = 1; s1 <= n; s1 ++)
	{
		for (int i = 0; T[i].size(); i ++)
			T[i].clear();
		for (int i = 1; i <= n; i ++)
			T[Dis[s1][i]].push_back(i);
		LD sum = 0.0;
		for (int d1 = 0; T[d1].size(); d1 ++)
		{
			LD today = 1.0 / n;
			LD tomorrow = Get(s1, d1);
			sum += max(today, tomorrow);
		}
		Max = max(Max, sum);
	}
	printf("%.7lf\n", (double) Max);
	return 0;
}