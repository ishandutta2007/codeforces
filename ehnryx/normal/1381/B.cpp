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
    int n;
    cin >> n;
    vector<int> a(2*n);

    int big = 0;
    vector<int> blocks;
    for(int i=0; i<2*n; i++) {
      cin >> a[i];
      if(a[i] > big) {
        big = a[i];
        blocks.push_back(i);
      }
    }
    blocks.push_back(2*n);

    vector<int> sz;
    for(int i=1; i<blocks.size(); i++) {
      sz.push_back(blocks[i] - blocks[i-1]);
    }

    int m = sz.size();
    vector<bool> dp(n+1), ndp(n+1);
    dp[0] = true;
    for(int i=0; i<m; i++) {
      fill(ndp.begin(), ndp.end(), false);
      for(int j=0; j<=n; j++) {
        ndp[j] = dp[j] || (sz[i]<=j && dp[j-sz[i]]);
      }
      swap(dp, ndp);
    }
    if(dp[n]) {
      cout << "YES" << nl;
    } else {
      cout << "NO" << nl;
    }
  }

  return 0;
}