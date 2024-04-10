#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  const auto Query = [&](int x, int y) {
    cout << "SCAN " << x << ' ' << y << endl;
    int t;
    cin >> t;
    return t;
  };

  int T;
  cin >> T;
  while (T--) {
    map<pair<int, int>, int> checked;
    const auto Check = [&](int x, int y) {
      if (checked.count({x, y})) return checked[{x, y}];
      cout << "DIG " << x << ' ' << y << endl;
      int t;
      cin >> t;
      return checked[{x, y}] = t;
    };
    int n, m;
    cin >> n >> m;
    int p = Query(1, 1);
    int q = Query(n, 1);
    int yy = (p + q - n - n + 6) / 2;
    int xx = (p - q + n + n + 2) / 2;
    int t2 = Query(xx / 2, 1);
    int t3 = Query(1, yy / 2);
    vector<array<int, 3>> done;
    done.push_back({1, 1, p});
    done.push_back({n, 1, q});
    done.push_back({xx / 2, 1, t2});
    done.push_back({1, yy / 2, t3});
    vector<array<int, 4>> all;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int ii = 1; ii <= n; ii++) {
          for (int jj = 1; jj <= m; jj++) {
            if (pair(i, j) < pair(ii, jj)) {
              int bad = 0;
              for (auto [x, y, t] : done) {
                if (abs(i - x) + abs(ii - x) + abs(j - y) + abs(jj - y) != t) {
                  bad = 1;
                }
              }
              if (bad) {
                continue;
              }
              all.push_back({i, j, ii, jj});
            }
          }
        }
      }
    }
    set<int> xs, ys;
    for (auto [a, b, c, d] : all) {
      xs.emplace(a);
      xs.emplace(c);
      ys.emplace(b);
      ys.emplace(d);
    }
    int qx = *begin(xs);
    int qy = *begin(ys);
    assert(xs.size() <= 2 && ys.size() <= 2);
    int rrr = Check(qx, qy);
    vector<array<int, 4>> ans;
    for (auto [a, b, c, d] : all) {
      if (rrr == 0) {
        if ((a == qx && b == qy) || (c == qx && d == qy)) {
          continue;
        }
        ans.push_back({a, b, c, d});
      } else {
        if ((a == qx && b == qy) || (c == qx && d == qy)) {
          ans.push_back({a, b, c, d});
        }
      }
    }
    assert(ans.size() == 1);
    Check(ans[0][0], ans[0][1]);
    Check(ans[0][2], ans[0][3]);
  }

  return 0;

  int n, m;
  cin >> n >> m;

  vector<array<int, 4>> all;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int ii = 1; ii <= n; ii++) {
        for (int jj = 1; jj <= m; jj++) {
          if (pair(i, j) < pair(ii, jj)) {
            all.push_back({i, j, ii, jj});
          }
        }
      }
    }
  }
  vector<pair<int, int>> trial;
  trial.push_back({1, 1});
  trial.push_back({n, 1});
  trial.push_back({-1, -1});
  trial.push_back({-1, -1});
  vector<array<int, 4>> queries;
  map<pair<vector<array<int, 4>>, int>, array<int, 3>> opt;
  const auto Dfs = [&](const auto &self, vector<array<int, 4>> pos, int step, int trace) {
    if (step == 5) return pos.size() <= 1;
    if (pos.size() == 1) return true;
    if (pos.empty()) return true;
    if (trace == 0 && opt.count({pos, step})) return opt[{pos, step}][0] != -1;
    if (!trace) {
      opt[{pos, step}] = {-1, -1, -1};
    }
    if (1)
      if (step == 2) {
        // x1 + x2 + y1 + y2 - 4 = p
        // 2n - x1 - x2 + y1 + y2 - 2 = q
        // 2n - 6 + 2y1 + 2y2 = p + q
        // 2x1 + 2x2 - 2n - 2 = p - q
        assert(queries.size() == 2);
        int p = queries[0][3];
        int q = queries[1][3];
        int yy = (p + q - n - n + 6) / 2;
        int xx = (p - q + n + n + 2) / 2;
        trial[2] = {xx / 2, 1};
        trial[3] = {1, yy / 2};
        // cout << "OK\n";
        for (auto [a, b, c, d] : pos) {
          assert(a + c == xx);
          assert(b + d == yy);
        }
      }
    auto o = opt[{pos, step}];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (trace == 1 && o != array<int, 3>{1, i, j}) continue;
        if (step < trial.size() && trial[step] != pair(i, j)) continue;
        vector<vector<array<int, 4>>> group(n + m + n + m + 1);
        for (auto [a, b, c, d] : pos) {
          int t = abs(a - i) + abs(b - j) + abs(c - i) + abs(d - j);
          assert(t < group.size());
          group[t].push_back({a, b, c, d});
        }
        int bad = 0;
        for (int gg = 0; gg < group.size(); gg++) {
          auto g = group[gg];
          // if (bad) {
          //   continue;
          // }
          queries.push_back({1, i, j, gg});
          if (!self(self, g, step + 1, trace)) {
            bad = 1;
          }
          queries.pop_back();
        }
        if (!bad) {
          if (trace) {
            if (step == 3) {
              // for (auto [a, b, c, d] : pos) cout << b + d << " ha\n";
              // cout << trial[3].first << ' ' << trial[3].second << '\n';
              // cout << step << ": " << 1 << ' ' << i << ' ' << j << '\n';
            }
          } else {
            opt[{pos, step}] = {1, i, j};
          }
          return true;
        }
      }
    }
    if (step == 4)
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (trace == 1 && o != array<int, 3>{0, i, j}) continue;
          if (step < trial.size()) continue;
          vector<vector<array<int, 4>>> group(2);
          for (auto [a, b, c, d] : pos) {
            if ((a == i && b == j) || (c == i && d == j)) {
              group[1].push_back({a, b, c, d});
            } else {
              group[0].push_back({a, b, c, d});
            }
          }
          if (group[1] == pos) continue;
          queries.push_back({0, i, j, 0});
          auto t0 = self(self, group[0], step + 1, trace);
          queries.pop_back();
          queries.push_back({0, i, j, 1});
          auto t1 = self(self, group[1], step, trace);
          queries.pop_back();
          if (t0 && t1) {
            if (trace) {
              cout << step << ": " << 0 << ' ' << i << ' ' << j << '\n';
            } else {
              opt[{pos, step}] = {0, i, j};
            }
            return true;
          }
        }
      }
    return false;
  };

  cout << Dfs(Dfs, all, 0, 0) << '\n';
  // Dfs(Dfs, all, 0, 1);
  return 0;
}