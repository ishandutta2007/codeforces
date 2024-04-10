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
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  /*for (ll x = 2; x <= 2000; x += 2) {
    for (ll y = x + 2; y <= 2000; y += 2) {
      bool fnd = false;
      ll tk_x = y / x;
      ll go = x * tk_x;
      ll rem = (y - go) / 2;
      ll n = y - rem;
      fnd = n % x == y % n;
      if (!fnd) {
        cout << x << ' ' << y << endl;
        for (int n = 2; n <= 2 * y; ++n) {
          if (n % x == y % n) {
            cout << n << endl;
          }
        }
        assert(false);
      }
      assert(fnd);
    }
  }
  return 0;*/
  int t;
  cin >> t;
  while (t--) {
    ll x, y;
    cin >> x >> y;
    if (x == y) {
      cout << x << '\n';
    } else if (x > y) {
      cout << x + y << '\n';
    } else {
      ll tk_x = y / x;
      ll go = x * tk_x;
      ll rem = (y - go) / 2;
      ll n = y - rem;
      cout << n << '\n';
    }
  }
}