#include <bits/stdc++.h>

using namespace std;
#define P 998244353

struct edge { int x, j, y; };
vector<edge> e[200001];
map<int, int> dis[200001], f[200001];
int t, n, ptr[200001], ans;
long long inv[200001];

long long power(long long x, int y) {
	long long ans = 1;
	while (y) {
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y /= 2;
	}
	return ans;
}

void dfs1(int x, int fa) {
	f[x].clear();
	ptr[x] = x;
	int hson = 0;
	for (edge i : e[x])
		if (i.j != fa) {
			dfs1(i.j, x);
			for (pair<int, int> j : dis[i.y])
				f[ptr[i.j]][j.first] = max(0, f[ptr[i.j]][j.first] - j.second);
			for (pair<int, int> j : dis[i.x])
				f[ptr[i.j]][j.first] += j.second;
			if (f[ptr[i.j]].size() > f[ptr[hson]].size()) hson = i.j;
		}
	if (!hson) return;
	ptr[x] = ptr[hson];
	for (edge i : e[x])
		if (i.j != fa && i.j != hson)
			for (pair<int, int> j : f[ptr[i.j]])
				f[ptr[x]][j.first] = max(f[ptr[x]][j.first], j.second);
}

void dfs2(int x, int fa, int cur) {
	ans = (ans + cur) % P;
	for (edge i : e[x])
		if (i.j != fa)
			dfs2(i.j, x, cur * inv[i.x] % P * i.y % P);
}

int main() {
	scanf("%d", &t);
	for (int i = 2; i <= 200000; ++i) {
		int t = i;
		for (int j = 2; j * j <= t; ++j)
			while (t % j == 0) {
				++dis[i][j];
				t /= j;
			}
		if (t > 1) ++dis[i][t];
	}
	inv[1] = 1;
	for (int i = 2; i <= 200000; ++i) inv[i] = (P - P / i) * inv[P % i] % P;
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) e[i].clear();
		for (int i = 1; i < n; ++i) {
			static int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			int g = __gcd(c, d);
			c /= g;
			d /= g;
			e[a].push_back({c, b, d});
			e[b].push_back({d, a, c});
		}
		dfs1(1, 0);
		long long prod = 1;
		for (pair<int, int> i : f[ptr[1]])
			prod = prod * power(i.first, i.second) % P;
		ans = 0;
		dfs2(1, 0, prod);
		printf("%d\n", ans);
	}
	return 0;
}