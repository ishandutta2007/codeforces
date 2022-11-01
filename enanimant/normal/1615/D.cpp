/*
 * author:  ADMathNoob
 * created: 12/24/21 09:35:14
 * problem: https://codeforces.com/contest/1615/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

void TestCase() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> t(n);
  vector<int> from(n), to(n), value(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> from[i] >> to[i] >> value[i];
    --from[i]; --to[i];
    t[from[i]].push_back(i);
    t[to[i]].push_back(i);
  }
  vector<vector<int>> g(n);
  vector<int> x(m), y(m), p(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i] >> p[i];
    --x[i]; --y[i];
    g[x[i]].push_back(i);
    g[y[i]].push_back(i);
  }
  for (int tid = 0; tid < n - 1; tid++) {
    if (value[tid] != -1) {
      x.push_back(from[tid]);
      y.push_back(to[tid]);
      p.push_back(__builtin_popcount(value[tid]) % 2);
      g[x[m]].push_back(m);
      g[y[m]].push_back(m);
      m += 1;
    }
  }
  vector<int> f(n, -1);
  for (int i = 0; i < n; i++) {
    if (f[i] == -1) {
      vector<int> que(1, i);
      f[i] = 0;
      for (int b = 0; b < (int) que.size(); b++) {
        int v = que[b];
        for (int id : g[v]) {
          int u = x[id] ^ y[id] ^ v;
          if (f[u] != -1) {
            continue;
          }
          f[u] = (f[v] ^ p[id]);
          que.push_back(u);
        }
      }
    }
  }
  for (int id = 0; id < m; id++) {
    if ((f[x[id]] ^ f[y[id]]) != p[id]) {
      cout << "NO\n";
      return;
    }
  }
  for (int tid = 0; tid < n - 1; tid++) {
    if (value[tid] == -1) {
      value[tid] = (f[from[tid]] ^ f[to[tid]]);
    }
  }
  // // vector<int> pv(n, -1);
  // function<void(int, int)> Dfs = [&](int v, int pr) {
  //   // pv[v] = pr;
  //   for (int id : t[v]) {
  //     int u = from[id] ^ to[id] ^ v;
  //     if (u == pr) {
  //       continue;
  //     }
  //     int need = (f[v] ^ f[u]);
  //     if (value[id] == -1) {
  //       value[id] = need;
  //     }
  //     Dfs(u, v);
  //   }
  // };
  // Dfs(0, -1);
  cout << "YES\n";
  for (int tid = 0; tid < n - 1; tid++) {
    cout << from[tid] + 1 << ' ' << to[tid] + 1 << ' ' << value[tid] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    TestCase();
  }
  return 0;
}