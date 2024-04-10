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

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for(int i=0; i<n; i++) {
    cin >> a[i];
    a[i] -= i;
  }
  for(int i=0; i<m; i++) {
    cin >> b[i];
    b[i]--;
    if(i > 0 && a[b[i]] < a[b[i-1]]) {
      cout << -1 << nl;
      return 0;
    }
  }
  b.push_back(INF);

  vector<int> lis(n, INF);
  int ans = m;
  int lb = -INF;
  for(int i=0, j=0; i<n; i++) {
    if(a[i] < lb) continue;
    auto it = upper_bound(lis.begin(), lis.end(), a[i]);
    *it = a[i];
    if(i == b[j]) {
      ans += it - lis.begin();
      int len = lower_bound(lis.begin(), lis.end(), INF) - lis.begin();
      fill(lis.begin(), lis.begin() + len, INF);
      lb = a[i];
      j++;
    }
  }
  ans += lower_bound(lis.begin(), lis.end(), INF) - lis.begin();
  cout << n - ans << nl;

  return 0;
}