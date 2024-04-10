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

bool valid(int m, int a, int b) {
  for(int i=0; i<m-1; i++) {
    if((__builtin_popcount(a & 0b11 << i) + __builtin_popcount(b & 0b11 << i)) % 2 == 0) {
      return false;
    }
  }
  return true;
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

  int n, m;
  cin >> n >> m;
  if(n >= 4 && m >= 4) {
    cout << -1 << nl;
    return 0;
  }
  if(min(n, m) == 1) {
    cout << 0 << nl;
    return 0;
  }

  vector<int> g(max(n, m) + 1);
  if(n < m) {
    swap(n, m);
    for(int j=0; j<m; j++) {
      for(int i=1; i<=n; i++) {
        char v;
        cin >> v;
        g[i] |= (v - '0') << j;
      }
    }
  } else {
    for(int i=1; i<=n; i++) {
      for(int j=0; j<m; j++) {
        char v;
        cin >> v;
        g[i] |= (v - '0') << j;
      }
    }
  }

  vector<vector<int>> dp(n+1, vector<int>(1<<m));
  for(int bm=0; bm<1<<m; bm++) {
    dp[1][bm] = __builtin_popcount(bm ^ g[1]);
  }
  for(int i=2; i<=n; i++) {
    for(int bm=0; bm<1<<m; bm++) {
      dp[i][bm] = INF;
      for(int sm=0; sm<1<<m; sm++) {
        if(!valid(m, sm, bm)) continue;
        dp[i][bm] = min(dp[i][bm], dp[i-1][sm] + __builtin_popcount(bm ^ g[i]));
      }
    }
  }
  cout << *min_element(dp[n].begin(), dp[n].end()) << nl;

  return 0;
}