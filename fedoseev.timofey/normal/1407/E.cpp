#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

const int Inf = 1e9;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <vector <pair <int, int>>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[v].push_back({u, w});
  }
  vector <int> col(n, -1);
  vector <int> d(n, Inf);
  d[n - 1] = 0;
  queue <int> q;
  q.push(n - 1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto [v, w] : g[u]) {
      if (col[v] == -1) {
        col[v] = w ^ 1;
      }
      if (col[v] == w) {
        if (d[u] + 1 < d[v]) {
          d[v] = d[u] + 1;
          q.push(v);
        }
      }
    }
  }
  cout << (d[0] == Inf ? -1 : d[0]) << '\n';
  for (int i = 0; i < n; ++i) {
    if (col[i] == -1) {
      col[i] = 0;
    }
    cout << col[i];
  }
}