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
    vector<ll> a(n+1);
    ll sum = 0;
    for(int i=1; i<=n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if(sum % n) {
      cout << -1 << nl;
      continue;
    }

    vector<tuple<int,int,int>> ans;
    for(int i=2; i<=n; i++) {
      int x = (i - a[i] % i) % i;
      ans.emplace_back(1, i, x);
      a[i] += x;
      a[1] -= x;
      assert(a[i] % i == 0);
      ans.emplace_back(i, 1, a[i]/i);
      a[1] += a[i];
      a[i] = 0;
    }

    int want = sum / n;
    for(int i=2; i<=n; i++) {
      ans.emplace_back(1, i, want);
    }

    cout << ans.size() << nl;
    for(auto [x, y, z] : ans) {
      cout << x << " " << y << " " << z << nl;
    }
  }

  return 0;
}