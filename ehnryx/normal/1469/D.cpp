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
    vector<pair<int,int>> ans;
    int val = n;
    for(int i=n-1; i>2; i--) {
      if((ll)i*i <= val) {
        ans.emplace_back(n, i);
        val = (val + i - 1) / i;
      }
      ans.emplace_back(i, n);
    }
    while(val > 1) {
      ans.emplace_back(n, 2);
      val = (val + 1) / 2;
    }
    assert(ans.size() <= n + 5);
    cout << ans.size() << nl;
    for(auto [a, b] : ans) {
      cout << a << " " << b << nl;
    }
  }

  return 0;
}