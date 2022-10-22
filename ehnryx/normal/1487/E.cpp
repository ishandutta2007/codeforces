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

struct SegmentTree {
  int N;
  vector<int> st;
  SegmentTree() = default;
  SegmentTree(int n) {
    N = 1 << (32 - __builtin_clz(max(1, n - 1)));
    st.resize(2 * N);
  }
  void insert(int i, int v) {
    st[i += N] = v;
    for(i/=2; i; i/=2) {
      st[i] = min(st[2*i], st[2*i+1]);
    }
  }
  int query(int l, int r) {
    int res = INF;
    for(l += N, r += N; l < r; l /= 2, r /= 2) {
      if(l & 1) res = min(res, st[l++]);
      if(r & 1) res = min(res, st[--r]);
    }
    return res;
  }
};

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

  vector<int> n(5, 1);
  vector<SegmentTree> st(5);
  for(int i=1; i<=4; i++) {
    cin >> n[i];
    st[i] = SegmentTree(n[i]);
  }
  st[0] = SegmentTree(1);

  vector<vector<int>> cost(5);
  vector<vector<vector<int>>> sep(5);
  for(int i=1; i<=4; i++) {
    sep[i].resize(n[i]);
    cost[i].resize(n[i]);
    for(int j=0; j<n[i]; j++) {
      cin >> cost[i][j];
    }
  }

  for(int i=2; i<=4; i++) {
    int m;
    cin >> m;
    for(int j=0; j<m; j++) {
      int x, y;
      cin >> x >> y;
      sep[i][y - 1].push_back(x - 1);
    }
  }

  for(int i=1; i<=4; i++) {
    for(int j=0; j<n[i]; j++) {
      sort(begin(sep[i][j]), end(sep[i][j]));
      sep[i][j].push_back(n[i-1]);
      int res = INF;
      for(int k=0, l=0; k<size(sep[i][j]); k++) {
        res = min(res, cost[i][j] + st[i-1].query(l, sep[i][j][k]));
        l = sep[i][j][k] + 1;
      }
      st[i].insert(j, res);
    }
  }

  int ans = st[4].query(0, n[4]);
  if(ans < INF) {
    cout << ans << nl;
  } else {
    cout << -1 << nl;
  }

  return 0;
}