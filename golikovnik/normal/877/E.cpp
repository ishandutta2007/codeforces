#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const ll MOD998 = 998244353;

mt19937 rnd((uint) chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 20;
vector<int> graph[N];
int timer;
int tin[N], tout[N], by_time[N];
int tree[4 * N], a[N], rev[4 * N];

void build(int v, int l, int r) {
	if (l == r) {
		tree[v] = a[by_time[l]];
		return;
	}
	int m = (l + r) / 2;
	build(2 * v, l, m);
	build(2 * v + 1, m + 1, r);
	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

void push(int v, int l, int r) {
	if (rev[v]) {
		tree[v] = r - l + 1 - tree[v];
		if (l != r) {
			rev[2 * v] ^= 1;
			rev[2 * v + 1] ^= 1;
		}
		rev[v] = 0;
	}
}

void update(int v, int l, int r, int ql, int qr) {
	push(v, l, r);
	if (l > qr || ql > r) return;
	if (ql <= l && r <= qr) {
		rev[v] ^= 1;
		push(v, l, r);
		return;
	}
	int m = (l + r) / 2;
	update(2 * v, l, m, ql, qr);
	update(2 * v + 1, m + 1, r, ql, qr);
	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int query(int v, int l, int r, int ql, int qr) {
	push(v, l, r);
	if (l > qr || ql > r) return 0;
	if (ql <= l && r <= qr) {
		return tree[v];
	}
	int m = (l + r) / 2;
	return query(2 * v, l, m, ql, qr) + query(2 * v + 1, m + 1, r, ql, qr);
}

void dfs(int v = 0) {
	tin[v] = timer;
	by_time[timer++] = v;
	for (int u : graph[v]) {
		dfs(u);
	}
	tout[v] = timer - 1;
}

void run() {
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		graph[p - 1].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	dfs();
	build(1, 0, n - 1);
	int q;
	cin >> q;
	while (q--) {
		string s;
		int v;
		cin >> s >> v;
		--v;
		if (s[0] == 'p') {
			update(1, 0, n - 1, tin[v], tout[v]);
		} else {
			cout << query(1, 0, n - 1, tin[v], tout[v]) << "\n";
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests;
	tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	return 0;
}