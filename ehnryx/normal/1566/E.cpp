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

pair<int, int> solve(vector<vector<int>>& adj, int u, int p) {
  if(p) adj[u].erase(find(begin(adj[u]), end(adj[u]), p));
  int res = 0;
  int children = 0;
  for(int v : adj[u]) {
    auto [cur, leaf] = solve(adj, v, u);
    children += leaf;
    res += cur;
  }
  if(children) {
    return pair(res + children - 1, 0);
  } else {
    return pair(res, 1);
  }
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
    vector<vector<int>> adj(n+1);
    for(int i=1; i<n; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int ans = solve(adj, 1, 0).first;
    cout << ans + 1 << nl;
  }

  return 0;
}