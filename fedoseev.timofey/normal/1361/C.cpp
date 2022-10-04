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
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
  }
  for (int k = 20; k >= 0; --k) {
    int md = (1 << k);
    vector <vector <int>> who(md);
    for (int i = 0; i < 2 * n; ++i) {
      who[a[i] % md].push_back(i);
    }
    bool bad = false;
    for (int i = 0; i < md; ++i) {
      if (who[i].size() % 2 == 1) {
        bad = true;
        break;
      }
    }
    if (bad) continue;
    vector <int> where(2 * n);
    for (int i = 0; i < md; ++i) {
      for (int id : who[i]) {
        where[id] = i;
      }
    }
    vector <int> par(2 * n), sz(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
      par[i] = i;
      sz[i] = 1;
    }
 
    int cmp_cnt = 2 * n;
 
    function <int(int)> get = [&] (int a) {
      return (a == par[a] ? a : par[a] = get(par[a]));
    };
 
    auto join = [&] (int a, int b) {
      a = get(a);
      b = get(b);
      if (a != b) {
        --cmp_cnt;
        if (sz[a] > sz[b]) swap(a, b);
        par[a] = b;
        sz[b] += sz[a];
      }
    };
    for (int i = 0; i < 2 * n; i += 2) join(i, i + 1);
    vector <int> pr(2 * n);
    for (int i = 0; i < md; ++i) {
      for (int j = 0; j < (int)who[i].size(); j += 2) {
        pr[who[i][j]] = who[i][j + 1];
        pr[who[i][j + 1]] = who[i][j];
        join(who[i][j], who[i][j + 1]);
      }
    }
 
    for (int i = 0; i < md; ++i) {
      if (who[i].empty()) continue;
      int w = who[i][0];
      for (int j = 1; j < (int)who[i].size(); ++j) {
        int u = who[i][j];
        int v = w;
        int cu = get(u);
        int cv = get(v);
        if (cu != cv) {
          join(u, v);
          int pu = pr[u], pv = pr[v];
          pr[u] = v;
          pr[v] = u;
          pr[pu] = pv;
          pr[pv] = pu;
          w = v;
        }
      }
    }
    if (cmp_cnt != 1) continue;
    vector <int> p;
    int id = 0;
    vector <int> used(2 * n);
    while (!used[id]) {
      used[id] = used[id ^ 1] = 1;
      p.push_back(id);
      p.push_back(id ^ 1);
      id = pr[id ^ 1];
    }
    for (int i = 1; i < 2 * n; i += 2) {
      int j = (i + 1) % (2 * n);
      if (a[p[i]] % md != a[p[j]] % md) {
        bad = true;
        break;
      }
    }
    cout << k << '\n';
    for (int id : p) {
      cout << id + 1 << ' ';
    }
    cout << '\n';
    return 0;
  }
}