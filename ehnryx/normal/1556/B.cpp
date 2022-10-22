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

ll solve(vector<int> a, int val) {
  int n = size(a);
  int want = 0;
  ll res = 0;
  for(int i=0; i<n; i++) {
    if(a[i] == val) {
      res += abs(want - i);
      want += 2;
    }
  }
  return res;
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
  while(T--) {
    int n;
    cin >> n;
    int odd = 0;
    int even = 0;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
      cin >> a[i];
      a[i] %= 2;
      odd += a[i];
      even += !a[i];
    }
    if(abs(odd - even) > 1) {
      cout << -1 << nl;
      continue;
    }

    if(odd > even) {
      cout << solve(a, 1) << nl;
    } else if(odd < even) {
      cout << solve(a, 0) << nl;
    } else {
      cout << min(solve(a, 0), solve(a, 1)) << nl;
    }
  }

  return 0;
}