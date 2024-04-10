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

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, sx, sy;
  cin >> n >> sx >> sy;
  vector <int> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  int best = -1;
  int ax = -1, ay = -1;
  auto check = [&] (int x1, int y1) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int d = abs(sx - x[i]) + abs(sy - y[i]);
      int cd = abs(sx - x1) + abs(sy - y1) + abs(x1 - x[i]) + abs(y1 - y[i]);
      if (cd == d) ++cnt;
    }
    if (cnt > best) {
      best = cnt;
      ax = x1;
      ay = y1;
    }
  };
  check(sx, sy - 1);
  check(sx, sy + 1);
  check(sx - 1, sy);
  check(sx + 1, sy);
  cout << best << '\n' << ax << ' ' << ay << '\n';
}