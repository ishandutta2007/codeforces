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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <int> w(n);
  for (int i = 0; i < n; ++i) cin >> w[i];
  vector <int> ans;
  vector <set <pair <int, int>>> g(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].insert({y, i});
    g[y].insert({x, i});
  }
  function <void(int)> rec = [&] (int u) {
    if (g[u].empty() || g[u].size() > w[u]) return;
    vector <int> who;
    for (auto p : g[u]) {
      ans.push_back(p.second);
      g[p.first].erase({u, p.second});
      who.push_back(p.first);
    }
    g[u].clear();
    for (auto v : who) rec(v);
  };    
  for (int i = 0; i < n; ++i) rec(i);
  if (ans.size() == m) {
    cout << "ALIVE\n";
    reverse(ans.begin(), ans.end());
    for (int id : ans) cout << id + 1 << ' ';
  } else {
    cout << "DEAD\n";
  }
}