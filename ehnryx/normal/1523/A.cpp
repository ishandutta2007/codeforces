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
  while (T--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    m = min(n, m);
    for (int i = 0; i < m; i++) {
      string nxt = s;
      for (int j = 0; j < n; j++) {
        if (s[j] == '0') {
          int cnt = (j > 0 && s[j - 1] == '1') + (j + 1 < n && s[j + 1] == '1');
          if (cnt == 1) {
            nxt[j] = '1';
          }
        }
      }
      s = move(nxt);
    }
    cout << s << nl;
  }

  return 0;
}