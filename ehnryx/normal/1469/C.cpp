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
    int n, k;
    cin >> n >> k;
    bool ok = true;
    ll l, r;
    cin >> l;
    r = l;
    for(int i=1; i<n; i++) {
      int h;
      cin >> h;
      if(i == n-1) {
        l = max(l - (k-1), (ll)h);
        r = min(r + (k-1), (ll)h);
      } else {
        l = max(l - (k-1), (ll)h);
        r = min(r + (k-1), (ll)h + (k-1));
      }
      ok &= (l <= r);
    }
    if(ok) {
      cout << "YES" << nl;
    } else {
      cout << "NO" << nl;
    }
  }

  return 0;
}