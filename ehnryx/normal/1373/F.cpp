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
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) {
      cin >> a[i];
    }
    for(int i=0; i<n; i++) {
      cin >> b[i];
    }

    int carry = max(0, a[0] - b[n-1]);
    for(int i=0; i<n; i++) {
      int cap = max(0, b[i] - carry);
      carry = max(0, a[(i+1)%n] - cap);
    }
    int first = carry;
    bool ok = true;
    for(int i=0; i<n && ok; i++) {
      ok &= (carry <= b[i]);
      int cap = max(0, b[i] - carry);
      carry = max(0, a[(i+1)%n] - cap);
    }
    if(ok && carry <= first) {
      cout << "YES" << nl;
    } else {
      cout << "NO" << nl;
    }
  }

  return 0;
}