#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int64_t, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  auto const INF = numeric_limits<int64_t>::max() / 2;
  vector<int64_t> dp(n, INF);
  vector<pair<int64_t, int>> pref_min(n, {INF, -1});
  pref_min[0] = {-a[0].first, 0};
  vector<int> p(n);
  for (int i = 1; i < n; ++i) {
    if (i >= 2) {
      auto pm = pref_min[i - 2];
      dp[i] = a[i].first + pm.first;
      p[i] = pm.second;
    }
    if (dp[i - 1] == INF) {
      pref_min[i] = pref_min[i - 1];
      continue;
    }
    auto value = -a[i].first + dp[i - 1];
    pref_min[i] = min({value, i}, pref_min[i - 1]);
  }
  auto answer = dp.back();
  vector<pair<int, int>> teams;
  int right = n - 1;
  vector<int> id(n);
  int cur_id = 1;
  while (right >= 0) {
    auto left = pref_min[right - 2].second;
    teams.emplace_back(left, right);
    for (int i = left; i <= right; ++i) {
      id[a[i].second] = cur_id;
    }
    right = left - 1;
    ++cur_id;
  }
  cout << answer << ' ' << teams.size() << '\n';
  for (auto x : id) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}