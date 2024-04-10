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

  int n, m;
  cin >> n >> m;
  vector<set<int>> stk(m+1);
  vector<int> val(m+1);
  for(int i=1; i<=n; i++) {
    int v;
    cin >> v;
    stk[v].insert(i);
  }

  int ans = 0;
  for(int i=1; i<=m; i++) {
    int last = -1;
    for(int v : stk[i]) {
      if(v > last + 1) {
        val[i]++;
      }
      last = v;
    }
    ans += val[i];
  }

  cout << ans - 1 << nl;
  for(int i=1; i<m; i++) {
    int a, b;
    cin >> a >> b;
    if(stk[a].size() < stk[b].size()) {
      swap(stk[a], stk[b]);
      swap(val[a], val[b]);
    }

    ans -= val[a] + val[b];
    for(int v : stk[b]) {
      auto it = stk[a].insert(v).first;
      int touch = 0;
      touch += (it != stk[a].begin() && *prev(it) == v - 1);
      touch += (next(it) != stk[a].end() && *next(it) == v + 1);
      if(touch == 2) {
        val[a]--;
      } else if(touch == 0) {
        val[a]++;
      }
    }
    ans += val[a];
    cout << ans - 1 << nl;
  }

  return 0;
}