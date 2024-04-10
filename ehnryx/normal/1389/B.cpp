//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define FILENAME sadcactussociety

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



// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
/*
#ifdef ONLINE_JUDGE
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif
*/

  int T;
  cin >> T;
  while(T--) {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n+1);
    for(int i=0; i<n; i++) {
      cin >> a[i];
    }

    int ans = 0;
    for(int left=0; left<=z && k-2*left>=0; left++) {
      int cur = 0;
      int maxp = 0;
      for(int i=0; i<=k-2*left; i++) {
        cur += a[i];
        maxp = max(maxp, a[i] + a[i+1]);
      }
      ans = max(ans, cur + maxp * left);
    }
    cout << ans << nl;
  }

  return 0;
}