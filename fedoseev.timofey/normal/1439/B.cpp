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
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector <set <int>> g(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].insert(v);
      g[v].insert(u);
    }
    set <pair <int, int>> gs;
    for (int i = 0; i < n; ++i) {
      gs.insert({(int)g[i].size(), i});
    }
    vector <set <int>> ng(n);
    vector <set <int>> sg = g;
    while (!gs.empty()) {
      auto p = *gs.begin();
      if (p.first >= k) break;
      int u = p.second;
      gs.erase(gs.begin());
      ng[u] = g[u];
      for (auto v : g[u]) {
        gs.erase({(int)g[v].size(), v});
        g[v].erase(u);
        gs.insert({(int)g[v].size(), v});
      }
    }
    if (!gs.empty()) {
      cout << "1 " << (int)gs.size() << '\n';
      for (auto p : gs) {
        cout << p.second + 1 << ' ';
      }
      cout << '\n';
      continue;
    }
    g = sg;
    gs.clear();
    for (int i = 0; i < n; ++i) {
      gs.insert({(int)g[i].size(), i});
    }
    vector <int> ans;
    vector <int> good(n);
    int timer = 0;
    while (!gs.empty()) {
      auto p = *gs.begin();
      int u = p.second;
      gs.erase(gs.begin());
      if ((int)g[u].size() == k - 1) {
        ++timer;
        good[u] = timer;
        for (auto v : g[u]) {
          good[v] = timer;
        }
        vector <int> rofl(k);
        ++rofl[k - 1];
        for (auto v : g[u]) {
          ++rofl[min(k - 1, (int)ng[v].size())];
        }
        for (int i = k - 2; i >= 0; --i) rofl[i] += rofl[i + 1];
        int ok = 1;
        for (int i = k - 1; i >= 0; --i) {
          ok &= (rofl[i] >= (k - i));
        }
        if (ok) {
          int cnt = k - 1;
          for (auto v : g[u]) {
            for (auto w : ng[v]) {
              if (good[w] == timer) ++cnt;
            }
          }
          if (cnt == (ll)k * (k - 1) / 2) {
            ans.push_back(u);
            for (auto v : g[u]) {
              ans.push_back(v);
            }
            sort(ans.begin(), ans.end());
            break;
          }
        }
      }
      for (auto v : g[u]) {
        gs.erase({(int)g[v].size(), v});
        g[v].erase(u);
        gs.insert({(int)g[v].size(), v});
      }
    }
    if (!ans.empty()) {
      cout << "2\n";
      for (auto x : ans) {
        cout << x + 1 << ' ';
      }
      cout << '\n';
    } else {
      cout << "-1\n";
    }
  }   
}