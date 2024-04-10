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

const int N = 2000 + 2;
int res[N][N], dp[N][N];
char g[N][N];

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

  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      cin >> g[i][j];
    }
  }

  memset(res, INF, sizeof res);
  for(int di : {1, -1}) {
    for(int dj : {1, -1}) {
      for(int i = (di > 0 ? 1 : n); (di > 0 ? i <= n : i >= 1); i += di) {
        for(int j = (dj > 0 ? 1 : m); (dj > 0 ? j <= m : j >= 1); j += dj) {
          dp[i][j] = 1;
          if(g[i][j] == g[i-di][j] && g[i][j] == g[i][j-dj]) {
            dp[i][j] = 1 + min(dp[i-di][j], dp[i][j-dj]);
          }
          res[i][j] = min(res[i][j], dp[i][j]);
        }
      }
    }
  }

  ll ans = 0;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      ans += res[i][j];
    }
  }
  cout << ans << nl;

  return 0;
}