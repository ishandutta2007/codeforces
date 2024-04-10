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
#include <chrono>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

vector <int> g[N];

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n;

int timer = 0;

int tin[N], tout[N];
bool used[N];
int par[N];

void dfs(int u) {
  used[u] = 1;
  tin[u] = timer++;
  for (auto v : g[u]) {
    if (!used[v]) {
      dfs(v);
      par[v] = u;
    }
  }
  tout[u] = timer++;
}

bool anc(int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}

bool ok(int u) {
  fill(used, used + n, 0);
  fill(par, par + n, -1);
  timer = 0;
  dfs(u);
  bool ok = true;
  for (int a = 0; a < n; ++a) {
    for (int b : g[a]) {
      ok &= (par[b] == a || anc(b, a));
    }
  }
  return ok;
}

vector <int> who[N];
bool good[N];

int p[N];

int get(int a) {
  return (a == p[a] ? a : p[a] = get(p[a]));
}

void join(int a, int b) {
  a = get(a);
  b = get(b);
  p[a] = b;
}

void jhfs(int u) {
  used[u] = 1;
  if (who[u].size() == 1) {
    good[u] = good[who[u][0]];
  }
  for (auto v : g[u]) {
    if (!used[v]) {
      jhfs(v);
    }
  }
}

vector <int> solve(int r) {
  fill(used, used + n, 0);
  fill(par, par + n, -1);
  timer = 0;
  dfs(r);
  for (int i = 0; i < n; ++i) p[i] = i;
  for (int a = 0; a < n; ++a) {
    for (int b : g[a]) {
      if (par[b] != a) {
        int x = get(a);
        while (!anc(x, b)) {
          who[x].push_back(b);
          if ((int)who[x].size() == 2) {
            join(x, par[x]);
          }
          x = get(par[x]);
        }
      }
    }
  }
  fill(used, used + n, 0);
  good[r] = 1;
  jhfs(r);
  vector <int> ans;
  for (int i = 0; i < n; ++i) if (good[i]) ans.push_back(i);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      g[i].clear();
      who[i].clear();
      good[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
    }
    vector <int> ck(n);
    int r = -1;
    for (int it = 0; it < min(n, 70); ++it) {
      int u = rnd() % n;
      while (ck[u]) {
        u = rnd() % n;
      }
      ck[u] = 1;
      if (ok(u)) {
        r = u;
        break;
      }
    }
    if (r == -1) {
      cout << "-1\n";
      continue;
    }
    vector <int> ans = solve(r);
    if (5 * (int)ans.size() < n) {
      cout << "-1\n";
    } else {
      for (int id : ans) {
        cout << id + 1 << ' ';
      }
      cout << '\n';
    }
  } 
}