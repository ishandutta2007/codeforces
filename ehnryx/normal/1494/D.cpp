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

  int n;
  cin >> n;
  vector<int> top(n+1), cost(n+1);
  vector<tuple<int,int,int>> order;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      int val;
      cin >> val;
      if(i == j) {
        cost[i] = val;
        top[i] = i;
      } else {
        order.emplace_back(val, i, j);
      }
    }
  }
  sort(order.begin(), order.end());

  vector<int> dsu(n+1);
  function<int(int)> find = [&](int i) {
    if(dsu[i] == 0) return i;
    return find(dsu[i]);
    //return dsu[i] = find(dsu[i]);
  };
  function<void(int,int)> link = [&](int i, int j) {
    if(find(i) != find(j)) {
      dsu[find(i)] = find(j);
    }
  };

  vector<pair<int,int>> edges;
  for(auto [c, i, j] : order) {
    if(find(i) == find(j)) continue;
    int a = top[find(i)];
    int b = top[find(j)];
    if(cost[a] == c) {
      link(i, j);
      top[find(i)] = a;
      edges.emplace_back(b, a);
    } else if(cost[b] == c) {
      link(i, j);
      top[find(i)] = b;
      edges.emplace_back(a, b);
    } else {
      int lca = cost.size();
      cost.push_back(c);
      link(i, j);
      top[find(i)] = lca;
      edges.emplace_back(a, lca);
      edges.emplace_back(b, lca);
    }
  }

  n = cost.size() - 1;
  cout << n << nl;
  for(int i=1; i<=n; i++) {
    cout << cost[i] << " ";
  }
  cout << nl;
  cout << top[find(1)] << nl;
  for(auto [a, b] : edges) {
    cout << a << " " << b << nl;
  }

  return 0;
}