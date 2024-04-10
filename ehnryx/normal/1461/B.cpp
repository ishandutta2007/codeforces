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
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



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
    vector grid(n, vector<char>(m));
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        cin >> grid[i][j];
      }
    }

    int ans = 0;
    vector dp(n, vector<int>(m));
    for(int i=n-1; i>=0; i--) {
      for(int j=0; j<m; j++) {
        if(grid[i][j] == '*') {
          dp[i][j] = 1;
          if(i+1 < n && j+1 < m && j > 0) {
            dp[i][j] = 1 + min(dp[i+1][j], min(dp[i+1][j-1], dp[i+1][j+1]));
          }
        }
        ans += dp[i][j];
      }
    }
    cout << ans << nl;
  }

  return 0;
}