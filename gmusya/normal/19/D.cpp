#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct segment_tree {
  int n;
  vector <int> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
  }
  void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
      t[v] = val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, val);
    else
      update(v * 2 + 1, tm + 1, tr, pos, val);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
  int get(int v, int tl, int tr, int l, int val) {
    if (tr < l)
      return -1;
    if (t[v] <= val)
      return -1;
    if (tl == tr)
      return tl;
    int tm = (tl + tr) / 2;
    int ans = get(v * 2, tl, tm, l, val);
    if (ans != -1)
      return ans;
    return get(v * 2 + 1, tm + 1, tr, l, val);
  }
  void update(int pos, int val) {
    update(1, 0, n - 1, pos, val);
  }
  int get(int l, int val) {
    return get(1, 0, n - 1, l, val);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> xm, ym;
  map <int, int> mx, my;
  vector <pair <int, pair <int, int>>> q(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "add")
      q[i].first = 0;
    if (s == "find")
      q[i].first = 1;
    if (s == "remove")
      q[i].first = 2;
    cin >> q[i].second.first >> q[i].second.second;
    mx[q[i].second.first] = 0, my[q[i].second.second] = 0;
  }
  int cnt = 0;
  for (auto &now : mx) {
    xm.push_back(now.first);
    now.second = cnt++;
  }
  cnt = 0;
  for (auto &now : my) {
    ym.push_back(now.first);
    now.second = cnt++;
  }
  for (int i = 0; i < n; i++) {
    q[i].second.first = mx[q[i].second.first];
    q[i].second.second = my[q[i].second.second];
  }
  vector <multiset <int>> ms(xm.size());
  segment_tree se(mx.size() + 1);
  for (int i = 0; i < n; i++) {
    int x = q[i].second.first, y = q[i].second.second;
    if (q[i].first == 0) {
      ms[x].insert(y);
      se.update(x, *ms[x].rbegin());
    }
    if (q[i].first == 1) {
      int ansx = se.get(x + 1, y);
      if (ansx == -1)
        cout << -1 << '\n';
      else {
        int ansy = *ms[ansx].lower_bound(y + 1);
        cout << xm[ansx] << ' ' << ym[ansy] << '\n';
      }
    }
    if (q[i].first == 2) {
      ms[x].erase(ms[x].find(y));
      if (!ms[x].empty())
        se.update(x, *ms[x].rbegin());
      else
        se.update(x, 0);
    }
  }
  return 0;
}