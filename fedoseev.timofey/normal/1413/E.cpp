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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

#define int long long
 
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > (ll)b * c) {
      cout << "-1\n";
      continue;
    }
    if (d >= c) {
      cout << a << '\n';
      continue;
    } 
    int can = 1 + c / d;
    ll best = 0;
    auto relax = [&] (ll tk) {
      best = max(best, 2LL * tk * a + (ll)b * d * tk - (ll)b * d * tk * tk);
    };
    auto check = [&] (ll pt) {
      for (int dl = -2; dl <= 2; ++dl) {
        if (0 <= pt + dl && pt + dl <= can) {
          relax(pt + dl);
        }
      }
    };
    check(1);
    check(can);
    ll pt = ((ll)b * d + 2 * a) / (2LL * b * d);
    check(pt);
    cout << best / 2 << '\n';
  }
}