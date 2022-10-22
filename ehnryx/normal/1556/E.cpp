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

const int N = 1 << 17;
ll big[2*N], small[2*N];

pair<ll, ll> query(int l, int r) {
  ll top = -INFLL;
  ll bot = INFLL;
  for(l+=N, r+=N+1; l<r; l/=2, r/=2) {
    if(l&1) {
      top = max(top, big[l]);
      bot = min(bot, small[l++]);
    }
    if(r&1) {
      top = max(top, big[--r]);
      bot = min(bot, small[r]);
    }
  }
  return pair(top, bot);
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
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  vector<ll> v(n+1);
  for(int i=0; i<n; i++) {
    cin >> b[i];
    v[i+1] = b[i] - a[i];
  }
  partial_sum(begin(v), end(v), begin(v));

  for(int i=0; i<=n; i++) {
    big[i+N] = small[i+N] = v[i];
  }
  for(int i=N-1; i>0; i--) {
    big[i] = max(big[2*i], big[2*i+1]);
    small[i] = min(small[2*i], small[2*i+1]);
  }

  for(int i=0; i<m; i++) {
    int l, r;
    cin >> l >> r;
    auto [top, bot] = query(l, r);
    assert(bot <= top);
    ll base = v[l-1];
    if(bot < base || top < base || base != v[r]) {
      cout << -1 << nl;
    } else {
      cout << top - base << nl;
    }
  }

  return 0;
}