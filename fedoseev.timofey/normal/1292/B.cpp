#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
 
using namespace std;
 
typedef long long ll;

const ll LIM = 2e16;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif  
  ll x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  ll xx, yy, t;
  cin >> xx >> yy >> t;
  vector <ll> xs, ys;
  while (true) {
    xs.push_back(x0);
    ys.push_back(y0);
    x0 = x0 * ax + bx;
    y0 = y0 * ay + by;
    if (x0 > LIM || y0 > LIM) break;
  }
  auto dist = [&] (ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
  };
  int ans = 0;
  int n = xs.size();
  for (int i = 0; i < n; ++i) {
    ll cur = dist(xs[i], ys[i], xx, yy);
    if (cur > t) continue;
    ans = max(ans, 1);
    for (int j = i + 1; j < n; ++j) {
      cur += dist(xs[j], ys[j], xs[j - 1], ys[j - 1]);
      if (cur > t) break;
      ans = max(ans, j - i + 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    ll cur = dist(xs[i], ys[i], xx, yy);
    if (cur > t) continue;
    ans = max(ans, 1);
    for (int j = i - 1; j >= 0; --j) {
      cur += dist(xs[j], ys[j], xs[j + 1], ys[j + 1]);
      if (cur > t) break;
      ans = max(ans, i - j + 1);
    }
  }
  cout << ans << '\n';
}