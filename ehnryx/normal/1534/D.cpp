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

vector<int> ask(int n, int u) {
  cout << "? " << u + 1 << endl;
  vector<int> d(n);
  for(int i=0; i<n; i++) {
    cin >> d[i];
  }
  return d;
}

void solve(int n, int root, bool store,
    const vector<int>& dists, const vector<int>& nodes, vector<pair<int,int>>& ans) {
  assert(dists[root] == 0);
  int two = -1;
  for(int u : nodes) {
    if(dists[u] == 1) {
      if (store) ans.emplace_back(root, u);
    } else if(dists[u] == 2) {
      two = u;
    }
  }
  if(two == -1) return;

  vector<int> in, out, big;
  auto sub = ask(n, two);
  int mid = -1;
  for(int u : nodes) {
    if(dists[u] == sub[u]) {
      out.push_back(u);
      if (dists[u] == 1) {
        mid = u;
      }
    } else if(dists[u] < sub[u]) {
      big.push_back(u);
    } else {
      in.push_back(u);
    }
  }
  assert(mid != -1);
  ans.emplace_back(two, mid);

  vector<int> mdst = dists;
  for(int u : out) {
    mdst[u] -= 1;
  }

  solve(n, two, true, sub, in, ans);
  solve(n, mid, true, mdst, out, ans);
  solve(n, root, false, dists, big, ans);
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

  int n;
  cin >> n;
  vector<int> dists = ask(n, 0);
  vector<int> nodes(n);
  iota(begin(nodes), end(nodes), 0);
  vector<pair<int,int>> edges;
  solve(n, 0, true, dists, nodes, edges);

  cout << "!" << endl;
  for(auto [a, b] : edges) {
    cout << a + 1 << " " << b + 1 << nl;
  }
  cout.flush();
  assert(edges.size() == n-1);

  return 0;
}