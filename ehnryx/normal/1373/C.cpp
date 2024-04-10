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
  for(cin >> T; T--; ) {
    string s;
    cin >> s;
    vector<int> a, b;
    transform(s.begin(), s.end(), back_inserter(a), [](char c) {
      return c == '+' ? 1 : -1;
    });
    partial_sum(a.begin(), a.end(), back_inserter(b));

    int low = 0;
    ll ans = 0;
    for(int i=0; i<b.size(); i++) {
      if(b[i] < low) {
        low = b[i];
        ans += i + 1;
      }
    }
    cout << ans + s.size() << nl;
  }

  return 0;
}