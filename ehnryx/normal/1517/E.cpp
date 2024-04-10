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
random_device _rd; mt19937 rng(_rd());

ll solve(const vector<ll>& a, ll offset) {
  int n = size(a);
  vector<ll> even(n + 1), odd(n + 1), pref(n + 1);
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      even[i + 1] = even[i] + a[i];
      odd[i + 1] = odd[i];
    } else {
      even[i + 1] = even[i];
      odd[i + 1] = odd[i] + a[i];
    }
  }
  partial_sum(begin(a), end(a), begin(pref) + 1);

  ll ans = 0;
  for (int i = 1; i < n; i++) {
    ll left = -pref[i];
    function<ll(int)> calc = [&](int d) {
      ll right = pref[n] - pref[i + 2 * d];
      ll middle = (even[i + 2 * d] - even[i]) - (odd[i + 2 * d] - odd[i]);
      if (i % 2 == 0) middle = -middle;
      return left + right + middle + offset;
    };
    if (calc(0) <= 0) continue;
    int l = 0;
    int r = (n - i - 1) / 2;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (calc(m) > 0) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    ans += r + 1;
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<ll> pref(n + 1);
    partial_sum(begin(a), end(a), begin(pref) + 1);
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
      if (pref[i] > pref[n] - pref[i]) {
        ans += 1;
      }
    }
    if (n > 1) {
      ans += solve(a, 0);
    }
    if (n > 2) {
      ans += solve(vector(next(begin(a)), end(a)), a.front());
      ans += solve(vector(begin(a), prev(end(a))), -a.back());
    }
    if (n > 3) {
      ans += solve(vector(next(begin(a)), prev(end(a))), a.front() - a.back());
    }
    ans %= MOD;
    cout << ans << nl;
  }

  return 0;
}