#include <bits/stdc++.h>

#include <functional>


#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using std::vector, std::queue;

template <typename int_type = int>
class Dinic {
public:
	struct Edge {
		int from, to;
		int_type cap, flow;
	};

	int n;
	vector<Edge> edges;
	vector<vector<int>> eids;

	Dinic(int _n): n(_n), eids(_n) {}

	void add_edge(int u, int v, int_type c, bool bidirectional = false) {
		eids[u].push_back(edges.size());
		edges.push_back({u, v, c, 0});
		eids[v].push_back(edges.size());
		edges.push_back({v, u, bidirectional ? c : 0, 0});
	}

	int_type k_flow(int s, int t, int_type flow_limit) {
		int_type ans = 0;
		while (bfs(s, t)) {
			ptr.assign(n, 0);
			while (int_type new_flow = push_flow(s, t, flow_limit)) {
				ans += new_flow;
				flow_limit -= new_flow;
			}
			if (!flow_limit) {
				break;
			}
		}
		return ans;
	}

	int_type max_flow(int s, int t) {
		return k_flow(s, t, inf);
	}

private:
	vector<int_type> d;
	vector<int> ptr;
	static inline constexpr int_type inf = std::numeric_limits<int_type>::max();

	int_type push_flow(int s, int t, int_type flow_limit) {
		if (!flow_limit) {
			return 0;
		}
		if (s == t) {
			return flow_limit;
		}
		int_type res = 0;
		for (int& i = ptr[s]; i < (int)eids[s].size(); ++i) {
			int eid = eids[s][i];
			if (d[edges[eid].to] != d[s] + 1 || edges[eid].flow == edges[eid].cap) {
				continue;
			}
			int_type added_flow = push_flow(edges[eid].to, t, std::min(edges[eid].cap - edges[eid].flow, flow_limit));
			if (!added_flow) {
				continue;
			}
			edges[eid].flow += added_flow;
			edges[eid ^ 1].flow -= added_flow;
			flow_limit -= added_flow;
			res += added_flow;
			if (!flow_limit) {
				break;
			}
		}
		return res;
	}

	bool bfs(int s, int t) {
		d.assign(n, inf);
		d[s] = 0;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int eid : eids[v]) {
				if (edges[eid].flow == edges[eid].cap) {
					continue;
				}
				int to = edges[eid].to;
				if (d[to] > d[v] + 1) {
					d[to] = d[v] + 1;
					q.push(to);
				}
			}
		}
		return d[t] != inf;
	}
};
#include <random>

using std::mt19937, std::mt19937_64;
using std::shuffle;

mt19937 rr;
mt19937_64 rr64;

inline std::uint_fast32_t custom_rand() {
	return rr();
}

inline std::uint_fast64_t custom_rand64() {
	return rr64();
}

template <typename RandomIt>
inline void custom_random_shuffle(RandomIt begin, RandomIt end) {
	shuffle(begin, end, rr);
}

#define rand custom_rand
#define rand64 custom_rand64
#define random_shuffle custom_random_shuffle
#include <memory>	// to define make_unique

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define imie(x) #x << ": " << x

vector<int> dinic_matching(const vector<vector<int>>& ed) {
	int m = 0;
	for (const auto& v : ed) {
		if (!v.empty()) {
			m = std::max(m, *max_element(all(v)) + 1);
		}
	}
	const int n = ed.size();
	Dinic<int> net(n + m + 2);
	for (int i = 0; i < n; ++i) {
		net.add_edge(0, i + 1, 1);
		for (int j : ed[i]) {
			net.add_edge(i + 1, j + n + 1, 1);
		}
	}
	for (int i = 0; i < m; ++i) {
		net.add_edge(i + n + 1, m + n + 1, 1);
	}
	net.max_flow(0, n + m + 1);
	vector<int> ans(n, -1);
	for (const auto& e : net.edges) {
		if (e.flow == 1 && e.from <= n && e.to > n) {
			ans[e.from - 1] = e.to - n - 1;
		}
	}
	return ans;
}

