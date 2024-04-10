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

  int n, m;
  cin >> n >> m;
  vector g(n, vector<char>(m));
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> g[i][j];
    }
  }

  int ans = (g[0][0] == '*');
  int x = 0;
  int y = 0;
  for(;;) {
    tuple<int,int,int> best(INF, INF, INF);
    for(int i=x; i<n; i++) {
      for(int j=y; j<m; j++) {
        if(pair(i, j) == pair(x, y)) continue;
        if(g[i][j] == '*') {
          best = min(best, tuple(i-x + j-y, i, j));
        }
      }
    }
    if(get<0>(best) == INF) {
      break;
    }
    tie(x, y) = pair(get<1>(best), get<2>(best));
    ans++;
  }
  cout << ans << nl;

  return 0;
}