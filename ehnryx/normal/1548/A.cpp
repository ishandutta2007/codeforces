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

  int n, m;
  cin >> n >> m;
  vector<set<int>> adj(n+1);
  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
  }

  int ans = 0;
  for(int i=1; i<=n; i++) {
    if(empty(adj[i]) || *rbegin(adj[i]) < i) {
      ans++;
    }
  }

  int q;
  cin >> q;
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int a, b;
      cin >> a >> b;
      ans -= (empty(adj[a]) || *rbegin(adj[a]) < a);
      ans -= (empty(adj[b]) || *rbegin(adj[b]) < b);
      adj[a].insert(b);
      adj[b].insert(a);
      ans += (empty(adj[a]) || *rbegin(adj[a]) < a);
      ans += (empty(adj[b]) || *rbegin(adj[b]) < b);
    } else if(t == 2) {
      int a, b;
      cin >> a >> b;
      ans -= (empty(adj[a]) || *rbegin(adj[a]) < a);
      ans -= (empty(adj[b]) || *rbegin(adj[b]) < b);
      adj[a].erase(b);
      adj[b].erase(a);
      ans += (empty(adj[a]) || *rbegin(adj[a]) < a);
      ans += (empty(adj[b]) || *rbegin(adj[b]) < b);
    } else {
      cout << ans << nl;
    }
  }

  return 0;
}