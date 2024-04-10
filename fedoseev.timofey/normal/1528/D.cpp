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
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <vector <pair <int, int>>> go(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    go[a].push_back({b, c});
  }
  for (int i = 0; i < n; ++i) {
    sort(go[i].begin(), go[i].end(), [&] (pair <int, int> f, pair <int, int> s) {
      return f.second < s.second;
    });
  }
  const ll Inf = 1.5e9;
  vector <vector <int>> ans(n, vector <int> (n, Inf));
  for (int st = 0; st < n; ++st) {
    vector <vector <int>> can(n, vector <int> (n));
    vector <int> d(n, Inf);
    d[st] = 0;
    vector <int> used(n);
    for (int it = 0; it < n; ++it) {
      int u = -1;
      for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        if (u == -1 || d[i] < d[u]) {
          u = i;
        }
      }
      used[u] = 1;
      vector <int> can_go(n, Inf);
      for (auto p : go[u]) {
        int v = (p.first + d[u]) % n;
        can_go[v] = min(can_go[v], d[u] + p.second);
      }
      for (int tt = 0; tt < 2; ++tt) {
        for (int i = 0; i < n; ++i) {
          can_go[i] = min(can_go[i], can_go[(i - 1 + n) % n] + 1);
        }
      }
      for (int i = 0; i < n; ++i) d[i] = min(d[i], can_go[i]);
    }
    for (int i = 0; i < n; ++i) ans[st][i] = d[i];
  }
  for (int i = 0; i < n; ++i) {
    ans[i][i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
}