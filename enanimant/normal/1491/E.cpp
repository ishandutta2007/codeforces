/*
 * author:  ADMathNoob
 * created: 02/28/21 08:33:49
 * problem: https://codeforces.com/contest/1491/problem/E
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1491E.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1491E.cpp -ggdb && gdb a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors 1491E.cpp && a


*/

#include <bits/stdc++.h>

using namespace std;

const int M = 27;
const int N = 200005;

int n;
vector<int> g[N];
int from[N], to[N];
bool cut[N];

int pe[N];
vector<int> order;
int sz[N];

int fib[M];
int inv[N];

void Dfs(int v, int p) {
  sz[v] = 1;
  order.push_back(v);
  for (int id : g[v]) {
    if (cut[id]) {
      continue;
    }
    int u = from[id] ^ to[id] ^ v;
    if (u == p) {
      continue;
    }
    pe[u] = id;
    Dfs(u, v);
    sz[v] += sz[u];
  }
}

void DoDfsFrom(int v) {
  pe[v] = -1;
  order.clear();
  Dfs(v, -1);
}

bool Solve(int v) {
  DoDfsFrom(v);
  if (sz[v] <= 3) {
    return true;
  }
  int f = inv[sz[v]];
  if (f == -1) {
    return false;
  }
  // assert(f >= 2);
  for (int i : order) {
    if (inv[sz[i]] != f - 1 && inv[sz[i]] != f - 2) {
      continue;
    }
    // assert(pe[i] != -1);
    cut[pe[i]] = true;
    bool r = Solve(i);
    bool s = Solve(v);
    cut[pe[i]] = false;
    if (r && s) {
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif

  fib[0] = fib[1] = 1;
  for (int i = 0; i + 2 < M; i++) {
    fib[i + 2] = fib[i + 1] + fib[i];
  }

  // for (int i = 0; i < M; i++) cerr << fib[i] << ' ';
  // cerr << '\n';

  fill(inv, inv + N, -1);
  for (int i = 1; i < M; i++) {
    inv[fib[i]] = i;
  }

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> from[i] >> to[i];
    --from[i];
    --to[i];
    g[from[i]].push_back(i);
    g[to[i]].push_back(i);
  }

  bool ans = Solve(0);
  cout << (ans ? "yes" : "no") << '\n';

  return 0;
}