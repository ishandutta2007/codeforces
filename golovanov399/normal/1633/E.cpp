#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

struct Dsu {
	int n;
	vector<int> p, rk;

	Dsu(int _n): n(_n), p(_n), rk(_n) {
		std::iota(p.begin(), p.end(), 0);
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
			++rk[u];
		}
		return true;
	}
};

struct Edge {
	int u, v;
	int w;
};

void solve() {
	int n = nxt(), m = nxt();
	vector<Edge> edges(m);
	for (auto& e : edges) {
		e.u = nxt() - 1;
		e.v = nxt() - 1;
		e.w = nxt();
	}

	vector<int> need_to_check = {0, (int)1e8 + 10};
	for (auto e1 : edges) {
		for (auto e2 : edges) {
			need_to_check.push_back((e1.w + e2.w) / 2);
		}
	}
	make_unique(need_to_check);
	const int sz = need_to_check.size();
	vector<long long> res(sz);
	vector<int> cnt_up(sz);
	for (int i = 0; i < sz; ++i) {
		int x = need_to_check[i];
		sort(all(edges), [&](const Edge& a, const Edge& b) {
			return make_pair(abs(x - a.w), a.w) < make_pair(abs(x - b.w), b.w);
		});
		Dsu dsu(n);
		for (const auto& e : edges) {
			if (dsu.merge(e.u, e.v)) {
				res[i] += abs(x - e.w);
				cnt_up[i] += (e.w >= x);
			}
		}
	}

	{
		int p = nxt(), k = nxt(), a = nxt(), b = nxt(), c = nxt();
		vector<int> qrs(k);
		for (int i = 0; i < p; ++i) {
			qrs[i] = nxt();
		}
		for (int i = p; i < k; ++i) {
			qrs[i] = (1ll * qrs[i - 1] * a + b) % c;
		}
		long long ans = 0;
		for (int x : qrs) {
			int i = lower_bound(all(need_to_check), x) - need_to_check.begin();
			ans ^= (res[i] + 1ll * (need_to_check[i] - x) * (cnt_up[i] * 2 - (n - 1)));
			// cerr << x << ", " << need_to_check[i] << ", " << res[i] + 1ll * (need_to_check[i] - x) * (cnt_up[i] * 2 - (n - 1)) << "\n";
		}
		cout << ans << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}