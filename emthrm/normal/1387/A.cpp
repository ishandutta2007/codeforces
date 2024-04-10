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
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  map<pair<int, int>, int> mp;
  while (m--) {
    int a, b, c; cin >> a >> b >> c; --a; --b;
    if (a > b) swap(a, b);
    if (mp.count({a, b}) == 1) {
      if (mp[{a, b}] != c) {
        cout << "NO\n";
        return 0;
      }
    } else {
      mp[{a, b}] = c;
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
    }
  }
  vector ans(n, 0.0);
  vector visited(n, false);
  REP(i, n) {
    if (visited[i] || graph[i].empty()) continue;
    map<int, pair<int, bool>> val;
    val[i] = {0, true};
    int num, den;
    bool is_fixed = false, ok = true;
    function<void(int, int)> dfs = [&](int par, int ver) {
      visited[ver] = true;
      for (int e : graph[ver]) {
        if (e == par) continue;
        int s = ver, t = e;
        if (s > t) swap(s, t);
        int sum = mp[{s, t}];
        if (val.count(e) == 1) {
          auto [s_c, s_x] = val[s];
          auto [t_c, t_x] = val[t];
          if (s_x != t_x) {
            if (s_c + t_c != sum) {
              ok = false;
              return;
            }
          } else {
            sum -= s_c + t_c;
            int tmp = (s_x ? 1 : -1) + (t_x ? 1 : -1);
            if (tmp < 0) {
              sum = -sum;
              tmp = -tmp;
            }
            // assert(tmp == 2);
            if (sum % 2 == 0) {
              sum >>= 1;
              tmp = 1;
            }
            if (is_fixed) {
              if (num != sum || den != tmp) {
                ok = false;
                return;
              }
            } else {
              num = sum;
              den = tmp;
              is_fixed = true;
            }
          }
        } else {
          auto [ver_c, ver_x] = val[ver];
          val[e] = {sum - ver_c, !ver_x};
          dfs(ver, e);
        }
      }
    };
    dfs(-1, i);
    if (!ok) {
      cout << "NO\n";
      return 0;
    }
    double d;
    if (!is_fixed) {
      vector<int> a;
      for (auto it = val.begin(); it != val.end(); ++it) {
        auto [l_c, l_x] = it->second;
        a.emplace_back(l_x ? -l_c : l_c);
      }
      sort(ALL(a));
      d = a[a.size() / 2];
    } else {
      d = 1.0 * num / den;
    }
    for (auto [ver, info] : val) {
      auto [c, x] = info;
      ans[ver] = c + (x ? d : -d);
    }
  }
  // for (auto [e, val] : mp) {
  //   auto [s, t] = e;
  //   assert(abs(ans[s] + ans[t] - val) < 1e-7);
  // }
  cout << "YES\n";
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
  return 0;
}