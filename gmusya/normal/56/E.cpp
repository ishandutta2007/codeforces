#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segment_tree {
  int n;
  vector <int> left, right, t;
  segment_tree(int _n) {
    n = _n;
    left.push_back(-1);
    right.push_back(-1);
    t.push_back(-1);
  }
  void push(int v) {
    if (left[v] == -1) {
      left[v] = left.size();
      left.push_back(-1);
      right.push_back(-1);
      t.push_back(-1);
      right[v] = right.size();
      left.push_back(-1);
      right.push_back(-1);
      t.push_back(-1);
    }
  }
  void update(int v, int tl, int tr, int pos, int x) {
    if (tl == tr) {
      t[v] = x;
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(left[v], tl, tm, pos, x);
    else
      update(right[v], tm + 1, tr, pos, x);
    t[v] = max(t[left[v]], t[right[v]]);
  }
  void update(int pos, int x) {
    update(0, 0, n - 1, pos, x);
  }
  int get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return -1;
    if (l == tl && r == tr)
      return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    int x = get(left[v], tl, tm, l, min(r, tm));
    int y = get(right[v], tm + 1, tr, max(l, tm + 1), r);
    return max(x, y);
  }
  int get(int l, int r) {
    return get(0, 0, n - 1, l, r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <pair <pair <int, int>, int>> q(n);
  for (int i = 0; i < n; i++) {
    cin >> q[i].first.first >> q[i].first.second;
    q[i].first.first += 1e8;
    q[i].second = i;
  }
  sort(q.begin(), q.end());
  vector <int> answer(n);
  segment_tree se(3e8+5);
  for (int i = n - 1; i >= 0; i--) {
    int x = q[i].first.first, h = q[i].first.second;
    int ans = max(i, se.get(x + 1, x + h - 1));
    se.update(x, ans);
    answer[q[i].second] = ans - i + 1;
  }
  for (auto &now : answer)
    cout << now << ' ';
  return 0;
}