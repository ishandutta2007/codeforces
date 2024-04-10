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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <vector <int>> g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector <int> par(n);
  int timer = 0;
  vector <int> used(n);
  vector <int> tin(n), tout(n);
  vector <int> xr(n);
  function <void(int, int)> dfs = [&] (int u, int p) {
    par[u] = p;
    used[u] = 1;
    tin[u] = timer++;
    for (auto v : g[u]) {
      if (!used[v]) {
        dfs(v, u);
      }
    }
    tout[u] = timer++;
  };
  dfs(0, -1);
  auto anc = [&] (int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
  };
  int q;
  cin >> q;
  vector <vector <int>> pt(q);
  int id = 0;
  while (q--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    vector <int> pa;
    int ca = a;
    while (!anc(ca, b)) {
      pa.push_back(ca);
      xr[ca] ^= 1;
      ca = par[ca];
    }
    pa.push_back(ca);
    vector <int> pb;
    int cb = b;
    while (!anc(cb, a)) {
      pb.push_back(cb);
      xr[cb] ^= 1;
      cb = par[cb];
    }
    reverse(pb.begin(), pb.end());
    pa.insert(pa.end(), pb.begin(), pb.end());
    pt[id++] = pa;
  }
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    ok &= (xr[i] == 0);
  }
  if (ok) {
    cout << "YES\n";
    for (const auto &p : pt) {
      cout << p.size() << '\n';
      for (auto x : p) {
        cout << x + 1 << ' ';
      }
      cout << '\n';
    }
  } else {
    cout << "NO\n";
    vector <int> cnt(n);
    for (int i = 0; i < n; ++i) {
      if (xr[i]) {
        ++cnt[par[i]];
        ++cnt[i];
      }
    }
    int need = 0;
    for (int i = 0; i < n; ++i) {
      if (cnt[i] % 2 == 1) {
        ++need;
      }
    }
    cout << max(1, need / 2) << '\n';
  }
}