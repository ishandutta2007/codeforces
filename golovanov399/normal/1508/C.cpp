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

struct Dsu {
	int n;
	vector<int> p, rk;

	Dsu(int _n): n(_n), p(_n), rk(_n) {
		iota(all(p), 0);
	}

	int get(int v) {
		return v == p[v] ? v : p[v] = get(p[v]);
	}

	bool merge(int u, int v) {
		u = get(u), v = get(v);
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

	bool operator <(const Edge& ot) const {
		return w < ot.w;
	}
};

template <typename T>
typename vector<T>::iterator insert_in_proper_place(vector<T>& vec, const T& x) {
	return vec.insert(lower_bound(all(vec), x), x);
}

void solve() {
	int n = nxt(), m = nxt();
	int tot = 0;
	vector<vector<pair<int, int>>> a(n);
	vector<Edge> edges;
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1, w = nxt();
		tot ^= w;
		a[u].push_back({v, w});
		a[v].push_back({u, w});
		edges.push_back({u, v, w});
	}
	sort(all(edges));
	for (int i = 0; i < n; ++i) {
		sort(all(a[i]));
	}

	auto calc = [&]() {
		int x = 1;
		while (2 * x <= n && x * (n - x) <= m) {
			++x;
		}
		// cerr << x << "\n";
		vector<char> used(n);
		vector<char> marked(n);
		Dsu dsu(n);
		for (int i = 0; i < n; ++i) {
			if (used[i]) {
				continue;
			}
			bool fail = false;
			vector<int> st = {i};
			used[i] = true;
			vector<int> comp;
			while (!st.empty()) {
				int v = st.back();
				st.pop_back();
				comp.push_back(v);
				if ((int)a[v].size() < n - x) {
					fail = true;
					break;
				}
				for (int j = 0, it = 0; j < n; ++j) {
					if (it < (int)a[v].size() && a[v][it].first == j) {
						++it;
						continue;
					} else {
						if (used[j] == 2) {
							fail = true;
							break;
						}
						if (used[j] == 1) {
							continue;
						}
						used[j] = 1;
						st.push_back(j);
					}
				}
				if (fail) {
					break;
				}
			}
			if (fail) {
				for (int v : comp) {
					used[v] = 2;
				}
				for (int v : st) {
					used[v] = 2;
				}
			} else {
				for (int j = 1; j < (int)comp.size(); ++j) {
					// cerr << "merged " << comp[j - 1] + 1 << " " << comp[j] + 1 << "\n";
					dsu.merge(comp[j - 1], comp[j]);
				}
				for (int v : comp) {
					marked[v] = 1;
				}
			}
		}
		vector<int> rem;
		for (int i = 0; i < n; ++i) {
			if (!marked[i]) {
				rem.push_back(i);
			}
		}
		for (int i = 1; i < (int)rem.size(); ++i) {
			// cerr << "merged " << rem[i - 1] + 1 << " " << rem[i] + 1 << "\n";
			dsu.merge(rem[i - 1], rem[i]);
		}
		long long ans = 0;
		for (auto [u, v, w] : edges) {
			if (dsu.merge(u, v)) {
				ans += w;
			}
		}
		return ans;
	};

	if (1ll * n * (n - 1) / 2 >= m + n) {
		cout << calc() << "\n";
		return;
	}

	long long ans = 1e18;
	int pos = lower_bound(all(edges), Edge{0, 0, tot}) - edges.begin();
	for (int i = 0; i < n; ++i) {
		int it = 0;
		for (int j = i + 1; j < n; ++j) {
			while (it < (int)a[i].size() && a[i][it].first < j) {
				++it;
			}
			if (it < (int)a[i].size() && a[i][it].first == j) {
				++it;
				continue;
			}
			edges.insert(edges.begin() + pos, {i, j, tot});
			auto ij = insert_in_proper_place(a[i], {j, tot});
			auto ji = insert_in_proper_place(a[j], {i, tot});
			ans = min(ans, calc());
			a[i].erase(ij);
			a[j].erase(ji);
			// cerr << i + 1 << " " << j + 1 << " " << tot << ": " << calc() << "\n";
			edges.erase(edges.begin() + pos);
		}
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}