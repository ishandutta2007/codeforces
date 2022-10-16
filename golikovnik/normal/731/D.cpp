#include <bits/stdc++.h>

using i64 = int64_t;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, c;
  cin >> n >> c;
  vector<vector<int>> a(n);
  for (auto& v : a) {
    int x;
    cin >> x;
    v.resize(x);
    for (auto& y : v) cin >> y;
  }
  vector<pair<int, int>> events;
  auto add_seg = [&](int l, int r, int i) {
    events.emplace_back(l, ~i);
    events.emplace_back(r, i);
  };
  int ns = 0;
  for (int i = 0; i + 1 < n; ++i) {
    auto& x = a[i];
    auto& y = a[i + 1];
    int sx = (int) x.size();
    int sy = (int) y.size();
    auto[it_x, it_y] = mismatch(x.begin(), x.end(), y.begin());
    if (it_x == x.end() || it_y == y.end()) {
      if (sx <= sy) continue;
      cout << -1 << '\n';
      return 0;
    }
    auto cx = *it_x;
    auto cy = *it_y;
    if (cx < cy) {
      add_seg(0, c - cy, i);
      add_seg(c - cx + 1, c - 1, i);
    } else {
      add_seg(c - cx + 1, c - cy, i);
    }
    ++ns;
  }
  if (events.empty()) {
    cout << 0 << '\n';
    return 0;
  }
  sort(events.begin(), events.end());
  int cnt = 0;
  for (auto[x, i] : events) {
    if (i < 0) {
      ++cnt;
      if (cnt == ns) {
        cout << x << '\n';
        return 0;
      }
    } else {
      --cnt;
    }
  }
  cout << -1 << '\n';
  return 0;
}