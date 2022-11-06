#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#define MAXN 1000

using namespace std;

typedef long long lint;

struct Tarjan {
  int n, ncnt = 0, nmark = 0; vector<vector<int>> adj;
  vector<int> preorderof, cntof, stack; vector<bool> instack;
  vector<int> order;
  Tarjan(int n): n(n), adj(n), preorderof(n, -1), cntof(n, -1), instack(n, false) {}
  void solve() {
    for (int i = 0; i < n; ++i) if (preorderof[i] == -1) dfs(i);
  }
  int dfs(int v) {
    int reach = preorderof[v] = nmark++;
    stack.push_back(v); instack[v] = true;
    for (int u : adj[v])
      if (preorderof[u] == -1) reach = min(reach, dfs(u));
      else if (instack[u]) reach = min(reach, preorderof[u]);
    if (reach == preorderof[v]) {
      int u;
      do {
	u = stack.back(); stack.pop_back();
        order.push_back(u);
	instack[u] = false; cntof[u] = ncnt;
      } while (u != v);
      ++ncnt;
    }
    return reach;
  }
};

vector<int> adj[2*MAXN];

void not_both(int a, int b) {
  adj[a].push_back(b ^ 1);
  adj[b].push_back(a ^ 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> firsts(n), seconds(n);
  vector<string> opt1(n), opt2(n);
  for (int i = 0; i < n; ++i) {
    cin >> firsts[i] >> seconds[i];
    opt1[i] = firsts[i].substr(0, 3);
    opt2[i] = firsts[i].substr(0, 2) + seconds[i].substr(0, 1);
  }

  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      if (opt1[i] == opt1[j])
        not_both(2 * i, 2 * j);
      if (opt2[i] == opt1[j])
        not_both(2 * i + 1, 2 * j);
      if (opt1[i] == opt2[j])
        not_both(2 * i, 2 * j + 1);
      if (opt2[i] == opt2[j])
        not_both(2 * i + 1, 2 * j + 1);
      if (opt1[i] == opt1[j]) {
        not_both(2 * i + 1, 2 * j);
        not_both(2 * i, 2 * j + 1);
      }
    }

  Tarjan tarjan(2 * n);
  for (int i = 0; i < 2 * n; ++i)
    tarjan.adj[i] = adj[i];
  tarjan.solve();

  bool ok = true;
  for (int i = 0; i < n; ++i)
    if (tarjan.cntof[2 * i] == tarjan.cntof[2 * i + 1]) {
      ok = false;
      break;
    }
  if (!ok) cout << "NO\n";
  else {
    vector<int> result(n, -1);
    for (int i = 0; i < 2 * n; ++i) {
      int node = tarjan.order[i];
      if (result[node / 2] == -1)
        result[node / 2] = node % 2;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
      if (result[i] == 0) cout << opt1[i] << "\n";
      else cout << opt2[i] << "\n";
  }

  return 0;
}