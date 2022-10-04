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

vector <pair <int, int>> ans;
const int N = 1e5 + 7;

vector <int> g[N];

void dfs(int u, int t, int p) {
  int cnt = 0;
  if (p == -1) {
    int ct = 0;
    ans.push_back({0, ct});
    for (auto v : g[u]) {
      if (v != p) {
        dfs(v, ++ct, u); 
        ans.push_back({u, ct});
      }
    }
  }
  else {
    ans.push_back({u, t});
    for (auto v : g[u]) {
      if (v != p) {
        ++cnt;
      }
    }
    int have = t - 1;
    if (have >= cnt) {
      int ct = have - cnt;
      ans.push_back({u, ct});
      for (auto v : g[u]) {
        if (v != p) {
          dfs(v, ++ct, u);
          ans.push_back({u, ct});
        }
      }
    } else {
      int ct = t;
      int need = cnt - have;
      vector <int> ch;
      for (auto v : g[u]) {
        if (v != p) {
          ch.push_back(v);
        }
      }
      for (int i = 0; i < need; ++i) {
        int v = ch[i];
        dfs(v, ++ct, u);
        ans.push_back({u, ct});
      }
      ct = 0;
      ans.push_back({u, ct});
      for (int i = need; i < (int)ch.size(); ++i) {
        int v = ch[i];
        dfs(v, ++ct, u);
        ans.push_back({u, ct});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, 0, -1);
  cout << ans.size() << '\n';
  for (auto p : ans) {
    cout << p.first + 1 << ' ' << p.second << '\n';
  }
}