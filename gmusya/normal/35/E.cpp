#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 1e9;

struct segment_tree {
  int n;
  vector <int> t, lk, rk;
  segment_tree(int _n) {
    n = _n;
    t.push_back(0);
    lk.push_back(-1);
    rk.push_back(-1);
  }
  void push(int v) {
    if (lk[v] == -1) {
      lk[v] = lk.size();
      lk.push_back(-1);
      rk.push_back(-1);
      t.push_back(0);
      rk[v] = rk.size();
      lk.push_back(-1);
      rk.push_back(-1);
      t.push_back(0);
    }
  }
  void update(int v, int tl, int tr, int l, int r, int val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v] = max(t[v], val);
      return;
    }
    push(v);
    int tm = tl + (tr - tl) / 2;
    update(lk[v], tl, tm, l, min(r, tm), val);
    update(rk[v], tm + 1, tr, max(l, tm + 1), r, val);
  }
  void get(int v, int tl, int tr, vector <pair <pair <int, int>, int>> &a) {
    if (lk[v] != -1) {
      int tm = tl + (tr - tl) / 2;
      t[lk[v]] = max(t[lk[v]], t[v]);
      t[rk[v]] = max(t[rk[v]], t[v]);
      get(lk[v], tl, tm, a);
      get(rk[v], tm + 1, tr, a);
      return;
    }
    if (a.empty()) {
      a.push_back({{tl, tr}, t[v]});
    } else {
      if (a.back().second == t[v])
        a.back().first.second = tr;
      else
        a.push_back({{tl, tr}, t[v]});
    }
  }
  void update(int l, int r, int val) {
    update(0, 0, n, l, r, val);
  }
  void get(vector <pair <pair <int, int>, int>> &a) {
    get(0, 0, n, a);
  }
};

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  segment_tree se(INF + INF);
  int q;
  cin >> q;
  map <int, int> mx;
  vector <pair <pair <int, int>, int>> queries(q);
  for (int i = 0; i < q; i++) {
    int h, l, r;
    cin >> h >> l >> r;
    mx[l] = mx[r] = 0;
    mx[r - 1] = 0;
    mx[l - 1] = 0;
    mx[l + 1] = 0;
    mx[r + 1] = 0;
    mx[r - 2] = 0;
    mx[l - 2] = 0;
    mx[l + 2] = 0;
    mx[r + 2] = 0;
    queries[i].first.first = l, queries[i].first.second = r, queries[i].second = h;
  }
  vector <int> xm;
  for (auto &now : mx) {
    now.second = xm.size();
    xm.push_back(now.first);
  }
  for (int i = 0; i < q; i++)
    se.update(mx[queries[i].first.first], mx[queries[i].first.second] - 1, queries[i].second);
  vector <pair <pair <int, int>, int>> a;
  se.get(a);
  for (auto &now : a) {
    now.first.second++;
    now.first.first = xm[now.first.first];
    if (now.first.second < xm.size())
      now.first.second = xm[now.first.second];
  }
  vector <pair <int, int>> ans;
  ans.push_back({a[0].first.second, a[0].second});
  for (int i = 1; i + 1 < a.size(); i++) {
    ans.push_back({a[i].first.first, a[i].second});
    ans.push_back({a[i].first.second, a[i].second});
  }
  ans.push_back({a.back().first.first, a.back().second});
  cout << ans.size() << '\n';
  for (auto &now : ans)
    cout << now.first << ' ' << now.second << "\n";
  return 0;
}