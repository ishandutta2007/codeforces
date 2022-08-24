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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int L = 17;
const int N = 1 << L;

long long a[N];
long long aa[N];
long long b[N];
long long bb[N];

void wh(long long* b, long long* e) {
	if (e == b + 1) {
		return;
	}
	long long *m = b + (e - b) / 2;
	wh(b, m);
	wh(m, e);
	while (m != e) {
		*b += *m;
		*m = *b - 2 * (*m);
		++b, ++m;
	}
}

vector<pair<int, int>> g[N];
vector<int> huili;
vector<char> used;
vector<pair<int, int>> order;

void dfs(int v, int p) {
	used[v] = 1;
	for (const auto& [to, id] : g[v]) {
		if (id == p) {
			continue;
		}
		if (used[to] == 1) {
			continue;
		} else if (used[to]) {
			huili.push_back(id);
		} else {
			dfs(to, id);
		}
	}
	if (p > -1) {
		order.push_back({v, p});
	}
	used[v] = 2;
}

int main() {
	int n = nxt(), m = nxt();
	vector<int> w(m);
	for (int i = 0; i < m; ++i) {
		itn u = nxt() - 1, v = nxt() - 1;
		w[i] = nxt();
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}

	used.assign(n, 0);

	dfs(0, -1);
	vector<long long> shit(m);
	for (int x : huili) {
		shit[x] = rand() % 1000000000;
		shit[x] <<= 31;
		shit[x] |= (long long)rand() % 1000000000;
	}
	for (const auto& [v, id] : order) {
		for (const auto& [to, idx] : g[v]) {
			assert(to > -1);
			if (id == idx) {
				continue;
			}
			shit[id] ^= shit[idx];
		}
	}

	vector<char> bridges(m);
	int off = 0;
	for (int i = 0; i < m; ++i) {
		bridges[i] = (shit[i] == 0);
		off ^= w[i];
	}

	used.assign(n, 0);
	a[off] = 1;
	aa[off] = 1;

	const int mod = 1000000007;
	int d2 = 1;
	for (int i = 0; i < L; ++i) {
		if (d2 % 2) {
			d2 += mod;
		}
		d2 /= 2;
	}
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		vector<int> st = {i};
		used[i] = 1;
		int cn = 0;
		while (!st.empty()) {
			++cn;
			int v = st.back();
			st.pop_back();
			for (const auto& [to, id] : g[v]) {
				if (bridges[id]) {
					continue;
				}
				b[w[id]] += 1;
				if (!used[to]) {
					used[to] = 1;
					st.push_back(to);
				}
			}
		}
		if (cn == 1) {
			continue;
		}
		for (int i = 0; i < N; ++i) {
			b[i] /= 2;
			bb[i] = b[i];
		}
		wh(a, a + N);
		wh(b, b + N);
		wh(aa, aa + N);
		wh(bb, bb + N);
		for (int i = 0; i < N; ++i) {
			a[i] %= mod;
			b[i] %= mod;
			if (a[i] < 0) {
				a[i] += mod;
			}
			if (b[i] < 0) {
				b[i] += mod;
			}
			a[i] *= b[i];
			a[i] %= mod;
			aa[i] *= bb[i];
		}
		wh(a, a + N);
		wh(aa, aa + N);
		for (int i = 0; i < N; ++i) {
			a[i] = a[i] % mod * d2 % mod;
			if (a[i] < 0) {
				a[i] += mod;
			}
			aa[i] = min(aa[i], 1ll);
		}
		memset(b, 0, sizeof(b));
	}

	int idx = 0;
	while (a[idx] == 0 && aa[idx] == 0) {
		++idx;
	}
	cout << idx << " " << a[idx] << "\n";

	return 0;
}