
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

const int mod = 998244353;

using Shit = array<long long, 4>;

int mat[3][3];

const int N = 64;
using Matrix = array<array<long long, N>, N>;

Matrix mult(const Matrix& a, const Matrix& b) {
	Matrix res;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			res[i][j] = 0;
			for (int k = 0; k < N; ++k) {
				res[i][j] += a[i][k] * b[k][j] % mod;
			}
			res[i][j] %= mod;
		}
	}
	return res;
}

const int L = 30;
Matrix degs[30];

array<long long, N> mult(const array<long long, N>& a, const Matrix& b) {
	array<long long, N> res = {};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			res[j] += a[i] * b[i][j] % mod;
		}
	}
	for (int i = 0; i < N; ++i) {
		res[i] %= mod;
	}
	return res;
}

int mex(vector<int> a) {
	make_unique(a);
	for (int i = 0;; ++i) {
		if (i >= (int)a.size() || a[i] != i) {
			return i;
		}
	}
}

Shit f(int n, const vector<pair<int, int>>& ptd) {
	array<long long, N> cur = {};
	cur[N - 1] = 1;
	int last = 0;
	for (const auto& [pos, c] : ptd) {
		for (int i = 0; i < L; ++i) {
			if ((pos - last - 1) & (1 << i)) {
				cur = mult(cur, degs[i]);
			}
		}

		array<long long, N> nw = {};
		for (int gr = 0; gr < N; ++gr) {
			int x[3] = {gr&3, (gr>>2)&3, (gr>>4)&3};
			vector<int> mx;
			for (int j = 0; j < 3; ++j) {
				if (mat[c - 1][j]) {
					mx.push_back(x[j]);
				}
			}
			nw[(x[1]<<4)|(x[0]<<2)|mex(mx)] += cur[gr];
		}
		for (int i = 0; i < N; ++i) {
			nw[i] %= mod;
		}
		cur = nw;
		last = pos;
	}

	for (int i = 0; i < L; ++i) {
		if ((n - last) & (1 << i)) {
			cur = mult(cur, degs[i]);
		}
	}

	Shit res = {};
	for (int i = 0; i < N; ++i) {
		res[i&3] += cur[i];
	}
	for (auto& x : res) {
		x %= mod;
	}
	return res;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<vector<pair<int, int>>> painted(n);

	int m = nxt();
	for (int i = 0; i < m; ++i) {
		int idx = nxt() - 1, pos = nxt(), c = nxt();
		painted[idx].push_back({pos, c});
	}
	for (int i = 0; i < n; ++i) {
		sort(all(painted[i]));
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			mat[i][j] = nxt();
		}
	}

	Matrix mm;
	for (int i = 0; i < N; ++i) {
		mm[i].fill(0);
	}
	for (int gr = 0; gr < N; ++gr) {
		int x[3] = {gr&3, (gr>>2)&3, (gr>>4)&3};
		for (int i = 0; i < 3; ++i) {
			vector<int> mx;
			for (int j = 0; j < 3; ++j) {
				if (mat[i][j]) {
					mx.push_back(x[j]);
				}
			}
			mm[gr][(x[1]<<4)|(x[0]<<2)|mex(mx)] += 1;
		}
	}
	degs[0] = mm;
	for (int i = 1; i < L; ++i) {
		degs[i] = mult(degs[i - 1], degs[i - 1]);
	}

	Shit res = {1, 0, 0, 0};
	for (int i = 0; i < n; ++i) {
		auto tmp = f(a[i], painted[i]);
		Shit nr = {};
		for (int x = 0; x < 4; ++x) {
			for (int y = 0; y < 4; ++y) {
				nr[x ^ y] += res[x] * tmp[y] % mod;
			}
		}
		for (auto& x : nr) {
			x %= mod;
		}
		res = nr;
	}

	cout << res[0] << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}