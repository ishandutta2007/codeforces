// August 11, 2019
// https://codeforces.com/contest/1200/problem/F

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MOD = 2520; // lcm(1, 2, ..., 10)
const int N = 1005;


int n, q;
int k[N], m[N];
vector<int> e[N];
int succ[MOD * N];
int was[MOD * N];
int was2[N];
int ans[MOD * N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k[i];
    k[i] = (k[i] % MOD + MOD) % MOD;
  }
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    e[i].resize(m[i]);
    for (int j = 0; j < m[i]; j++) {
      cin >> e[i][j];
      e[i][j]--;
    }
    for (int j = 0; j < MOD; j++) {
      int nxt = (j + k[i]) % MOD;
      succ[j * n + i] = nxt * n + e[i][nxt % m[i]];
    }
  }
  fill(was, was + MOD * N, -1);
  fill(was2, was2 + N, -1);
  for (int i = 0; i < MOD * n; i++) {
    if (was[i] != -1) {
      continue;
    }
    int v = i;
    vector<int> stk;
    while (was[v] == -1) {
      was[v] = i;
      stk.push_back(v);
      v = succ[v];
    }
    int res;
    if (was[v] != i) {
      res = ans[v];
    } else {
      // int j = find(stk.begin(), stk.end(), v) - stk.begin();
      res = 0;
      for (int j = find(stk.begin(), stk.end(), v) - stk.begin(); j < (int) stk.size(); j++) {
        int node = stk[j] % n;
        if (was2[node] != i) {
          res++;
          was2[node] = i;
        }
      }
      // while (j < (int) stk.size()) {
      //   int node = stk[j] % n;
      //   if (was2[node] != i) {
      //     res++;
      //     was2[node] = i;
      //   }
      // }
    }
    for (int v : stk) {
      ans[v] = res;
    }
  }
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y = (y % MOD + MOD) % MOD;
    cout << ans[y * n + x] << '\n';
  }


  return 0;
}