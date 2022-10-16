#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define X first
#define Y second
#define endl '\n'
#define make_unique(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

typedef long long ll;
typedef long double ld;
typedef double D;

template<class T = int> inline T read() {
	T x;
	cin >> x;
	return x;
}

int gcd(int x, int y) {
	while (y) {
		x %= y;
		swap(x, y);
	}
	return x;
}

const int MAXN = 666666;
int a[MAXN];
int tree[MAXN * 4];

void build(int v, int vl, int vr) {
	if (vl == vr) {
		tree[v] = a[vl];
		return;
	}
	int vm = (vl + vr) / 2;
	build(2 * v + 1, vl, vm);
	build(2 * v + 2, vm + 1, vr);
	tree[v] = gcd(tree[2 * v + 1], tree[2 * v + 2]);
}

int query(int v, int vl, int vr, int l, int r) {
	if (vl > vr || l > vr || vl > r) return 0;
	if (l <= vl && vr <= r) return tree[v];
	int vm = (vl + vr) / 2;
	return gcd(query(2 * v + 1, vl, vm, l, r), query(2 * v + 2, vm + 1, vr, l, r));
}

void update(int v, int vl, int vr, int pos, int x) {
	if (vl == vr) {
		tree[v] = x;
		return;
	}
	int vm = (vl + vr) / 2;
	if (pos <= vm) {
		update(2 * v + 1, vl, vm, pos, x);
	} else update(2 * v + 2, vm + 1, vr, pos, x);
	tree[v] = gcd(tree[2 * v + 1], tree[2 * v + 2]);
}

int countDiv(int v, int vl, int vr, int l, int r, int x, int byFar) {
	if (vl > vr || l > vr || vl > r) return byFar;
	if (l <= vl && vr <= r) {
		if (tree[v] % x == 0) return byFar;
		if (vl == vr) return byFar + 1;
	}
	int vm = (vl + vr) / 2;
	byFar = countDiv(2 * v + 1, vl, vm, l, r, x, byFar);
	if (byFar > 1) return byFar;
	return countDiv(2 * v + 2, vm + 1, vr, l, r, x, byFar);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	int n = read();
	for (int i = 0; i < n; ++i) a[i] = read();
	build(0, 0, n - 1);
	int q = read();
	for (int i = 0; i < q; ++i) {
		int type = read();
		if (type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			--l; --r;
			int res = countDiv(0, 0, n - 1, l, r, x, 0);
			cout << (res > 1 ? "NO" : "YES") << endl;
		} else {
			int pos, x;
			cin >> pos >> x;
			--pos;
			update(0, 0, n - 1, pos, x);
		}
	}
	return 0;
}