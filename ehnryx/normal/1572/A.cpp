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
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1);
    for(int i=1; i<=n; i++) {
      int k;
      cin >> k;
      for(int j=0; j<k; j++) {
        int a;
        cin >> a;
        deg[i]++;
        adj[a].push_back(i);
      }
    }

    vector<int> dp(n+1);
    queue<int> bfs;
    for(int i=1; i<=n; i++) {
      if(deg[i] == 0) {
        dp[i] = 1;
        bfs.push(i);
      }
    }

    int done = 0;
    while(!empty(bfs)) {
      int u = bfs.front();
      bfs.pop();
      done++;
      for(int v : adj[u]) {
        if(v < u) {
          dp[v] = max(dp[v], dp[u] + 1);
        } else {
          dp[v] = max(dp[v], dp[u]); // oops
        }
        if(--deg[v] == 0) {
          bfs.push(v);
        }
      }
    }

    if(done < n) {
      cout << -1 << nl;
    } else {
      cout << *max_element(begin(dp), end(dp)) << nl;
    }
  }

  return 0;
}