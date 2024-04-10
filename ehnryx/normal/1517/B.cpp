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
    vector<tuple<int,int,int>> order;
    vector a(n, vector<int>(m));
    vector perm(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      iota(begin(perm[i]), end(perm[i]), 0);
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        order.emplace_back(a[i][j], i, j);
      }
    }
    sort(begin(order), end(order));

    vector ans(n, vector<int>(m));
    set<pair<int, int>> have;
    for (int k = 0; k < m; k++) {
      auto [v, i, j] = order[k];
      ans[i][k] = v;
      have.insert(pair(i, j));
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0, k = 0; j < m; j++) {
        if (ans[i][j]) continue;
        while (k < m && have.count(pair(i, k))) {
          k++;
        }
        assert(k < m);
        ans[i][j] = a[i][k++];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << ans[i][j] << " ";
      }
      cout << nl;
    }
  }

  return 0;
}