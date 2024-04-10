#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k1, k2;
  cin >> n >> m >> k1 >> k2;
  if (k1 > m - 1 || k2 > n - 1) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";

  vector<int> a(m - 1), b(n - 1);
  vector<int> deg(n + m);
  for (int i = 0; i < m - 1; ++i) {
    if (i < k1) {
      cin >> a[i];
      --a[i];
    } else {
      a[i] = 0;
    }
    deg[a[i]]++;
  }
  for (int i = 0; i < n - 1; ++i) {
    if (i < k2) {
      cin >> b[i];
      --b[i];
    } else {
      b[i] = n + m - 1;
    }
    deg[b[i]]++;
  }
  set<int> leaves;
  for (int i = 0; i < n + m; ++i) {
    if (!deg[i]) {
      leaves.insert(i);
    }
  }
  vector<pair<int, int>> edges;
  int p1 = 0;
  int p2 = 0;
  while (p1 < m - 1 || p2 < n - 1) {
    auto who = *leaves.begin();
    leaves.erase(leaves.begin());
    auto nei = who < n ? b[p2++] : a[p1++];
    edges.emplace_back(who, nei);
    if (!--deg[nei]) {
      leaves.insert(nei);
    }
  }
  assert(leaves.size() == 2);
  edges.emplace_back(*leaves.begin(), *leaves.rbegin());
  for (auto[u, v] : edges) {
    cout << u + 1 << ' ' << v + 1 << '\n';
  }
  return 0;
}