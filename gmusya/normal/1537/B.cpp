#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll dist(ll x1, ll y1, ll x2, ll y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    vector <pair <ll, ll>> a = {{1, 1}, {1, m}, {n, 1}, {n, m}};
    pair <ll, pair <ll, ll>> ans = {-1, {0, 0}};
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        ll var1 = dist(sx, sy, a[i].first, a[i].second) + dist(a[i].first, a[i].second, a[j].first, a[j].second);
        ll var2 = dist(sx, sy, a[j].first, a[j].second) + dist(a[i].first, a[i].second, a[j].first, a[j].second);
        ll dist = min(var1, var2);
        ans = max(ans, {dist, {i, j}});
      }
    }
    cout << a[ans.second.first].first << ' ' << a[ans.second.first].second << ' ' << a[ans.second.second].first << ' ' << a[ans.second.second].second << '\n';
  }
  return 0;
}