/*
 * author:  ADMathNoob
 * created: 05/02/21 10:34:14
 * problem: https://codeforces.com/contest/1515/problem/G
 */

/*
g++ 1515G.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1515G.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -O3


*/

#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int M = 200005;

int n, m;
vector<int> g[N];
int from[M], to[M], cost[M];

bool was[N];
int pre[N];
vector<int> order;
long long dist[N];
int low[N];

int cnt;
bool on_stk[N];
vector<int> stk;
int comp[N];
vector<long long> cycle_lengths[N];
long long comp_gcd[N];

void Dfs(int v) {
  pre[v] = low[v] = (int) order.size();
  order.push_back(v);
  stk.push_back(v);
  on_stk[v] = true;
  for (int id : g[v]) {
    assert(v == from[id]);
    int u = to[id];
    if (was[u]) {
      if (on_stk[u]) {
        // back edge
        low[v] = min(low[v], pre[u]);
        long long len = dist[v] - dist[u] + cost[id];
        // if (len <= 0) {
        //   cerr << v << ' ' << u << ' ' << len << '\n';
        //   for (int i : stk) cerr << i << ' ';
        //   cerr << '\n';
        // }
        len = abs(len);
        cycle_lengths[u].push_back(len);
      }
      continue;
    }
    was[u] = true;
    dist[u] = dist[v] + cost[id];
    Dfs(u);
    low[v] = min(low[v], low[u]);
  }
  if (low[v] == pre[v]) {
    // cerr << v << " is root\n";
    int u;
    do {
      u = stk.back();
      stk.pop_back();
      on_stk[u] = false;
      comp[u] = cnt;
    } while (u != v);
    cnt += 1;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> from[i] >> to[i] >> cost[i];
    --from[i];
    --to[i];
    g[from[i]].push_back(i);
  }
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      was[i] = true;
      dist[i] = 0;
      Dfs(i);
    }
  }
  for (int i = 0; i < n; i++) {
    for (long long x : cycle_lengths[i]) {
      comp_gcd[comp[i]] = __gcd(comp_gcd[comp[i]], x);
    }
  }

  // for (int i : order) {
  //   cerr << i << ' ';
  // }
  // cerr << '\n';
  // for (int i = 0; i < n; i++) {
  //   cerr << comp[i] << ' ';
  // }
  // cerr << '\n';
  // for (int c = 0; c < cnt; c++) {
  //   cerr << "gcd of component " << c << ": " << comp_gcd[c] << '\n';
  // }

  int tt;
  cin >> tt;
  while (tt--) {
    int start;
    long long b, md;
    cin >> start >> b >> md;
    --start;
    b = (md - b) % md;
    long long a = comp_gcd[comp[start]];
    // is there a solution x to ax = b (mod md)?
    long long g = __gcd(a, __gcd(b, md));
    a /= g;
    b /= g;
    md /= g;
    bool ok = (__gcd(a, md) == 1);
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}