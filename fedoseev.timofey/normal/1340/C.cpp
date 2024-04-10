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
 
using namespace std;
 
typedef long long ll;
 
const int M = 10007;
const int T = 1007;
const int Inf = 1e9;
 
int dist[M * T];
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <int> d(m);
  for (int i = 0; i < m; ++i) cin >> d[i];
  sort(d.begin(), d.end());
  int g, r;
  cin >> g >> r;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j <= g; ++j) {
      dist[i * (g + 1) + j] = Inf;
    }
  } 
  deque <int> q;
  dist[0 * (g + 1) + g] = 0;
  q.push_back(0 * (g + 1) + g);
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    int id = u / (g + 1);
    int tm = u % (g + 1);
    auto go = [&] (int v, int w) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        if (w == 0) q.push_front(v);
        else q.push_back(v);
      }
    };
    if (tm == 0) {
      go(id * (g + 1) + g, 1);
    }
    if (id > 0 && d[id] - d[id - 1] <= tm) {
      go((id - 1) * (g + 1) + tm - (d[id] - d[id - 1]), 0);
    }
    if (id + 1 < m && d[id + 1] - d[id] <= tm) {
      go((id + 1) * (g + 1) + tm - (d[id + 1] - d[id]), 0);
    }
  }
  int ans = Inf;
  for (int i = 0; i < m; ++i) {
    if (d[m - 1] - d[i] <= g) {
      if (dist[i * (g + 1) + g] != Inf) ans = min(ans, (g + r) * dist[i * (g + 1) + g] + d[m - 1] - d[i]);
    }
  }
  if (ans == Inf) {
    cout << "-1\n";
  } else {
    cout << ans << '\n';
  }
}