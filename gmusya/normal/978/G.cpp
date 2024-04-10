#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct query {
  int x;
  int type;
  int id;
  query(int a, int b, int c) {
    x = a;
    type = b;
    id = c;
  }
};

bool cmp(query a, query b) {
  if (a.x != b.x)
    return a.x < b.x;
  return a.type < b.type;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> c(m);
  vector <int> d(m);
  vector <query> scanline;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r >> c[i];
    l--, r--;
    query tmp1(l, 0, i);
    query tmp2(r, 1, i);
    scanline.push_back(tmp1);
    scanline.push_back(tmp2);
    d[i] = r;
  }
  for (int i = 0; i < n; i++) {
    query tmp(i, 2, 0);
    scanline.push_back(tmp);
  }
  vector <int> ans(n, -1);
  set <pair <int, int>> s;
  sort(scanline.begin(), scanline.end(), cmp);
  for (auto &que : scanline) {
    int x = que.x, type = que.type, id = que.id;
    if (type == 0) {
      s.insert({d[id], id});
    }
    if (type == 1) {
      if (c[id])
        s.erase({d[id], id});
      ans[x] = m + 1;
    }
    if (type == 2) {
      if (ans[x] != -1)
        continue;
      if (s.empty())
        continue;
      id = s.begin()->second;
      ans[x] = id + 1;
      s.erase(s.begin());
      c[id]--;
      if (c[id])
        s.insert({d[id], id});
    }
  }
  for (auto &now : c)
    if (now) {
      cout << -1;
      return 0;
    }
  for (auto &now : ans)
    cout << max(0, now) << ' ';
  return 0;
}