vector<int> kuhn_matching(const vector<vector<int>>& ed) {
	int m = 0;
	for (const auto& v : ed) {
		if (!v.empty()) {
			m = std::max(m, *max_element(all(v)) + 1);
		}
	}
	const int n = ed.size();

	vector<int> rt(m, -1);
	vector<int> lt(n, -1);
	vector<int> used(n);
	int timer = 0;

	vector<int> perm(n);
	iota(all(perm), 0);
	random_shuffle(all(perm));

	for (int i : perm) {
		for (int x : ed[i]) {
			if (rt[x] == -1) {
				rt[x] = i;
				lt[i] = x;
				break;
			}
		}
	}

	std::function<bool(int)> dfs = [&](int v) {
		if (used[v] == timer) {
			return false;
		}
		used[v] = timer;
		for (int x : ed[v]) {
			if (rt[x] == -1) {
				lt[v] = x;
				rt[x] = v;
				return true;
			}
		}
		for (int x : ed[v]) {
			if (dfs(rt[x])) {
				lt[v] = x;
				rt[x] = v;
				return true;
			}
		}
		return false;
	};

	for (int run = 1; run;) {
		run = 0;
		++timer;
		for (int i : perm) {
			if (lt[i] == -1 && dfs(i)) {
				run = 1;
			}
		}
	}

	return lt;
}

template <typename int_type>
vector<int> hungarian(const vector<vector<int_type>>& a) {
	const int n = a.size();
	constexpr int_type inf = std::numeric_limits<int_type>::max();

	vector<int_type> u(n + 1), v(n + 1);
	vector<int_type> est(n + 1, inf);
	vector<int> prv(n + 1, n);
	vector<char> used(n + 1);
	vector<int> rt(n + 1, n);

	for (int i = 0; i < n; ++i) {
		fill(all(est), inf);
		fill(all(used), 0);
		rt[n] = i;
		int r = n;
		do {
			used[r] = true;
			int l = rt[r];
			int nx = n;
			int_type delta = inf;
			for (int j = 0; j < n; ++j) {
				if (!used[j]) {
					int_type cur = a[l][j] - u[l] - v[j];
					if (cur < est[j]) {
						est[j] = cur;
						prv[j] = r;
					}
					if (est[j] < delta) {
						delta = est[j];
						nx = j;
					}
				}
			}
			for (int j = 0; j <= n; ++j) {
				if (used[j]) {
					u[rt[j]] += delta;
					v[j] -= delta;
				} else {
					est[j] -= delta;
				}
			}
			r = nx;
		} while (rt[r] != n);
		do {
			int pr = prv[r];
			rt[r] = rt[pr];
			r = pr;
		} while (r < n);
	}

	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[rt[i]] = i;
	}

	return ans;
}

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n1 = nxt(), n2 = nxt(), m = nxt();
	int q = nxt();
	map<pair<int, int>, int> M;
	vector<vector<int>> a(n1);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		M[{u, v}] = i + 1;
		a[u].push_back(v);
	}
	
	auto matching = dinic_matching(a);
	vector<char> left_used(n1), right_used(n2);
	for (int i = 0; i < n1; ++i) {
		if (matching[i] != -1) {
			left_used[i] = right_used[matching[i]] = 1;
		}
	}
	vector<int> eids;
	vector<pair<int, int>> matching_itself;
	vector<char> left_fed(n1)/*, right_fed(n2)*/;
	vector<vector<int>> l2r(n1), r2l(n2);
	vector<int> st;
	for (auto [p, idx] : M) {
		auto [u, v] = p;
		l2r[u].push_back(v);
		r2l[v].push_back(u);
		if (matching[u] == v) {
			eids.push_back(idx);
			matching_itself.push_back(p);
		} else {
			if (left_used[u] && !right_used[v]) {
				left_fed[u] = 1;
				st.push_back(u);
			}
			// if (right_used[v] && !left_used[u]) {
			// 	right_fed[v] = 1;
			// }
		}
	}
	vector<char> handled(n1);
	for (int x : st) {
		handled[x] = 1;
	}
	while (!st.empty()) {
		int u = st.back();
		st.pop_back();
		if (matching[u] == -1) {
			continue;
		}
		for (int x : r2l[matching[u]]) {
			if (handled[x]) {
				continue;
			}
			handled[x] = 1;
			left_fed[x] = 1;
			st.push_back(x);
		}
	}

	long long sum = accumulate(all(eids), 0ll);
	while (q--) {
		int t = nxt();
		if (t == 1) {
			cout << "1\n";
			auto [u, v] = matching_itself.back();
			matching_itself.pop_back();
			sum -= eids.back();
			eids.pop_back();
			if (left_fed[u]) {
				cout << u + 1 << "\n";
			} else {
				cout << -v - 1 << "\n";
			}
			cout << sum << endl;
		} else {
			cout << eids.size() << "\n";
			for (auto i : eids) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int t = 1; // nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}