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

  int n;
  cin >> n;
  vector<tuple<int,int,int>> v;
  for(int i=0; i<n; i++) {
    int l, r, t;
    cin >> l >> r >> t;
    v.emplace_back(l, r, t-1);
    v.emplace_back(r, INF, t-1);
  }
  sort(v.begin(), v.end());

  multiset<int> cur[2];
  multiset<pair<int,int>> have;
  int match = 0;
  for(auto [l, r, t] : v) {
    if(r == INF) {
      auto it = have.lower_bound(make_pair(l, t));
      if(it != have.end() && *it == make_pair(l, t)) {
        have.erase(it);
        if(!cur[t^1].empty()) {
          have.erase(have.find(make_pair(*cur[t^1].begin(), t^1)));
          cur[t^1].erase(cur[t^1].begin());
          match++;
        }
        cur[t].erase(cur[t].begin());
      }
    } else {
      cur[t].insert(r);
      have.insert(make_pair(r, t));
    }
  }
  cout << n - match << nl;

  return 0;
}