#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 222222;
vector<int> a[N];
vector<int> ar[N];

constexpr int mod = 998'244'353;
constexpr int L = 50;

int d_small[N][L];

struct Zlp {
	int flips;
	int len;
};

bool operator <(const Zlp& a, const Zlp& b) {
	if (a.flips < L && b.flips < L) {
		long long lhs = (1ll << a.flips) + a.len;
		long long rhs = (1ll << b.flips) + b.len;
		return lhs < rhs;
	} else {
		return tie(a.flips, a.len) < tie(b.flips, b.len);
	}
}

pair<int, int> d_large[N][2];

void solve() {
	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		ar[v].push_back(u);
	}

	memset(d_small, -1, sizeof(d_small));
	d_small[0][0] = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});

	auto handle_small = [&](int v, int l, int d) {
		if (d_small[v][l] < 0) {
			d_small[v][l] = d;
			q.push({v, l});
		}
	};

	while (!q.empty()) {
		auto [u, l] = q.front();
		int d = d_small[u][l];
		q.pop();
		if (l + 1 < L) {
			handle_small(u, l + 1, d + 1);
		}
		if (l % 2 == 0) {
			for (int v : a[u]) {
				handle_small(v, l, d + 1);
			}
		} else {
			for (int v : ar[u]) {
				handle_small(v, l, d + 1);
			}
		}
	}

	Zlp ans{2281488, 0};
	for (int l = 0; l < L; ++l) {
		if (d_small[n - 1][l] > -1) {
			ans = min<Zlp>(ans, {l, d_small[n - 1][l] - l});
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			d_large[i][j] = {-1, -1};
		}
	}
	d_large[0][0] = {0, 0};
	set<tuple<int, int, int, int>> S;
	S.insert({0, 0, 0, 0});

	auto handle_large = [&](int v, int p, int flips, int len) {
		pair by{flips, len};
		if (d_large[v][p].first == -1 || by < d_large[v][p]) {
			if (d_large[v][p].first > -1) {
				S.erase({d_large[v][p].first, d_large[v][p].second, v, p});
			}
			d_large[v][p] = by;
			S.insert({d_large[v][p].first, d_large[v][p].second, v, p});
		}
	};

	while (!S.empty()) {
		auto [flips, len, u, p] = *S.begin();
		S.erase(S.begin());
		handle_large(u, p ^ 1, flips + 1, len);
		if (!p) {
			for (int v : a[u]) {
				handle_large(v, p, flips, len + 1);
			}
		} else {
			for (int v : ar[u]) {
				handle_large(v, p, flips, len + 1);
			}
		}
	}
	for (int i : {0, 1}) {
		if (d_large[n - 1][i].first > -1) {
			ans = min(ans, Zlp{d_large[n - 1][i].first, d_large[n - 1][i].second});
		}
	}

	long long res = 1;
	for (int i = 0; i < ans.flips; ++i) {
		res = res * 2 % mod;
	}
	res += ans.len;
	res -= 1;
	res += mod;
	cout << res % mod << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}