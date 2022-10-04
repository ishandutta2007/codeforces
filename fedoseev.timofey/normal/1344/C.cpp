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

const int N = 2e5 + 7;

set <int> g[N];
set <int> rg[N];
int color[N];

bool bad = false;

void dfs(int u) {
  color[u] = 1;
  for (auto v : g[u]) {
    if (color[v] == 0) {
      dfs(v);
    } else if (color[v] == 1) {
      bad = true;
    }
  } 
  color[u] = 2;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].insert(v);
    rg[v].insert(u);
  }
  for (int i = 0; i < n; ++i) {
    if (color[i] == 0) {
      dfs(i);
    }
  }
  if (bad) {
    cout << "-1\n";
    return 0;
  }
  set <int> alive;
  for (int i = 0; i < n; ++i) {
    alive.insert(i);
  }
  function <void(int)> kill_f = [&] (int u) {
    alive.erase(u);
    for (auto v : g[u]) {
      kill_f(v);
    }
    g[u].clear();
  };

  function <void(int)> kill_b = [&] (int u) {
    alive.erase(u);
    for (auto v : rg[u]) {
      kill_b(v);
    }
    rg[u].clear();
  };

  vector <char> ans(n, 'E');
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (alive.count(i)) {
      ++cnt;
      ans[i] = 'A';
    }
    kill_f(i);
    kill_b(i);
  }
  cout << cnt << '\n';
  for (int i = 0; i < n; ++i) cout << ans[i];
  cout << '\n';
}