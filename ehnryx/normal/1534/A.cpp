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
    int n, m;
    cin >> n >> m;
    vector g(n, vector<char>(m));
    bool odd = true, even = true;
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        cin >> g[i][j];
        if(g[i][j] == 'R') {
          ((i + j) % 2 ? even : odd) = false;
        } else if(g[i][j] == 'W') {
          ((i + j) % 2 ? odd : even) = false;
        }
      }
    }
    if(odd) {
      cout << "YES" << nl;
      for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
          cout << ((i + j) % 2 ? 'R' : 'W');
        }
        cout << nl;
      }
    } else if(even) {
      cout << "YES" << nl;
      for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
          cout << ((i + j) % 2 ? 'W' : 'R');
        }
        cout << nl;
      }
    } else {
      cout << "NO" << nl;
    }
  }

  return 0;
}