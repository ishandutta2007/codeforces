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
  int n, m, x;
  cin >> n >> m >> x;
  vector <ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  map <pair <int, int>, int> ei;
  vector <vector <pair <int, int>>> edges(n);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges[u].push_back({u, v});
    edges[v].push_back({v, u});
    ei[{u, v}] = ei[{v, u}] = i;
  }

  vector <int> id(n);
  for (int i = 0; i < n; ++i) id[i] = i;
  vector <vector <int>> who(n);
  for (int i = 0; i < n; ++i) {
    who[i].push_back(i);
  }
  vector <ll> sum = a;
  set <pair <ll, int>> gs;
  for (int i = 0; i < n; ++i) {
    gs.insert({a[i], i});
  }
  vector <int> ans;
  while (gs.size() > 1) {
    auto p = *gs.rbegin();
    gs.erase(--gs.end());
    int c = p.second;

    while (true) {
      assert(!edges[c].empty());

      auto p = edges[c].back();
      int u = p.first, v = p.second;
      assert(id[u] == c);
      int a = id[u], b = id[v];

      if (a == b) {
        edges[c].pop_back();
        continue;
      }

      if (sum[a] + sum[b] < x) {
        cout << "NO\n";
        return 0;
      }

      gs.erase({sum[b], b});
      ans.push_back({ei[{u, v}]});

      if (who[b].size() > who[a].size()) swap(a, b);

      sum[a] += sum[b];
      sum[a] -= x;
      for (auto p : edges[b]) {
        edges[a].push_back(p);
      }

      for (auto w : who[b]) {
        who[a].push_back(w);
        id[w] = a;
      }

      who[b] = {};

      gs.insert({sum[a], a});
      break;
    }
  }
  cout << "YES\n";
  for (int i : ans) {
    cout << i + 1 << '\n';
  }
}