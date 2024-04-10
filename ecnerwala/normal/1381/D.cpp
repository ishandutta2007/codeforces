#include<bits/stdc++.h>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

bool go() {
	using namespace std;

	int N, A, B; cin >> N >> A >> B; A--, B--;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> par(N);
	vector<int> depth(N);
	par[A] = A;
	depth[A] = 0;
	std::y_combinator([&](auto self, int cur) -> void {
		for (int nxt : adj[cur]) {
			if (nxt == par[cur]) continue;
			depth[nxt] = depth[cur]+1;
			par[nxt] = cur;
			self(nxt);
		}
	})(A);

	int L = depth[B] - depth[A];
	assert(L >= 1);

	//cerr << A << ' ' << B << ' ' << C << ' ' << L << '\n';

	vector<int> dp_down(N);
	std::y_combinator([&](auto self, int cur) -> void {
		dp_down[cur] = 0;
		for (int nxt : adj[cur]) {
			if (nxt == par[cur]) continue;
			self(nxt);
			dp_down[cur] = max(dp_down[cur], dp_down[nxt]+1);
		}
	})(A);
	vector<int> dp_up(N);
	dp_up[A] = 0;
	std::y_combinator([&](auto self, int cur) -> void {
		int best = dp_up[cur], best2 = 0;
		for (int nxt : adj[cur]) {
			if (nxt == par[cur]) continue;
			int cnd = dp_down[nxt]+1;
			if (cnd > best) best2 = best, best = cnd;
			else if (cnd > best2) best2 = cnd;
		}
		for (int nxt : adj[cur]) {
			if (nxt == par[cur]) continue;
			int cnd = dp_down[nxt]+1;
			dp_up[nxt] = 1 + (best == cnd ? best2 : best);
			self(nxt);
		}
	})(A);

	bool has_good = false;
	for (int cur = 0; cur < N; cur++) {
		int cnt = 0;
		for (int nxt : adj[cur]) {
			int l = (nxt == par[cur]) ? dp_up[cur] : (dp_down[nxt]+1);
			if (l >= L) cnt++;
		}
		if (cnt >= 3) {
			has_good = true;
		}
	}
	//cerr << "has_good " << has_good << '\n';
	if (!has_good) return false;

	vector<int> caterpillar; caterpillar.reserve(L+1);
	for (int cur = B; cur != A; cur = par[cur]) {
		int v = 0;
		for (int nxt : adj[cur]) {
			if (nxt == par[cur]) continue;
			v = max(v, dp_down[nxt]+1);
		}
		caterpillar.push_back(v);
		dp_down[cur] = -1;
	}
	{
		int cur = A;
		int v = dp_up[cur];
		for (int nxt : adj[cur]) {
			if (nxt == par[cur]) continue;
			v = max(v, dp_down[nxt]+1);
		}
		caterpillar.push_back(v);
	}

	//for (int i : caterpillar) { cerr << i << ' '; } cerr << '\n';

	vector<int> pref = caterpillar;
	for (int i = 0; i < L; i++) pref[i+1] = max(pref[i+1], pref[i]+1);
	vector<int> suff = caterpillar;
	for (int i = L; i > 0; i--) suff[i-1] = max(suff[i-1], suff[i]+1);

	int lo = 0, hi = L;
	while (lo < hi) {
		if (lo < suff[hi] - (L - hi)) lo++;
		else if (L-hi < pref[lo] - lo) hi--;
		else break;
	}
	return lo == hi;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		bool ans = go();
		cout << (ans ? "YES" : "NO") << '\n';
	}

	return 0;
}