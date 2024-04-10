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

  vector<vector<pair<int, int>>> adj(n + 1);
  for(int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].emplace_back(b, c);
    adj[b].emplace_back(a, c);
  }

  vector<vector<int>> busy(n + 1);
  for(int i=1; i<=n; i++) {
    int k;
    cin >> k;
    busy[i].resize(k);
    for(int j=0; j<k; j++) {
      cin >> busy[i][j];
    }
  }

  struct Node {
    int u, t;
    bool operator < (const Node& o) const {
      return t > o.t;
    }
  };
  priority_queue<Node> dijk;
  vector<int> dist(n + 1, -1);
  dijk.push({1, 0});
  while(!empty(dijk)) {
    auto [u, t] = dijk.top();
    dijk.pop();
    if(dist[u] != -1) continue;
    dist[u] = t;
    auto it = find(begin(busy[u]), end(busy[u]), t);
    while(it != end(busy[u]) && *it == t) {
      t++;
      it++;
    }
    for(auto [v, c] : adj[u]) {
      if(dist[v] != -1) continue;
      dijk.push({v, t + c});
    }
  }

  cout << dist[n] << nl;

  return 0;
}