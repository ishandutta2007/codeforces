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
#include <cassert>
#include <complex>
#include <functional>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const ld pi = acos(-1);

struct point {
  ll x, y;
  point() : x(0), y(0) {}
  point(ll x, ll y) : x(x), y(y) {}
};

point operator -(point a, point b) {
  return point(a.x - b.x, a.y - b.y);
}

ll operator %(point a, point b) {
  return a.x * b.y - a.y * b.x;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <point> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (ll)(n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
    vector <pair <ld, int>> cr;
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        int dx = a[j].x - a[i].x;
        int dy = a[j].y - a[i].y;
        cr.push_back({atan2(dy, dx), j});
      }
    }
    sort(cr.begin(), cr.end());
    vector <int> go;
    for (auto pr : cr) go.push_back(pr.second);
    for (auto pr : cr) go.push_back(pr.second);
    int uk = 0;
    for (int j = 0; j < (int)cr.size(); ++j) {
      uk = max(uk, j);
      while (uk < j + cr.size() && ((a[go[j]] - a[i]) % (a[go[uk]] - a[i])) >= 0) ++uk;
      int cnt = uk - j - 1;
      ans -= (ll)cnt * (cnt - 1) * (cnt - 2) / 6;
    }
  }
  cout << ans << '\n';
}