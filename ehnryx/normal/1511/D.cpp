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

namespace Euler {
  const int N = 26;
  multiset<int> adj[N];
  void euler(int u, list<int>& ans, list<int>::iterator it) {
    for (auto it2 = adj[u].begin(); it2 != adj[u].end(); ) {
      int v=*it2; adj[u].erase(it2);
      euler(v, ans, ans.insert(it, v)); it2 = adj[u].begin(); } }
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

  int n, k;
  cin >> n >> k;
  for(int i=0; i<k; i++) {
    for(int j=0; j<k; j++) {
      Euler::adj[i].insert(j);
    }
  }
  list<int> ans;
  Euler::euler(0, ans, begin(ans));

  vector<int> res(begin(ans), end(ans));
  for(int i=0; i<n; i++) {
    cout << (char)(res[i % size(ans)] + 'a');
  }
  cout << nl;

  return 0;
}