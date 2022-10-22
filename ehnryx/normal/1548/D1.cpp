#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
using ordered_set = __gnu_pbds::tree<T,
      __gnu_pbds::null_type,
      less<T>,
      __gnu_pbds::rb_tree_tag,
      __gnu_pbds::tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 998244353;
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

  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for(int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    v.emplace_back(a, b);
  }

  vector<int> dsu(n, -1), sz(n, 1);
  function<int(int)> find = [&](int i) {
    if(dsu[i] == -1) return i;
    return dsu[i] = find(dsu[i]);
  };
  function<void(int,int)> link = [&](int i, int j) {
    i = find(i); j = find(j);
    if(i != j) {
      dsu[i] = j;
      sz[j] += sz[i];
    }
  };

  for(int i=0; i<n; i++) {
    for(int j=0; j<i; j++) {
      int dx = abs(v[i].first - v[j].first);
      int dy = abs(v[i].second - v[j].second);
      if(gcd(dx, dy) % 4 == 0) {
        link(i, j);
      }
    }
  }

  ll bad = 0;
  for(int i=0; i<n; i++) {
    if(i != find(i)) continue;
    int c = sz[i];
    ll one = (ll)c * (n-c) * (n-c-1) / 2;
    ll two = (ll)c * (c-1) / 2 * (n-c); // good
    bad += one - two;
  }
  //cerr << "bad: " << bad << nl;
  ll ans = (ll)n * (n-1) * (n-2) / 6 - bad / 3;
  cout << ans << nl;


  return 0;
}