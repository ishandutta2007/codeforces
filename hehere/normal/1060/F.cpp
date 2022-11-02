#include <bits/stdc++.h>
using namespace std;

const int maxN = 50 + 3;
int n;
double fac[maxN];
vector<int> G[maxN];

double f[maxN][maxN], g[maxN];
void link(int &cnt, double f[]) {
	copy(f, f + cnt + 1, g);
	fill(f, f + cnt + 2, 0.0);
	for(int i = 0; i <= cnt; ++i)
		for(int j = 0; j <= cnt; ++j) {
			if(j >= i) f[j + 1] += g[i] * 0.5, f[0] += g[i] * 0.5;
			else f[i + 1] += g[i];
		}
	++cnt;
	for(int i = 0; i <= cnt; ++i) f[i] /= cnt;
}
double C(int n, int k) {
	if(k < 0 || k > n) return 0;
	else return fac[n] / fac[n - k] / fac[k];
}
void merge(double f[], int n, double h[], int m) {
	copy(f, f + n + 1, g);
	fill(f, f + n + m + 1, 0.0);
	double sum = C(n + m, n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			for(int k = i + j; k <= n + m; ++k) {
				f[k] += g[i] * h[j] * C(k - 1, i - 1) * C(n + m - k, n - i) / sum;
				f[k] += g[i] * h[j] * C(k - 1, j - 1) * C(n + m - k, m - j) / sum;
			}
		}
	}
	for(int k = 1; k <= n + m; ++k) {
		for(int i = 1; i <= k && i <= n; ++i) f[k] += g[i] * h[0] * C(k - 1, i - 1) * C(n + m - k, n - i) / sum;
		for(int j = 1; j <= k && j <= m; ++j) f[k] += g[0] * h[j] * C(k - 1, j - 1) * C(n + m - k, m - j) / sum;
	}
	f[0] = g[0] * h[0];
}

int DP(int u, int fa) {
	int cnt = 0;
	f[u][0] = 1;
	for(int v : G[u]) if(v != fa) {
		int sz = DP(v, u);
		link(sz, f[v]);
//		printf("g[%d] = {", v);
//		for(int i = 0; i <= sz; ++i) printf("%s%.3lf", (i == 0 ? "" : ", "), f[v][i]);
//		printf("}\n");
		merge(f[u], cnt, f[v], sz);
		cnt += sz;
	}
//	printf("f[%d] = {", u);
//	for(int i = 0; i <= cnt; ++i) printf("%s%.3lf", (i == 0 ? "" : ", "), f[u][i]);
//	printf("}\n");
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	fac[0] = 1.0;
	for(int i = 1; i < maxN; ++i) fac[i] = fac[i - 1] * i;
	for(int i = 0; i < n - 1; ++i) {
		int x, y; cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	cout << fixed << setprecision(8);
	for(int u = 1; u <= n; ++u) {
		int sz = DP(u, -1);
		assert(sz == n - 1);
		cout << f[u][0] << endl;
	}
	return 0;
}