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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> left(n+1), right(n+1);
    for(int i=0; i<n; i++) {
      int c;
      cin >> c;
      if(i < l) {
        left[c]++;
      } else {
        right[c]++;
      }
    }

    int ans = 0;
    for(int i=1; i<=n; i++) {
      int used = min(left[i], right[i]);
      left[i] -= used;
      right[i] -= used;
    }

    for(int i=1; i<=n && l != r; i++) {
      if(l < r && right[i] > 1) {
        right[i--] -= 2;
        ans++;
        l += 1;
        r -= 1;
      } else if(r < l && left[i] > 1) {
        left[i--] -= 2;
        ans++;
        l -= 1;
        r += 1;
      }
    }

    ans += abs(l - r) / 2;
    ans += (accumulate(begin(left), end(left), 0) + accumulate(begin(right), end(right), 0)) / 2;
    cout << ans << nl;
  }

  return 0;
}