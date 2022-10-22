#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

void merge(multiset<int>& a, multiset<int>& b) {
  if(size(a) < size(b)) swap(a, b);
  for(int v : b) {
    a.insert(v);
  }
  b.clear();
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int n;
  cin >> n;
  int root = 0;
  vector<int> val(n+1);
  for(int i=1; i<=n; i++) {
    cin >> val[i];
    if(val[i] > val[root]) {
      root = i;
    }
  }
  assert(root);
  vector<vector<int>> adj(n+1);
  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<multiset<int>> have(n+1);
  function<void(int, int)> solve = [&](int u, int p) {
    for(int v : adj[u]) {
      if(v == p) continue;
      solve(v, u);
      if(u != root) {
        merge(have[u], have[v]);
      }
    }
    if(size(adj[u]) == 1) {
      have[u].insert(val[u]);
    } else if(u != root && *rbegin(have[u]) < val[u]) {
      have[u].erase(prev(end(have[u])));
      have[u].insert(val[u]);
    }
  };
  cerr << "root = " << root << nl;
  solve(root, 0);

  ll ans = 0;
  vector<int> big;
  for(int i=1; i<=n; i++) {
    if(empty(have[i])) continue;
    for(int v : have[i]) {
      ans += v;
    }
    big.push_back(*have[i].rbegin());
  }
  sort(begin(big), end(big), greater<>());
  ans += 2 * val[root] - big[0] - big[1];
  cout << ans << nl;

  return 0;
}