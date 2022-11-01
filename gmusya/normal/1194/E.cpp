#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

struct fenwick_tree {
  int n;
  vector <int> t;
  fenwick_tree(int _n) {
    n = _n;
    t.resize(n);
  }
  void upd(int pos, int val) {
    while (pos < n) {
      t[pos] += val;
      pos |= pos + 1;
    }
  }
  int get(int pos) {
    int res = 0;
    if (pos >= n)
      pos = n - 1;
    while (pos > -1) {
      res += t[pos];
      pos &= pos + 1;
      pos--;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <pair <int, pii>> vert, hori;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 5000, y1 += 5000, x2 += 5000, y2 += 5000;
    if (x2 < x1)
      swap(x1, x2);
    if (y2 < y1)
      swap(y1, y2);
    if (x1 == x2)
      vert.push_back({x1, {y1, y2}});
    else
      hori.push_back({y1, {x1, x2}});
  }
  ll ans = 0;
  for (auto &now : vert) {
    vector <pair <int, pii>> scanline;
    for (int i = 0; i < (int)vert.size(); i++) {
      pair <int, pii> tmp = vert[i];
      if (tmp.fi <= now.fi)
        continue;
      scanline.push_back({tmp.fi, {0, i}});
    }
    int cnt = 0;
    fenwick_tree ft(now.se.se - now.se.fi + 1);
    for (int i = 0; i < (int)hori.size(); i++) {
      pair <int, pii> tmp = hori[i];
      if (tmp.fi < now.se.fi || tmp.fi > now.se.se)
        continue;
      if (tmp.se.fi > now.fi || tmp.se.se <= now.fi)
        continue;
      scanline.push_back({tmp.se.se, {1, i}});
      ft.upd(tmp.fi - now.se.fi, 1);
      cnt++;
    }
    sort(scanline.begin(), scanline.end());
    for (auto &tmp : scanline) {
      if (tmp.se.fi == 0) {
        int y1 = vert[tmp.se.se].se.fi;
        int y2 = vert[tmp.se.se].se.se;
        int val = ft.get(y2 - now.se.fi) - ft.get(y1 - now.se.fi - 1);
        ans += val * (val - 1) / 2;
      } else {
        int y = hori[tmp.se.se].fi;
        ft.upd(y - now.se.fi, -1);
      }
    }
  }
  cout << ans;
  return 0;
}