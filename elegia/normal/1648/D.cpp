/*
 , .
 */
#include <cmath>
#include <cstring>

#include <algorithm>
#include <limits>
#include <random>
#include <chrono>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using ull = unsigned long long;
using ll = long long;

using namespace std;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

const int P = 998244353;

int norm(int x) { return x >= P ? x - P : x; }
int reduce(int x) { return x < 0 ? x + P : x; }
int neg(int x) { return x ? P - x : 0; }
void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
int mpow(int x, unsigned k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}

const int _ = 500005;

int a[3][_];
ll x[_], y[_];

namespace SGT1 {

struct Info {
	ll mx, x, y;
	Info(ll mx = 0, ll x = 0, ll y = 0) : mx(mx), x(x), y(y) {}
	Info operator*(const Info& rhs) const {
		return Info(max({mx, rhs.mx, x + rhs.y}), max(x, rhs.x), max(y, rhs.y));
	}
} T[_ << 2];

void build(int o, int l, int r) {
	if (l == r) {
		T[o] = Info(x[l] + y[l], x[l], y[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(o << 1, l, mid); build(o << 1 | 1, mid + 1, r);
	T[o] = T[o << 1] * T[o << 1 | 1];
}
void upd(int o, int l, int r, int k) {
	if (l == r) {
		T[o] = Info(x[l] + y[l], x[l], y[l]);
		return;
	}
	int mid = (l + r) >> 1;
	if (k <= mid) upd(o << 1, l, mid, k);
	else upd(o << 1 | 1, mid + 1, r, k);
	T[o] = T[o << 1] * T[o << 1 | 1];
}
Info query(int o, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) return T[o];
	int mid = (l + r) >> 1;
	if (qr <= mid) return query(o << 1, l, mid, ql, qr);
	if (ql > mid) return query(o << 1 | 1, mid + 1, r, ql, qr);
	return query(o << 1, l, mid, ql, mid) * query(o << 1 | 1, mid + 1, r, mid + 1, qr);
}

}

vector<pair<int, int>> rg[_];

// ll fw[_];
// void ch(int k, ll x) {
// 	for (; k < _; k += k & -k) fw[k] = max(fw[k], x);
// }
// ll qry(int k, ll x) [
	
// ]

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, Q; cin >> N >> Q;
	for (int i = 0; i != 3; ++i)
		for (int j = 1; j <= N; ++j) cin >> a[i][j];
	for (int i = 1; i <= N; ++i) {
		x[i] = x[i - 1] + a[0][i] - a[1][i - 1];
		y[i] = y[i - 1] + a[1][i];
	}
	{
		ll tmp = 0;
		for (int i = N; i; --i) {
			tmp += a[2][i];
			y[i] += tmp;
		}
	}
	SGT1::build(1, 1, N);
	ll ans = numeric_limits<ll>::min();
	while (Q--) {
		int l, r, k; cin >> l >> r >> k;
		rg[l].emplace_back(r, k);
		// ans = max(ans, SGT1::query(1, 1, N, l, r).mx - k);
	}
	// for (int i = 1; i <= N; ++i) cerr << x[i] << ' ' << y[i] << '\n';
	for (int l = N; l; --l) {
		for (auto [r, k] : rg[l]) {
			auto val = SGT1::query(1, 1, N, l, r);
			ans = max(ans, val.mx - k);
			// cerr << l << ' ' << r << " " << k << ": " << val.mx - k << ", " << val.y << '\n';
			y[l - 1] = max(y[l - 1], val.y - k);
		}
		if (l > 1) SGT1::upd(1, 1, N, l - 1);
	}

	cout << ans << '\n';

	return 0;
}