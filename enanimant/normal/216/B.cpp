/*
 * author:  ADMathNoob
 * created: 01/13/21 15:20:18
 * problem: https://codeforces.com/contest/216/problem/B
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 216B.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 216B.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> was(n, false);
  int cnt_v, cnt_e;
  function<void(int)> Dfs = [&](int v) {
    ++cnt_v;
    cnt_e += (int) g[v].size();
    for (int u : g[v]) {
      if (was[u]) {
        continue;
      }
      was[u] = true;
      Dfs(u);
    }
  };
  auto DoDfsFrom = [&](int v) {
    cnt_v = cnt_e = 0;
    was[v] = true;
    Dfs(v);
    cnt_e /= 2;
  };
  int ans = 0;
  int odd = 0;
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      DoDfsFrom(i);
      if (cnt_v % 2 == 0) {
        continue;
      }
      if (cnt_v == cnt_e) {
        ans += 1;
      } else {
        odd += 1;
      }
      // if (cnt_v == cnt_e) { // cycle
      //   if (cnt_v % 2 == 1) {
      //     ans += 1;
      //   }
      // } else { // path
      //   if (cnt_v % 2 == 1) {
      //     odd += 1;
      //   }
      // }
    }
  }
  if (odd % 2 == 1) {
    ans += 1;
  }
  cout << ans << '\n';


  return 0;
}