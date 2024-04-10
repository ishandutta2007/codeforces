/*
 * author:  ADMathNoob
 * created: 02/17/21 22:41:09
 * problem: https://codeforces.com/contest/1485/problem/E
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1485E.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1485E.cpp -ggdb && gdb a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors 1485E.cpp && a


*/

#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)1e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int p;
      cin >> p;
      --p;
      g[p].push_back(i);
      g[i].push_back(p);
    }
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
      cin >> a[i];
    }
    vector<int> pv(n, -1);
    vector<int> depth(n, -1);
    vector<int> que(1, 0);
    depth[0] = 0;
    for (int b = 0; b < (int)que.size(); b++) {
      int v = que[b];
      for (int u : g[v]) {
        if (depth[u] != -1) {
          continue;
        }
        pv[u] = v;
        depth[u] = depth[v] + 1;
        que.push_back(u);
      }
    }
    int d = *max_element(depth.begin(), depth.end());
    vector<vector<int>> at_depth(d + 1);
    for (int i = 0; i < n; i++) {
      at_depth[depth[i]].push_back(i);
    }
    vector<long long> dp(n, 0);
    for (int j = d - 1; j >= 0; j--) {
      vector<int> as;
      // vector<long long> dps_small, dps_large;
      long long mx_small = -INF, mx_large = -INF;
      for (int u : at_depth[j + 1]) {
        as.push_back(a[u]);
        mx_small = max(mx_small, dp[u] - a[u]);
        mx_large = max(mx_large, dp[u] + a[u]);
        // dps_small.push_back(dp[u] - a[u]);
        // dps_large.push_back(dp[u] + a[u]);
      }
      sort(as.begin(), as.end());
      // sort(dps_small.begin(), dps_small.end());
      // sort(dps_large.begin(), dps_large.end());
      for (int v : at_depth[j]) {
        for (int u : g[v]) {
          if (u == pv[v]) {
            continue;
          }
          dp[v] = max(dp[v], dp[u] + max(a[u] - as[0], as.back() - a[u]));
          dp[v] = max(dp[v], a[u] + mx_small);
          dp[v] = max(dp[v], mx_large - a[u]);
        }
      }
    }
    cout << dp[0] << '\n';
  }

  return 0;
}