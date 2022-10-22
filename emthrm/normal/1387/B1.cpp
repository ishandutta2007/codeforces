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
  vector<int> ans(n);
  iota(ALL(ans), 0);
  int total = 0;
  function<void(int, int)> dfs = [&](int par, int ver) {
    for (int e : graph[ver]) {
      if (e != par) dfs(ver, e);
    }
    if (ans[ver] == ver && par != -1) {
      total += 2;
      swap(ans[ver], ans[par]);
    }
  };
  dfs(-1, 0);
  if (ans[0] == 0) {
    total += 2;
    swap(ans[0], ans[graph[0][0]]);
  }
  REP(i, n) assert(i != ans[i]);
  cout << total << '\n';
  REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
  return 0;
}