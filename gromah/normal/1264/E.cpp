#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define N 50 + 5
#define D 2500 + 5
#define M 100000 + 5
#define Cost int
#define Flow int
#define pb push_back

namespace MCMF
{
const int mxn = D, mxm = M, MXL = 593119681;
#define fore(i,e,x) for(int i,e=fe[x]; i=ev[e],e; e=ne[e])
int n,m,fe[mxn],ne[mxm],ev[mxm]; Flow f[mxm]; Cost c[mxm];
void clear(int nn)
{ n = nn; fill(fe, fe + n + 1, 0); m = 1; }
void add_(int x, int y, Flow F, Cost C)
{ ne[++m] = fe[x]; fe[x] = m; ev[m] = y; f[m]=F; c[m]=C; }
void add1(int x, int y, Flow F, Cost C)
{ add_(x, y, F, C); add_(y, x, 0, -C); }
// , f[]c[]
int S, T; Cost cost, dist, d[mxn]; bool v[mxn];
Flow extend(int x, Flow lim) { // T
	if (x == S) return cost += dist * lim, lim; // flow+=lim,
	Flow re = 0; v[x] = true;
	fore(i,e,x) if (f[e ^ 1] && !c[e] && !v[i]) {
		Flow t = extend(i, min(lim - re, f[e ^ 1]));
		f[e] += t, f[e ^ 1] -= t;
		if ((re += t) == lim) { v[x] = false; break; }
	}
	return re;
}
void dijk() { // O(N^2)dijkstra
	fill(d, d + n + 1, MXL); d[S] = 0;
	using P = pair<Cost,int>;
	priority_queue<P,vector<P>,greater<P>> h;
	for (h.push({0, S}); !h.empty(); ) {
		Cost t; int x; tie(t, x) = h.top(); h.pop();
		if (x == T) break; if (t > d[x]) continue;
		fore(i,e,x) if (f[e] && d[i] > d[x] + c[e])
			h.push({d[i] = d[x] + c[e], i});
	}
	for (int i = 1; i <= n; ++i) d[i] = min(d[i], d[T]);
}
void label() {
	for (int i = 2; i <= m; ++i)
		c[i] -= d[ev[i]] - d[ev[i ^ 1]];
	dist += d[T];
}
Cost mcmf(int SS, int TT) {
	S = SS, T = TT; cost = dist = 0;
	// spfa(), label(); // 
	while (dijk(), label(), d[T] < MXL) // : && dist < 0
		do fill(v, v + n + 1, false); while (extend(T, MXL));
	return cost;
}

}


int n, m, S, T, Deg[N], C[N], Id[N][N];
bool Map[N][N];
char s[N][N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		Map[u][v] = 1;
	}
	S = 0, T = n * (n - 1) / 2 + n + 1;
	MCMF::clear(T);
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < n; j ++)
			MCMF::add1(i, T, 1, j);
	for (int i = 1, o = n + 1; i < n; i ++)
		for (int j = i + 1; j <= n; j ++, o ++)
		{
			MCMF::add1(S, o, 1, 0);
			if (!Map[i][j] && !Map[j][i])
			{
				MCMF::add1(o, i, 1, 0);
				MCMF::add1(o, j, 1, 0);
			}
			else if (Map[i][j])
				MCMF::add1(o, i, 1, 0);
			else MCMF::add1(o, j, 1, 0);
		}
	MCMF::mcmf(S, T);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			s[i][j] = '0';
	for (int i = 1, o = n + 1; i < n; i ++)
		for (int j = i + 1; j <= n; j ++, o ++)
		{
			for(int u,e=MCMF::fe[o]; u=MCMF::ev[e],e; e=MCMF::ne[e])
			{
				if (1 <= u && u <= n && !MCMF::f[e])
				{
					s[u][i + j - u] = '1';
					break ;
				}
			}
		}
	for (int i = 1; i <= n; i ++)
		printf("%s\n", s[i] + 1);
	return 0;
}