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
#include <iomanip>
#include <functional>
#include <cassert>
 
using namespace std;
 
typedef long long ll;
 
#define int long long
 
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, a, r, m;
  cin >> n >> a >> r >> m;
  m = min(m, a + r);
  vector <int> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];
  sort(h.begin(), h.end());
  ll ans = 8e18;

  ll sl = 0, sr = 0;
  for (int i = 0; i < n; ++i) sr += h[i];

  for (int i = 0; i < n; ++i) {
    ll up = (ll)h[i] * i - sl;
    ll down = sr - (ll)h[i] * (n - i);
    sl += h[i];
    sr -= h[i];
    ll go = min(up, down);
    ans = min(ans, go * m + (up - go) * a + (down - go) * r);
  }
  sl = 0, sr = 0;
  for (int i = 0; i < n; ++i) sr += h[i];

  for (int i = 0; i + 1 < n; ++i) {
    sl += h[i];
    sr -= h[i];
    int lf = h[i] - 1, rg = h[i + 1] - 1;
    while (rg - lf > 1) {
      int mid = (lf + rg) >> 1;
      ll up = (ll)mid * (i + 1) - sl;
      ll down = sr - (ll)mid * (n - i - 1);
      ll go = min(up, down);
      ans = min(ans, go * m + (up - go) * a + (down - go) * r);
      if (up >= down) rg = mid;
      else lf = mid;
    }
  }
  cout << ans << '\n';
}