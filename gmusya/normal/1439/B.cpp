#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

void dfs(int v, vector <bool> &used, vector <vector <int>> &g, vector <int> &cnt, vector <int> &deg) {
  used[v] = true;
  for (int u : g[v]) {
    if (used[u])
      continue;
    dfs(u, used, g, cnt, deg);
  }
  cnt.push_back(v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector <bool> used(n);
    vector <int> deg(n);
    vector <vector <int>> g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
      if (u > v)
        swap(u, v);
      deg[u]++;
      deg[v]++;
    }
    long long heh = k * 1ll * k;
    long long tmp = m * 4;
    if (heh > tmp) {
      cout << -1 << '\n';
      continue;
    }
    int mda = 0;
    for (int i = 0; i < n; i++)
      mda += (deg[i] >= k - 1);
    if (mda < k) {
      cout << -1 << '\n';
      continue;
    }
    set <pair <int, int>> s;
    for (int v = 0; v < n; v++)
      s.insert({deg[v], v});
    vector <cc_hash_table<int, bool>> us(n);
    for (int v = 0; v < n; v++)
      for (int u : g[v])
        us[v][u] = 1;
    bool flag = false;
    while (s.size() > k - 1) {
      if (flag)
        break;
      int v = s.begin()->second;
      if (deg[v] >= k)
        break;
      used[v] = true;
      if (deg[v] == k - 1) {
        vector <int> arr;
        for (int u : g[v]) {
          if (used[u])
            continue;
          arr.push_back(u);
        }
        bool tf = true;
        for (int i = 0; i < (int)arr.size(); i++)
          for (int j = i + 1; j < (int)arr.size(); j++)
            if (us[arr[i]].find(arr[j]) == us[arr[i]].end()) {
              tf = false;
              break;
            }
        if (tf) {
          cout << 2 << '\n';
          cout << v + 1 << ' ';
          for (int u : arr)
            cout << u + 1 << ' ';
          cout << '\n';
          flag = true;
          break;
        }
      }
      s.erase(s.begin());
      for (int u : g[v]) {
        if (used[u])
          continue;
        s.erase({deg[u], u});
        deg[u]--;
        s.insert({deg[u], u});
      }
    }
    for (int v = 0; v < n; v++) {
      if (flag)
        break;
      if (used[v])
        continue;
      vector <int> cnt;
      dfs(v, used, g, cnt, deg);
      int mi = k;
      for (int u : cnt)
        if (deg[u] < k)
          mi = deg[u];
      if (mi >= k) {
        cout << 1 << ' ' << cnt.size() << '\n';
        for (auto &now : cnt)
          cout << now + 1 << ' ';
        cout << '\n';
        flag = true;
        break;
      }
    }
    if (!flag)
      cout << -1 << '\n';
  }
  return 0;
}