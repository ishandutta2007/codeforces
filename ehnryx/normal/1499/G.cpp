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
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int add(int a, int b) {
  return a+b < MOD ? a+b : a+b-MOD;
}

const int N = 4e5 + 1;
int con[N];
int dsu[N], lc[N], rc[N], blue[N], red[N];
int two[N];
list<int> path[N];

int find(int i) {
  if(dsu[i] == 0) return i;
  return dsu[i] = find(dsu[i]);
}

int link(int i, int j) {
  int ri = find(i);
  int rj = find(j);
  if(path[ri].size() < path[rj].size()) {
    swap(ri, rj);
    swap(i, j);
  }

  bool idir = (path[ri].back() == i);
  bool jdir = (path[rj].front() == j);
  if(idir != jdir) {
    reverse(path[rj].begin(), path[rj].end());
    swap(lc[rj], rc[rj]);
  }

  bool icol = (idir ? rc[ri] : lc[ri]);
  bool jcol = (idir ? lc[rj] : rc[rj]);
  int res = 0;
  if(icol == jcol) {
    res = add(blue[ri], MOD - red[ri]);
    lc[ri] ^= 1;
    rc[ri] ^= 1;
    swap(red[ri], blue[ri]);
  }

  dsu[rj] = ri;
  red[ri] = add(red[ri], red[rj]);
  blue[ri] = add(blue[ri], blue[rj]);
  if(idir) {
    rc[ri] = rc[rj];
    path[ri].splice(path[ri].end(), path[rj]);
  } else {
    lc[ri] = lc[rj];
    path[ri].splice(path[ri].begin(), path[rj]);
  }

  return res;
}

int add_edge(int a, int b, int i) {
  blue[i] = two[i];
  path[i].push_back(i);

  int res = 0;

  if(con[a]) {
    res = add(res, link(con[a], i));
    con[a] = 0;
  } else {
    con[a] = i;
  }

  if(con[b]) {
    if(find(i) != find(con[b])) {
      res = add(res, link(i, con[b]));
    }
    con[b] = 0;
  } else {
    con[b] = i;
  }

  return res;
}

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

  two[0] = 1;
  for(int i=1; i<N; i++) {
    two[i] = add(two[i-1], two[i-1]);
  }

  int n1, n2, m;
  cin >> n1 >> n2 >> m;

  int ha = 0;
  for(int i=1; i<=m; i++) {
    int a, b;
    cin >> a >> b;
    ha = add(ha, add_edge(a, b + n1, i));
  }

  int q;
  cin >> q;
  for(int i=m; q--; ) {
    int t;
    cin >> t;
    if(t == 1) {
      int a, b;
      cin >> a >> b;
      ha = add(ha, add_edge(a, b + n1, ++i));
      cout << ha << endl;
    } else {
      vector<int> ans;
      for(int j=1; j<=i; j++) {
        if(find(j) != j) continue;
        int r = lc[find(j)];
        for(int u : path[find(j)]) {
          if(r) ans.push_back(u);
          r ^= 1;
        }
      }
      cout << ans.size() << " ";
      for(int u : ans) {
        cout << u << " ";
      }
      cout << endl;
    }
  }

  return 0;
}