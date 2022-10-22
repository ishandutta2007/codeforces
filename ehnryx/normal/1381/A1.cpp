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
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> ans;
    for(int i=n; i>0; i--) {
      if(s[i-1] == t[i-1]) continue;
      int j = find(s.begin(), s.begin() + i, t[i-1]) - s.begin();
      if(j < i) {
        ans.push_back(j + 1);
        reverse(s.begin(), s.begin() + j + 1);
        transform(s.begin(), s.begin() + j + 1, s.begin(), [](char c) {
          return c ^ 1;
        });
      }
      ans.push_back(i);
      reverse(s.begin(), s.begin() + i);
      transform(s.begin(), s.begin() + i, s.begin(), [](char c) {
        return c ^ 1;
      });
    }

    cout << ans.size() << " ";
    for(int it : ans) {
      cout << it << " ";
    }
    cout << nl;
  }

  return 0;
}