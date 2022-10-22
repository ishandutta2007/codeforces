#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e5 + 10, M = 19, inf = 1e9;
int n, q, p[N], ls[N], rs[N], a[N];
int up[N], dw[N];
pair<int, int> st[M][N];
void solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) cin >> p[i], st[0][i] = {p[i], i};
	for(int i = 1; i < M; i ++) {
		for(int j = 1; j <= n - (1 << i) + 1; j ++) {
			st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
	vector<int> id;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(!a[i]) id.emplace_back(i);
	}
	auto qry = [&] (int l, int r) {
		int k = __lg(r - l + 1);
		return max(st[k][l], st[k][r - (1 << k) + 1]).second;
	};
	function<int(int, int)> build = [&](int l, int r) {
		if(l > r) return 0;
		int mid = qry(l, r);
		ls[mid] = build(l, mid - 1);
		rs[mid] = build(mid + 1, r);
		return mid;
	};
	int rt = build(1, n);
	function<void(int)> dfs = [&] (int u) {
		if(!u) return ;
		if(a[u]) up[u] = min(up[u], a[u]);
		up[ls[u]] = up[rs[u]] = up[u];
		dfs(ls[u]), dfs(rs[u]);
		dw[u] = max(dw[ls[u]], dw[rs[u]]);
		if(a[u]) dw[u] = max(dw[u], a[u]);
	};
	up[rt] = inf;
	dfs(rt);
	// for(int i = 1; i <= n; i ++) cout << up[i] << ' ' << dw[i] << '\n';
	vector<int> s(id.size() - 1);
	for(auto &u : s) cin >> u;
	sort(s.begin(), s.end());
	int l = -1, r = -1;
	for(int i = 0; i < n; i ++) if(dw[i] > up[i]) {
		l = inf, r = 0;
	}
	if(l == inf) {
		for(int i = 0; i < q; i ++) {
			int d;
			cin >> d;
			cout << "No\n";
		}
		return ;
	}
	set<int> st(s.begin(), s.end());
	sort(id.begin(), id.end(), [&] (int x, int y) {return up[x] < up[y];});
	for(int i : id) {
		auto it = st.lower_bound(dw[i]);
		if(it != st.end() && *it <= up[i]) st.erase(it);
		else {
			if(r == -1) r = up[i];
			else l = inf, r = 0;
		}
	}
	st = set<int>(s.begin(), s.end());
	sort(id.begin(), id.end(), [&] (int x, int y) {return dw[x] > dw[y];});
	for(int i : id) {
		auto it = st.upper_bound(up[i]);
		if(it != st.begin() && *--it >= dw[i]) st.erase(it);
		else {
			if(l == -1) l = dw[i];
			else l = inf, r = 0;
		}
	}
	// cout << l << ' ' << r << '\n';
	for(int i = 0; i < q; i ++) {
		int d;
		cin >> d;
		cout << (d >= l && d <= r ? "Yes\n" : "No\n");
	}
	
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		solve();
	}
	return 0;
}