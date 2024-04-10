#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,avx2,abm,fma,popcnt,tune=native")
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

const int N = 22;
int dp[2][1<<N];

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

  int n, x, y;
  cin >> n >> x >> y;
  if(x > y) swap(x, y);
  int m = x + y;

  int cnt = n / m;
  int rem = n % m;

  memset(dp[0], ~0x3f, sizeof dp[0]);
  dp[0][0] = 0;
  for(int i=0; i<m; i++) {
    memset(dp[1], ~0x3f, sizeof dp[1]);
    for(int bm=0; bm<1<<y; bm++) {
      if(dp[0][bm] < 0) continue;
      dp[1][bm>>1] = max(dp[1][bm>>1], dp[0][bm]);
      if(!(bm & 1<<(y-x)) && !(bm & 1)) {
        int om = bm >> 1 | 1 << (y-1);
        dp[1][om] = max(dp[1][om], dp[0][bm] + cnt + (i < rem));
      }
    }
    swap(dp[0], dp[1]);
  }

  int ans = *max_element(dp[0], dp[0] + (1<<N));
  cout << ans << nl;

  return 0;
}