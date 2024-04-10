#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 100500;

int n, m, a, b, c, cv, nv, tmr, l, ans1, ans2;
bool used[MAXN];
int tin[MAXN], tout[MAXN], h[MAXN], par[MAXN][21];
vi g[MAXN], hk[MAXN];

void dfs(int v, int from, int k) {
	used[v] = 1;
	h[v] = k;
	hk[k].push_back(tmr);
	tin[v] = tmr++;
	par[v][0] = from;
	FORN(i, 1, l)
		par[v][i] = par[par[v][i - 1]][i - 1];

	int to;
	forn(i, g[v].size()) {
		to = g[v][i];
		if (from != to)
			dfs(to, v, k + 1);
	}
	tout[v] = tmr++;
}

int parent(int a, int k) {
	if (h[a] < k) return -1;
	for (int i = l; i >= 0; i--)
		if (k >= (1 << i)) {
			a = par[a][i];
			k -= (1 << i);
		}
	return a;
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	scanf("%d", &n);
	l = 0;
	while ((1 << l) <= n) l++;
	FORN(i, 1, n) {
		scanf("%d", &a);
		if (a != 0)
			g[a].push_back(i);
	}
	FORN(i, 1, n)
		if (!used[i])
			dfs(i, 0, 0);
	forn(i, n)
		hk[i].push_back(INF);

	scanf("%d", &m);
	forn(i, m) {
		scanf("%d%d", &a, &b);
		c = parent(a, b);
		if (c == -1)
			printf("0 ");
		else {
			nv = h[a];
			ans1 = lower_bound(hk[nv].begin(), hk[nv].end(), tin[c]) - hk[nv].begin();
			ans2 = lower_bound(hk[nv].begin(), hk[nv].end(), tout[c]) - hk[nv].begin();
			ans2--;
			printf("%d ", ans2 - ans1);
		}
	}

	return 0;
}