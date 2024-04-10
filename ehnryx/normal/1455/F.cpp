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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<string> best(n+1, s);
    for(int i=0; i<n; i++) {
      // decrease
      s = best[i];
      if(s[i] > 'a') {
        s[i]--;
        best[i+1] = min(best[i+1], s);
      }
      // increase
      s = best[i];
      if(s[i] - 'a' + 1 == m) {
        s[i] = 'a';
        best[i+1] = min(best[i+1], s);
      }
      // left
      s = best[i];
      if(i > 0) {
        swap(s[i], s[i-1]);
        best[i+1] = min(best[i+1], s);
      }
      // right, decrease
      s = best[i];
      if(i+1 < n && s[i+1] > 'a') {
        swap(s[i], s[i+1]);
        s[i]--;
        best[i+2] = min(best[i+2], s);
      }
      // right, increase
      s = best[i];
      if(i+1 < n && s[i+1] - 'a' + 1 == m) {
        swap(s[i], s[i+1]);
        s[i] = 'a';
        best[i+2] = min(best[i+2], s);
      }
      // right, left
      s = best[i];
      if(i+1 < n && i > 0) {
        swap(s[i], s[i+1]);
        swap(s[i], s[i-1]);
        best[i+2] = min(best[i+2], s);
      }
    }
    cout << best[n] << nl;
  }

  return 0;
}