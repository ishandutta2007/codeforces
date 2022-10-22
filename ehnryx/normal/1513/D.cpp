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
random_device _rd; mt19937 rng(_rd());



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
    int n, cost;
    cin >> n >> cost;
    vector<int> a(n);
    vector<pair<int,int>> order;
    for(int i=0; i<n; i++) {
      cin >> a[i];
      order.emplace_back(a[i], i);
    }
    sort(begin(order), end(order));

    vector<int> res(n-1, cost);
    vector<bool> done(n-1);
    for(auto [v, i] : order) {
      if(v >= cost) break;
      int l = i;
      while(l > 0 && !done[l-1] && a[l-1] % v == 0) {
        l--;
      }
      int r = i;
      while(r+1 < n && !done[r] && a[r+1] % v == 0) {
        r++;
      }
      for(int j=l; j<r; j++) {
        res[j] = v;
        done[j] = true;
      }
    }

    ll ans = accumulate(begin(res), end(res), (ll)0);
    cout << ans << nl;
  }

  return 0;
}