#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const ll BIG = 2e18 + 7;
ll mul(ll a, ll b) {
  if(b == 0) return 0;
  if(a <= BIG/b + 1) return min(BIG, a*b);
  return BIG;
}

ll get_jumps(ll l, ll r, ll m, ll d) {
  if(d == 0) return BIG;
  ll lo = (l + d-1) / d;
  ll hi = r / d;
  if(lo <= hi) return lo;
  if(m % d == 0) return BIG;
  ll jumps = (m + d-1) / d;
  ll cnt = get_jumps(l, r, m, d - m % d);
  return mul(cnt, jumps);
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

  ll k, l, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;

  if(x == y) {
    if(k + y <= r || k - x >= l) {
      cout << "Yes" << nl;
    } else {
      cout << "No" << nl;
    }
    return 0;
  }

  else if(x > y) {
    if(k + y > r) {
      k -= x;
      t -= 1;
    }
    if(k < l) {
      cout << "No" << nl;
    } else {
      ll d = x - y;
      if((k - l) / d >= t) {
        cout << "Yes" << nl;
      } else {
        cout << "No" << nl;
      }
    }
    return 0;
  }

  else {
    ll lo = max(l, r - y + 1);
    ll hi = min(r, l + x - 1);
    if(lo > hi) {
      cout << "Yes" << nl;
      return 0;
    }
    if(lo <= k && k <= hi) {
      cout << "No" << nl;
      return 0;
    }

    // want lo <= k + ay - bx <= hi
    //      lo - k <= ay - bx <= hi - k
    ll mod_lo = lo % x - k % x;
    ll mod_hi = hi % x - k % x;
    if(mod_hi < mod_lo) mod_hi += x;
    while(mod_hi < 0) {
      mod_lo += x;
      mod_hi += x;
    }

    if(mod_lo <= 0 && 0 <= mod_hi) {
      // y's = 0
      if((k - lo) / x >= t) {
        cout << "Yes" << nl;
      } else {
        cout << "No" << nl;
      }
      return 0;
    }

    else {
      // remember to cap y_cnt at BIG
      ll y_cnt = get_jumps(mod_lo, mod_hi, x, y % x);
      if(y % x == 0) assert(y_cnt == BIG);
      if(y % x == 0) if(lo <= k && k <= hi) while(clock()<0.5*CLOCKS_PER_SEC);
      if(y % x == 0) assert(k < lo || k > hi);
      if((k + (__int128)y_cnt * y - lo) / x >= t) {
        cout << "Yes" << nl;
      } else {
        cout << "No" << nl;
      }
      return 0;
    }
  }

  return 0;
}