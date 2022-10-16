#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

struct rect {
	int lx, rx, ly, ry;
};

rect combine(rect a, rect b) {
	return {max(a.lx, b.lx), min(a.rx, b.rx), max(a.ly, b.ly), min(a.ry, b.ry)};
}

const int N = 133000;
rect tree[4 * N];
rect a[N];

const rect INF = {int(-1e9), int(1e9), int(-1e9), int(1e9)};

void build(int v, int l, int r) {
	if (l == r) {
		tree[v] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * v, l, mid);
	build(2 * v + 1, mid + 1, r);
	tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
}

rect query(int v, int l, int r, int ql, int qr) {
	if (r < ql || qr < l) return INF;
	if (ql <= l && r <= qr) return tree[v];
	int mid = (l + r) >> 1;
	return combine(query(2 * v, l, mid, ql, qr), query(2 * v + 1, mid + 1, r, ql, qr));
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		a[i] = {lx, rx, ly, ry};
	}
	build(1, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		rect fi = query(1, 0, n - 1, 0, i - 1);
		rect se = query(1, 0, n - 1, i + 1, n - 1);
		rect res = combine(fi, se);
		if (res.lx <= res.rx && res.ly <= res.ry) {
			cout << res.lx << " " << res.ly << "\n";
			return 0;
		}
	}
	return 0;
}