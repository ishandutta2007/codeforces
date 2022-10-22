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

  int n, m, k;
  cin >> n >> m >> k;
  if (k % 2) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << -1 << " ";
      }
      cout << nl;
    }
    return 0;
  }

  vector h(n, vector<int>(m)), v(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      cin >> h[i][j];
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  vector dist(n, vector<int>(m));
  for (int t = 1; t <= k / 2; t++) {
    vector nd(n, vector<int>(m, INF));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i > 0) nd[i][j] = min(nd[i][j], dist[i - 1][j] + v[i][j]);
        if (j > 0) nd[i][j] = min(nd[i][j], dist[i][j - 1] + h[i][j]);
        if (i + 1 < n) nd[i][j] = min(nd[i][j], dist[i + 1][j] + v[i + 1][j]);
        if (j + 1 < m) nd[i][j] = min(nd[i][j], dist[i][j + 1] + h[i][j + 1]);
      }
    }
    dist = move(nd);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << 2 * dist[i][j] << " ";
    }
    cout << nl;
  }

  return 0;
}