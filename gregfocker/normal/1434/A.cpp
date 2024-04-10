#include <bits/stdc++.h>

using namespace std;

#define int long long
const int INF = (int) 2e18;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> d(6);
  for (int i = 0; i < 6; i++) {
    cin >> d[i];
  }
  int n;
  cin >> n;
  vector<int> v(n), cur(n, 0);
  vector<vector<int>> a(n, vector<int> (6, 0));
  multiset<int> lol;
  vector<int> tms;
  vector<pair<int, int>> ops;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (int j = 0; j < 6; j++) {
      a[i][j] = v[i] - d[j];
      tms.push_back(a[i][j]);
      ops.push_back({a[i][j], i});
    }
    sort(a[i].begin(), a[i].end());
    lol.insert(a[i][0]);
  }
  sort(tms.begin(), tms.end());
  sort(ops.rbegin(), ops.rend());
  int sol = INF;
  bool ok = 1;
  for (auto &it : tms) {
    while (!ops.empty() && ops.back().first < it) {
      int id = ops.back().second;
      ops.pop_back();
      lol.erase(lol.find(a[id][cur[id]]));
      cur[id]++;
      if (cur[id] == 6) {
        ok = 0;
        break;
      }
      lol.insert(a[id][cur[id]]);
    }
    if (!ok) break;
    auto big = lol.end();
    big--;
    sol = min(sol, *big - it);
  }
  cout << sol << "\n";
}