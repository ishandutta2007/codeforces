#include  <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long long

const int N = 1e6 + 7;
const int Inf = 3e9;

int t[4 * N];
int mod[4 * N];

void update(int v, int val) {
	t[v] += val;
	mod[v] += val;
}

void push(int v) {
 	if (mod[v]) {
 		update(2 * v + 1, mod[v]);
 		update(2 * v + 2, mod[v]);
 		mod[v] = 0;
 	}	
}

void modify(int ql, int qr, int val, int l, int r, int v) {
	if (qr < l || r < ql) return;
	if (ql <= l && r <= qr) {
		update(v, val);
	} else {
		push(v);
		int m = (l + r) >> 1;
		modify(ql, qr, val, l, m, 2 * v + 1);
		modify(ql, qr, val, m + 1, r, 2 * v + 2);
		t[v] = max(t[2 * v + 1], t[2 * v + 2]);
	}
}

void build(int l, int r, int v, vector <int> &a) {
 	if (l == r) {
 	 	t[v] = a[l];
 	} else {
 		int m = (l + r) >> 1;
 		build(l, m, 2 * v + 1, a);
 		build(m + 1, r, 2 * v + 2, a);
 		t[v] = max(t[2 * v + 1], t[2 * v + 2]);
 	}
}

void solve() {
	int n, m, p;
	cin >> n >> m >> p;
	vector <int> a(n), ca(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> ca[i];
	}
	vector <int> best(N, -Inf);
	vector <int> b(m), cb(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i] >> cb[i];
		best[b[i]] = max(best[b[i]], -cb[i]);
	}
	build(0, N - 1, 0, best);
	vector <int> x(p), y(p), z(p);
	for (int i = 0; i < p; ++i) {
		cin >> x[i] >> y[i] >> z[i];
	}
	vector <int> ida(n);
	iota(ida.begin(), ida.end(), 0);
	sort(ida.begin(), ida.end(), [&] (int i, int j) {
		return a[i] < a[j];
	});
	vector <int> idx(p);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&] (int i, int j) {
		return x[i] < x[j];
	});
	int uk = 0;
	int ans = -Inf;
	for (int i : ida) {
	 	while (uk < p && x[idx[uk]] < a[i]) {
	 	 	int id = idx[uk];
	 	 	modify(y[id] + 1, N - 1, z[id], 0, N - 1, 0);
	 	 	++uk;
	 	}
	 	ans = max(ans, -ca[i] + t[0]);
	}
	cout << ans << '\n';
}
                  
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}	
}