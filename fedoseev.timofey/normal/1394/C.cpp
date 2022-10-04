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
 
const int N = 5e5 + 7;
 
const int Inf = 1e9;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int mxx = -Inf, mnx = Inf, mxy = -Inf, mny = Inf;
  int f = -Inf, s = -Inf;
  for (int i = 0; i < n; ++i) {
    string t;
    cin >> t;
    int cb = 0, cn = 0;
    for (auto c : t) {
      if (c == 'B') ++cb;
      else ++cn;
    }
    mxx = max(mxx, cb);
    mnx = min(mnx, cb);
    mxy = max(mxy, cn);
    mny = min(mny, cn);
    f = max(f, cb - cn);
    s = max(s, -cb + cn);
  }
  int l = -1, r = 2 * N;
  int ax = -1, ay = -1;
  auto check = [&] (int m) {
    int L = f - m;
    int R = m - s;
    int lx = mxx - m;
    int rx = mnx + m;
    int ly = mxy - m;
    int ry = mny + m;
    lx = max(lx, 0);
    ly = max(ly, 0);
    bool ok = false;
    for (int x = lx; x <= rx; ++x) {
      int y = max(ly, x - R);
      if (L <= x - y && x - y <= R && ly <= y && y <= ry) {
        ok = true;
        ax = x;
        ay = y;
        break;
      }
    }
    return ok;
  };
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  check(r);
  cout << r << '\n';
  if (ax == 0 && ay == 0) {
    ax = 1;
    ay = 1;
  } 
  for (int i = 0; i < ax; ++i) cout << 'B';
  for (int i = 0; i < ay; ++i) cout << 'N';
}