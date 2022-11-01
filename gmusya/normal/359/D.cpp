#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 1e9;

struct segment_tree {
  int n;
  vector <int> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
  }
  void build(int v, int tl, int tr, vector <int> &a) {
    if (tl == tr) {
      t[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
  int rmq(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return INF;
    if (l == tl && r == tr)
      return t[v];
    int tm = (tl + tr) / 2;
    int x = rmq(v * 2, tl, tm, l, min(r, tm));
    int y = rmq(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return min(x, y);
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  int rmq(int l, int r) {
    return rmq(1, 0, n - 1, l, r);
  }
};

int gcd(int a, int b) {
  if (a % b) return gcd(b, a % b);
  return b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <pair <int, int>> cur;
  pair <int, vector <int>> ans = {1, vector <int>()};
  segment_tree se(n);
  se.build(a);
  for (int i = 0; i < n; i++) {
    int s = 0;
    map <int, int> ne;
    for (auto &now : cur) {
      int neg = now.first, cnt = now.second;
      s += cnt;
      int g = gcd(neg, a[i]);
      int mi = se.rmq(i - s, i);
      if (mi == g) {
        if (s + 1 == ans.first)
          ans.second.push_back(i - s);
        if (s + 1 > ans.first)
          ans = {s + 1, vector <int>(1, i - s)};
      }
      ne[g] += cnt;
    }
    ne[a[i]]++;
    if (ans.first == 1)
      ans.second.push_back(i);
    cur.resize(0);
    for (auto &now : ne)
      cur.push_back(now);
    reverse(cur.begin(), cur.end());
  }
  cout << ans.second.size() << ' ' << ans.first - 1 << '\n';
  for (auto &now : ans.second)
    cout << now + 1 << ' ';
  return 0;
}