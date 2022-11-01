#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segment_tree {
  vector <int> t;
  segment_tree() {
    t.resize(4e6 + 1);
  }
  void update(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) return;
    if (l == tl && r == tr) {
      t[v] += val;
      return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
  int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    int x = query(v * 2, tl, tm, l, min(r, tm));
    int y = query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
    return x + y;
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <vector <int>> open_updates(1e6 + 1), close_updates(1e6 + 1);
  vector <vector <pair <int, int>>> queries(1e6 + 1);
  int n, m;
  cin >> n >> m;
  long long ans = -(n + m + 3);
  while (n--) {
    int y, lx, rx;
    cin >> y >> lx >> rx;
    open_updates[lx].push_back(y);
    close_updates[rx].push_back(y);
  }
  while (m--) {
    int x, ly, ry;
    cin >> x >> ly >> ry;
    queries[x].push_back({ly, ry});
  }
  queries[1e6].push_back({0, 1e6});
  queries[0].push_back({0, 1e6});
  open_updates[0].push_back(0);
  open_updates[0].push_back(1e6);
  close_updates[1e6].push_back(0);
  close_updates[1e6].push_back(1e6);
  segment_tree se;
  for (int col = 0; col <= 1e6; col++) {
    for (auto &now : open_updates[col])
      se.update(1, 0, 1e6, now, now, 1);
    for (auto &now : queries[col]) 
      ans += se.query(1, 0, 1e6, now.first, now.second);
    for (auto &now : close_updates[col])
      se.update(1, 0, 1e6, now, now, -1);
  }
  cout << ans;
  return 0;
}