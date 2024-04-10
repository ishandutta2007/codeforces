#pragma GCC optimize("O3")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
using ordered_set = __gnu_pbds::tree<T,
      __gnu_pbds::null_type,
      less<T>,
      __gnu_pbds::rb_tree_tag,
      __gnu_pbds::tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

ld cp(const pt& a, const pt& b) { return imag(conj(a) * b); }
ld dp(const pt& a, const pt& b) { return real(conj(a) * b); }
pt line_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
  return a + cp(c - a, d - c) / cp(b - a, d - c) * (b - a);
}
bool parallel(const pt& a, const pt& b, const pt& c, const pt& d) {
  return abs(cp(a-b, c-d) / abs(a-b)) < EPS;
}
bool on_segment(const pt& c, const pt& a, const pt& b) {
  return abs(c-a) < EPS || abs(c-b) < EPS || (dp(c-a, b-a) > 0 && dp(c-b, a-b) > 0);
}

ld area(const vector<pt>& v) {
  int n = v.size();
  ld ans = 0;
  for(int i=n-1, j=0; j<n; i=j++) {
    ans += cp(v[i], v[j]);
  }
  return ans / 2;
}

ld solve(const vector<pt>& v, pt s, pt t) {
  int n = v.size();
  ld ans = 0;
  pt dir = (t - s) / abs(s - t);
  for(int i=n-1, j=0; j<n; i=j++) {
    if(parallel(v[i], v[j], s, t)) continue;
    pt it = line_inter(v[i], v[j], s, t);
    if (!on_segment(it, v[i], v[j])) continue;
    if (abs(it - v[i]) < EPS) {
      int k = (i + n-1) % n;
      if (parallel(v[k], v[i], s, t)) {
        if (cp(dir, v[j] - v[i]) > 0 && dp(dir, v[i] - v[k]) > 0) {
          ans += dp(it - s, dir); // out
        }
        if (cp(dir, v[j] - v[i]) < 0 && dp(dir, v[i] - v[k]) < 0) {
          ans -= dp(it - s, dir); // in
        }
      }
    } else if (abs(it - v[j]) < EPS) {
      int k = (j + 1) % n;
      if (parallel(v[k], v[j], s, t)) {
        if (cp(dir, v[j] - v[i]) > 0 && dp(dir, v[k] - v[j]) < 0) {
          ans += dp(it - s, dir); // out
        }
        if (cp(dir, v[j] - v[i]) < 0 && dp(dir, v[k] - v[j]) > 0) {
          ans -= dp(it - s, dir); // in
        }
      } else {
        if (cp(dir, v[j] - v[i]) > 0 && cp(dir, v[k] - v[j]) > 0) {
          ans += dp(it - s, dir); // out
        }
        if (cp(dir, v[j] - v[i]) < 0 && cp(dir, v[k] - v[j]) < 0) {
          ans -= dp(it - s, dir); // in
        }
      }
    } else { // easy
      if (cp(dir, v[j] - v[i]) > 0) {
        ans += dp(it - s, dir);
      } else {
        ans -= dp(it - s, dir);
      }
    }
  }

  return ans;
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int n, m;
  cin >> n >> m;

  vector<pt> v;
  for(int i=0; i<n; i++) {
    ld x, y;
    cin >> x >> y;
    v.emplace_back(x, y);
  }
  if (area(v) < 0) {
    reverse(begin(v), end(v));
  }

  for(int j=0; j<m; j++) {
    ld a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << solve(v, pt(a, b), pt(x, y)) << nl;
  }

  return 0;
}