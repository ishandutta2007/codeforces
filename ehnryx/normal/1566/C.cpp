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

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;

    int ans = 0;
    bool zero = false;
    bool one = false;
    for(int i=0; i<n; i++) {
      if(zero && (s[i] == '0' || t[i] == '0')) {
        assert(!one);
        ans += 1; // cut
        zero = false;
      }
      zero |= (s[i] == '0' || t[i] == '0');
      one |= (s[i] == '1' || t[i] == '1');
      if(zero && one) {
        ans += 2;
        zero = false;
        one = false;
      }
    }
    ans += zero;
    cout << ans << nl;
  }

  return 0;
}