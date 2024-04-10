#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int L = 18;
const int N = 1 << L;
int a[N];

struct Dsu {
	int n;
	vector<int> p, rk;

	Dsu() {}
	Dsu(int _n): n(_n), p(_n), rk(_n) {
		iota(all(p), 0);
	}

	int get(int v) {
		return v == p[v] ? v : p[v] = get(p[v]);
	}

	bool merge(int u, int v) {
		u = get(u);
		v = get(v);
		if (u == v) {
			return false;
		}
		if (rk[u] < rk[v]) {
			swap(u, v);
		}
		p[v] = u;
		if (rk[u] == rk[v]) {
			p[v] = u;
		}
		return true;
	}
};

Dsu dsu;

bool cmp(int i, int j) {
	if (i == -1) {
		return false;
	}
	if (j == -1) {
		return true;
	}
	if (a[i] != a[j]) {
		return a[i] > a[j];
	} else {
		return i > j;
	}
}

using State = array<int, 2>;
State def = {-1, -1};

void upd(State& x, int i) {
	if (i == -1) {
		return;
	}
	for (int& j : x) {
		if (j == -1) {
			break;
		} else if (dsu.get(j) == dsu.get(i)) {
			if (cmp(i, j)) {
				j = i;
			}
			return;
		}
	}
	for (int j = 0; j < (int)x.size(); ++j) {
		if (cmp(i, x[j])) {
			for (int k = (int)x.size() - 1; k > j; --k) {
				x[k] = x[k - 1];
			}
			x[j] = i;
			return;
		}
	}
}

void upd(State& x, const State& y) {
	for (auto z : y) {
		upd(x, z);
	}
}

State dp[N];
tuple<int, int, int> best[N];

int main() {
	int n = nxt();
	generate(a, a + n, nxt);
	n += 1;
	dsu = Dsu(n);
	long long ans = -accumulate(a, a + n, 0ll);
	while (true) {
		fill(dp, dp + N, def);
		for (int i = 0; i < n; ++i) {
			upd(dp[a[i]], i);
		}
		for (int mask = 0; mask < N; ++mask) {
			for (int i = 0; i < L; ++i) {
				if (mask & (1 << i)) {
					upd(dp[mask], dp[mask ^ (1 << i)]);
				}
			}
		}

		fill_n(best, n, tuple{-1, -1, -1});

		for (int i = 0; i < n; ++i) {
			for (int j : dp[(N - 1) ^ a[i]]) {
				if (j == -1) {
					break;
				} else if (int di = dsu.get(i), dj = dsu.get(j); di != dj) {
					best[di] = max(best[di], {a[i] + a[j], i, j});
				}
			}
		}

		bool ok = false;
		for (int i = 0; i < n; ++i) {
			if (get<0>(best[i]) > -1 && dsu.merge(get<1>(best[i]), get<2>(best[i]))) {
				ans += get<0>(best[i]);
				ok = true;
			}
		}

		if (!ok) {
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}