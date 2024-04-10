//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 1;
vector<pair<int,int>> adj[N];

const int M = 10;
bool conflict[M][M][M][M];
vector<int> group[M];
bitset<N> to[M][M];
bool bad[M][M];

int cur[M];
int solve(int k, int base) {
  if(k == 0) {
    return 1;
  }

  int res = 0;
  for(int i=1; i<=k; i++) {
    if(bad[k][i]) continue;
    bool ok = true;
    for(int j=k+1; j<=base; j++) {
      ok &= !conflict[k][i][j][cur[j]];
    }
    if(ok) {
      cur[k] = i;
      res += solve(k-1, base);
    }
  }
  return res;
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int n, m, k;
  cin >> n >> m >> k;
  for(int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].emplace_back(c, b);
  }

  for(int i=1; i<=n; i++) {
    int deg = adj[i].size();
    group[deg].push_back(i);
    sort(adj[i].begin(), adj[i].end());
  }

  for(int i=1; i<=k; i++) {
    for(int ci=1; ci<=i; ci++) {
      for(int u : group[i]) {
        int v = adj[u][ci-1].second;
        if(to[i][ci][v]) {
          bad[i][ci] = true;
          break;
        }
        to[i][ci][v] = true;
      }
    }
  }

  for(int i=1; i<=k; i++) {
    for(int ci=1; ci<=i; ci++) {
      if(bad[i][ci]) continue;
      for(int j=1; j<i; j++) {
        for(int cj=1; cj<=j; cj++) {
          if(bad[j][cj]) continue;
          if((to[i][ci] & to[j][cj]).count() > 0) {
            conflict[i][ci][j][cj] = true;
            conflict[j][cj][i][ci] = true;
          }
        }
      }
    }
  }

  cout << solve(k, k) << nl;

  return 0;
}