#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 55;
using ld = long double;

vector<int> a[N];

ld prob[N];
ld invfact[N];
ld fact[N];
ld C[N][N];
ld deg2[N];

ld crit_prob[N][N][N];
ld tmp_buf[N][N];
int sz[N];

void dfs(int v, int p) {
	memset(crit_prob[v], 0, sizeof(crit_prob[v]));
	
	crit_prob[v][0][0] = 1;
	sz[v] = 0;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v);
		for (int i = 0; i <= sz[v] + sz[x]; ++i) {
			for (int j = 0; j <= i; ++j) {
				tmp_buf[i][j] = 0;
			}
		}
		for (int i = sz[v]; i >= 0; --i) {
			for (int j = sz[x]; j >= 0; --j) {
				for (int k = 0; k <= i; ++k) {
					for (int l = 0; l <= j; ++l) {
						tmp_buf[i + j][k + l] += crit_prob[v][i][k] * crit_prob[x][j][l] * C[sz[v]][i] / C[sz[v] + sz[x]][i + j] * C[sz[x]][j];
					}
				}
			}
		}
		for (int i = 0; i <= sz[v] + sz[x]; ++i) {
			for (int j = 0; j <= i; ++j) {
				crit_prob[v][i][j] = tmp_buf[i][j];
			}
		}
		sz[v] += sz[x];
	}
	++sz[v];
	for (int i = 0; i <= sz[v]; ++i) {
		for (int j = 0; j <= sz[v]; ++j) {
			tmp_buf[i][j] = 0;
		}
	}
	for (int i = 0; i <= sz[v]; ++i) {
		ld tmp = i * 1.0 / sz[v];
		for (int j = 0; j <= i; ++j) {
			tmp_buf[i][j] += (1 - tmp) * crit_prob[v][i][j];
		}
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k <= i; ++k) {
				tmp_buf[i][k + 1] += crit_prob[v][j][k] * tmp / i;
			}
		}
	}
	// cerr << v << ":\n";
	for (int i = 0; i <= sz[v]; ++i) {
		for (int j = 0; j <= sz[v]; ++j) {
			crit_prob[v][i][j] = tmp_buf[i][j];
			// cerr << crit_prob[v][i][j] << " ";
		}
		// cerr << "\n";
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 0; i < N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}

	invfact[0] = 1;
	deg2[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = fact[i - 1] * i;
		invfact[i] = invfact[i - 1] / i;
		deg2[i] = deg2[i - 1] / 2;
	}

	cout << setprecision(10) << fixed;
	for (int i = 0; i < n; ++i) {
		prob[i] = 1;
		for (int x : a[i]) {
			dfs(x, i);
			ld tmp = 0;
			for (int j = 0; j < n; ++j) {
				tmp += crit_prob[x][sz[x]][j] * deg2[j];
			}
			prob[i] *= tmp;
		}
		cout << prob[i] << "\n";
	}

	return 0;
}