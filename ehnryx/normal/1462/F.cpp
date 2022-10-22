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
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    vector<int> right;
    for(int i=0; i<n; i++) {
      int l, r;
      cin >> l >> r;
      v.emplace_back(l, r);
      right.push_back(r);
    }
    sort(v.begin(), v.end());
    sort(right.begin(), right.end());

    int ans = INF;
    for(auto [l, r] : v) {
      int cur = lower_bound(right.begin(), right.end(), l) - right.begin();
      cur += v.end() - upper_bound(v.begin(), v .end(), make_pair(r, (int)INF));
      ans = min(ans, cur);
    }
    cout << ans << nl;
  }

  return 0;
}