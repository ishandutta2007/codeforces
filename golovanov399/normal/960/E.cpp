#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

/* For any commutative function f({x, y, ..., z}) = f(x, f(y, f(..., z)))
 * like sum, min, max, or, xor, and, etc
 * calculates in dp[i][j] f(subtree),
 * where subtree is a connectivity component of G \ (i, a[i][j]) with vertex a[i][j]
 */

using pii = pair<int, int>;

const int N = 222222;
vector<int> a[N];
vector<pii> dp[N];
int par[N];

pair<int, int> levels_par[N];

inline pii f(pii x, pii y) {
	return {x.first + y.first, x.second + y.second};
}

pii dfsDown(int v) {
	pii res = {0, 1};
	for (int i = 0; i < (int)a[v].size(); ++i) {
		int to = a[v][i];
		if (to == par[v]) {
			continue;
		}
		par[to] = v;
		res = f(res, dp[v][i] = dfsDown(to));
	}
	swap(res.first, res.second);
	return res;
}

void dfsUp(int v, pii to_parent = {0, 0}) {
	vector<pii> pref, suf;
	pref.reserve(a[v].size());
	suf.reserve(a[v].size());
	int j = 0;
	for (int i = 0; i < (int)a[v].size(); ++i) {
		int to = a[v][i];
		if (to == par[v]) {
			dp[v][i] = to_parent;
			continue;
		}
		pref.push_back(j ? f(pref[j - 1], dp[v][i]) : dp[v][i]);
		++j;
	}
	j = 0;
	for (int i = (int)a[v].size() - 1; i >= 0; --i) {
		int to = a[v][i];
		if (to == par[v]) {
			continue;
		}
		suf.push_back(j ? f(dp[v][i], suf[j - 1]) : dp[v][i]);
		++j;
	}
	reverse(all(suf));

	j = 0;
	to_parent = f(to_parent, {0, 1});
	for (int i = 0; i < (int)a[v].size(); ++i) {
		int to = a[v][i];
		if (to == par[v]) {
			continue;
		}
		pii new_to_parent = to_parent;
		if (j > 0) {
			new_to_parent = f(pref[j - 1], new_to_parent);
		}
		if (j < (int)suf.size() - 1) {
			new_to_parent = f(new_to_parent, suf[j + 1]);
		}
		swap(new_to_parent.first, new_to_parent.second);
		dfsUp(to, new_to_parent);
		++j;
	}
}

int val[N];

const int mod = 1000000007;

map<int, int> getIndex[N];

int main() {
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		val[i] = nxt();
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		dp[i].resize(a[i].size());
	}
	dfsDown(0);
	dfsUp(0);

	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < (int)a[i].size(); ++j) {
	// 		cerr << i + 1 << " -> " << a[i][j] + 1 << ": " << dp[i][j].first << " even paths and " << dp[i][j].second << " odd paths\n";
	// 	}
	// }

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)a[i].size(); ++j) {
			getIndex[i][a[i][j]] = j;
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)a[i].size(); ++j) {
			pii forv_levels = dp[i][j];
			pii back_levels = dp[a[i][j]][getIndex[a[i][j]][i]];

			long long tmp = (back_levels.first - back_levels.second) * (forv_levels.first + forv_levels.second) % mod;
			tmp += (forv_levels.second - forv_levels.first);
			tmp = tmp * val[i] % mod;
			if (tmp < 0) {
				tmp += mod;
			}
			ans += tmp;
		}
		ans += mod + val[i];
	}

	cout << ans % mod << "\n";

	return 0;
}