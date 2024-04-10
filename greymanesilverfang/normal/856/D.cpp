#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 2e5 + 5, MAX_M = 2e5 + 5, MAX_HEIGHT = 20;
int h[MAX_N] = {0, 1}, p[MAX_N][MAX_HEIGHT], s[MAX_N], prv[MAX_N], g[MAX_N], f[MAX_N];
struct info {int u, v, c, pos;} e[MAX_M];
bool operator < (info a, info b) {return (a.pos < b.pos);}

int lca(int a, int b) {
	if (h[a] < h[b]) 
		swap(a, b);
	for (int i = MAX_HEIGHT; --i + 1;)
		if (h[p[a][i]] >= h[b])
			a = p[a][i];
	if (a == b) 
		return a;
	for (int i = MAX_HEIGHT; --i + 1;)
		if (p[a][i] ^ p[b][i])
			a = p[a][i], b = p[b][i];
	return p[a][0];
}

int sum(int a, int b) {
	if (a == b) 
		return 0;
	if (prv[a] ^ b)
		s[a] += sum(prv[a], b), prv[a] = b;
	return s[a];
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i++ - n;) {
		scanf("%d", &prv[i]);
		h[i] = h[p[i][0] = prv[i]] + 1;
		for (int j = 0; p[i][j + 1] = p[p[i][j]][j]; ++j);
	}
	for (int i = 0; i++ - m;) {
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		e[i] = (info) {u, v, c, lca(u, v)};
	}
	sort(e + 1, e + m + 1);
	for (int i = n + 1, j = m; --i; f[prv[i]] += g[i]) {
		for (g[i] = f[i]; j && e[j].pos == i; --j)
			g[i] = max(g[i], f[i] + e[j].c + sum(e[j].u, i) + sum(e[j].v, i));
		s[i] = f[i] -= g[i];
	}
	printf("%d", f[0]);
	return 0;
}