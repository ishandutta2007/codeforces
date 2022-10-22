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

void solve_case() {
  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for(int i=0; i<n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  v.push_back(2*INF);

  for(int i=0, _; i<n; i++) {
    cin >> _;
  }

  vector dp(n+1, vector<int>(3));
  int ans = 0;
  for(int i=n-1; i>=0; i--) {
    for(int t=0; t<=2; t++) {
      dp[i][t] = dp[i+1][t];
    }
    int j = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
    for(int t=0; t<2; t++) {
      dp[i][t] = max(dp[i][t], dp[j][t+1] + j-i);
    }
    ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
  }
  cout << ans << nl;
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

  int T;
  cin >> T;
  while(T--) {
    solve_case();
  }

  return 0;
}