#include <bits/stdc++.h>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  vector<int> sub(n, 1), cen;
  ll total = 0;
  function<void(int, int)> dfs = [&](int par, int ver) {
    bool ans = true;
    for (int e : graph[ver]) {
      if (e != par) {
        dfs(ver, e);
        total += 2 * min(sub[e], n - sub[e]);
        sub[ver] += sub[e];
        ans &= sub[e] <= n / 2;
      }
    }
    if (ans && (n - sub[ver]) <= n / 2) cen.emplace_back(ver);
  };
  dfs(-1, 0);
  vector<int> ans(n);
  if (cen.size() == 1) {
    vector<int> vers;
    function<void(int, int)> dfs2 = [&](int par, int ver) {
      vers.emplace_back(ver);
      for (int e : graph[ver]) {
        if (e != par) dfs2(ver, e);
      }
    };
    for (int e : graph[cen[0]]) dfs2(cen[0], e);
    vers.emplace_back(cen[0]);
    REP(i, n) ans[vers[i]] = vers[(i + n / 2) % n];
  } else if (cen.size() == 2) {
    vector<int> u, v;
    function<void(int, int)> dfs2 = [&](int par, int ver) {
      u.emplace_back(ver);
      for (int e : graph[ver]) {
        if (e != par) dfs2(ver, e);
      }
    };
    dfs2(cen[1], cen[0]);
    function<void(int, int)> dfs3 = [&](int par, int ver) {
      v.emplace_back(ver);
      for (int e : graph[ver]) {
        if (e != par) dfs3(ver, e);
      }
    };
    dfs3(cen[0], cen[1]);
    assert(u.size() == n / 2 && v.size() == n / 2);
    REP(i, n / 2) {
      ans[u[i]] = v[i];
      ans[v[i]] = u[i];
    }
  }
  cout << total << '\n';
  REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
  return 0;
}