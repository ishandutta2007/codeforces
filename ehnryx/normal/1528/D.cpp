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

struct Item {
  int u; ll d;
  bool operator < (const Item& o) const {
    return d > o.d;
  }
};

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
  vector<vector<pair<int,int>>> adj(n);
  for(int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].emplace_back(b, c);
  }

  for(int s=0; s<n; s++) {
    vector<ll> dist(n, INFLL);
    vector<bool> vis(n);
    dist[s] = 0;

    for(;;) {
      int u = -1;
      for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        if(u == -1 || dist[i] < dist[u]) {
          u = i;
        }
      }
      if(u == -1) break;

      //cerr << "AT " << u << " time " << dist[u] << endl;
      vis[u] = true;
      vector<ll> edge(n, INFLL);
      for(auto [v, c] : adj[u]) {
        int to = (v + dist[u]) % n;
        edge[to] = min(edge[to], (ll)c - to);
      }

      for(int i=0, take=INF; i<n; i++) {
        take = min((ll)take, edge[i]);
        if(!vis[i]) {
          dist[i] = min(dist[i], take + dist[u] + i);
        }
      }
      for(int i=n-1, take=INF; i>=0; i--) {
        take = min((ll)take, edge[i]);
        if(!vis[i]) {
          dist[i] = min(dist[i], take + dist[u] + i + n);
        }
      }
    }

    for(int i=0; i<n; i++) {
      cout << dist[i] << " ";
    }
    cout << nl;
  }

  return 0;
}