//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define FILENAME sadcactussociety

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Frac {
  ll n, d;
  Frac(ll a, ll b) {
    ll g = abs(__gcd(a, b)) * (b < 0 ? -1 : 1);
    n = a/g;
    d = b/g;
  }
  bool operator < (const Frac& o) const {
    return n*o.d < d*o.n;
  }
  bool operator != (const Frac& o) const {
    return n != o.n || d != o.d;
  }
  Frac operator * (const Frac& o) const {
    return Frac(n*o.n, d*o.d);
  }
  Frac operator + (const Frac& o) const {
    return Frac(n*o.d + d*o.n, d*o.d);
  }
};

ostream& operator << (ostream& os, const Frac& v) {
  return os << v.n << '/' << v.d;
}

Frac abs(const Frac& v) {
  return Frac(abs(v.n), v.d);
}

ld to_float(const Frac& v) {
  return (ld) v.n / v.d;
}

struct Line {
	mutable ld m, b, p;
	bool operator<(const Line& o) const { return m < o.m; }
	bool operator<(ld x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	const ld inf = (ld)1/(ld)0;
	ld div(ld a, ld b) { return a/b; }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->m == y->m) x->p = x->b > y->b ? inf : -inf;
		else x->p = div(y->b - x->b, x->m - y->m);
		return x->p >= y->p;
	}
	void add(ld m, ld b) {
		auto z = insert({m, b, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ld query(ld x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.m * x + l.b;
	}
};

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
/*
#ifdef ONLINE_JUDGE
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif
*/

  int n;
  cin >> n;
  vector<int> a(n), b(n), y(n);
  vector<pair<Frac,int>> v;
  LineContainer big, small;
  for(int i=0; i<n; i++) {
    cin >> a[i] >> b[i] >> y[i];
    big.add(-y[i], b[i]);
    small.add(y[i], -a[i]);
    for(int j=0; j<i; j++) {
      if(y[i] == y[j]) continue;
      Frac s(a[i] - b[j], y[i] - y[j]);
      Frac t(b[i] - a[j], y[i] - y[j]);
      v.emplace_back(min(s, t), 1);
      v.emplace_back(max(s, t), -1);
    }
  }
  v.emplace_back(Frac(1e7, 1), 0);
  v.emplace_back(Frac(-1e7, 1), 0);
  sort(v.begin(), v.end());

  int cnt = 0;
  ld ans = 1e19;
  for(auto [x, t] : v) {
    ld slope = to_float(x);
    if(cnt == 0) {
      ans = min(ans, big.query(slope) + small.query(slope));
    }
    cnt += t;
    if(cnt == 0) {
      ans = min(ans, big.query(slope) + small.query(slope));
    }
  }
  cout << ans << nl;

  return 0;
}