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
    int n, m;
    cin >> n >> m;
    vector<int> a(n*m);
    vector<pair<int, int>> order;
    for(int i=0; i<n*m; i++) {
      cin >> a[i];
      order.emplace_back(a[i], i); // go farther if earlier
    }
    sort(begin(order), end(order));

    ll ans = 0;
    vector g(n, vector<pair<int, int>>(m));
    for(int i=0; i<n; i++) {
      int start = 0;
      for(int j=0; j<m; j++) {
        g[i][j] = order[i*m + j];
        if(j > 0 && g[i][j].first != g[i][j-1].first) {
          reverse(begin(g[i]) + start, begin(g[i]) + j);
          start = j;
        }
      }
      reverse(begin(g[i]) + start, end(g[i]));
      ordered_set<int> have;
      for(auto [_, j] : g[i]) {
        have.insert(j);
        ans += have.order_of_key(j);
      }
    }

    cout << ans << nl;
  }

  return 0;
}