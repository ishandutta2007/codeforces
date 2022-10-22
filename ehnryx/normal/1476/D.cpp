//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct DSU {
  vector<int> dsu, sz;
  DSU(int n) {
    dsu.resize(n, -1);
    sz.resize(n, 1);
  }
  int find(int i) {
    if(dsu[i] == -1) return i;
    return dsu[i] = find(dsu[i]);
  }
  void link(int i, int j) {
    i = find(i);
    j = find(j);
    if(i == j) return;
    dsu[i] = j;
    sz[j] += sz[i];
  }
  int size(int i) {
    return sz[find(i)];
  }
};

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
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
    DSU dsu(2*(n+1));
    for(int i=0; i<n; i++) {
      char dir;
      cin >> dir;
      if(dir == 'L') {
        dsu.link(i+1, n+1 + i);
      } else {
        dsu.link(i, n+1 + i+1);
      }
    }
    for(int i=0; i<=n; i++) {
      cout << dsu.size(i) << " ";
    }
    cout << nl;
  }

  return 0;
}