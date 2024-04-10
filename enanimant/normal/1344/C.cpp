/*
 * author:  ADMathNoob
 * created: 07/20/21 09:43:22
 * problem: https://codeforces.com/contest/1344/problem/C
 */

/*
g++ 1344C.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1344C.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> out(n);
  vector<vector<int>> in(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    out[x].push_back(y);
    in[y].push_back(x);
  }
  bool has_cycle = false;
  vector<int> state(n, -1);
  function<void(int)> Dfs1 = [&](int v) {
    if (state[v] == 0) {
      has_cycle = true;
      return;
    }
    if (state[v] == 1) {
      return;
    }
    state[v] = 0;
    for (int u : out[v]) {
      Dfs1(u);
    }
    state[v] = 1;
  };
  for (int i = 0; i < n; i++) {
    Dfs1(i);
  }
  if (has_cycle) {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> min_out(n, -1);
  vector<int> min_in(n, -1);
  function<void(int)> DfsOut = [&](int v) {
    if (min_out[v] != -1) {
      return;
    }
    min_out[v] = v;
    for (int u : out[v]) {
      DfsOut(u);
      min_out[v] = min(min_out[v], min_out[u]);
    }
  };
  function<void(int)> DfsIn = [&](int v) {
    if (min_in[v] != -1) {
      return;
    }
    min_in[v] = v;
    for (int u : in[v]) {
      DfsIn(u);
      min_in[v] = min(min_in[v], min_in[u]);
    }
  };
  vector<int> res(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    DfsOut(i);
    DfsIn(i);
    res[i] = (min_out[i] == i && min_in[i] == i);
    cnt += res[i];
  }
  cout << cnt << '\n';
  for (int i = 0; i < n; i++) {
    cout << (res[i] ? 'A' : 'E');
  }
  cout << '\n';
  return 0;
}