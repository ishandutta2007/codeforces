#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <ll> l(n), r(n);
  for (int i = 0; i < n; i++)
    cin >> l[i] >> r[i];
  vector <pair <ll, pair <ll, ll>>> scanline; // 0: open, 1: point, 2: close
  for (int i = 0; i + 1 < n; i++) {
    ll mi = (l[i + 1] - r[i]);
    ll ma = (r[i + 1] - l[i]);
    scanline.push_back({mi, {0, i}});
    scanline.push_back({ma, {2, i}});
  }
  for (int i = 0; i < m; i++) {
    ll x;
    cin >> x;
    scanline.push_back({x, {1, i}});
  }
  set <pair <ll, ll>> s;
  vector <int> ans(n - 1, -1);
  sort(scanline.begin(), scanline.end());
  for (auto &now : scanline) {
    ll x = now.first, type = now.second.first, id = now.second.second;
    if (type == 0)
      s.insert({r[id + 1] - l[id], id});
    if (type == 1) {
      if (s.empty()) continue;
      auto tmp = *s.begin();
      ans[tmp.second] = id;
      s.erase(tmp);
    }
    if (type == 2)
      s.erase({r[id + 1] - l[id], id});
  }
  for (int i = 0; i + 1 < n; i++)
    if (ans[i] == -1) {
      cout << "No\n";
      return 0;
    }
  cout << "Yes\n";
  for (int i = 0; i + 1 < n; i++)
    cout << ans[i] + 1 << ' ';
  return 0;
}