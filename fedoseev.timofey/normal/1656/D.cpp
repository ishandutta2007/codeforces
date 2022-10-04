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


/*0 + 1 + 2 + ... + k - 1

(k - 1) * k / 2

n - (k - 1) * k / 2 mod k == 0*/
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll good = -1;
    auto check = [&](ll k) {
      const ll Inf = 3e9;
      if (1 < k && k < Inf && k * (k - 1) / 2 < n && (n - (k - 1) * k / 2) % k == 0) {
        good = k;
      }
    };
    for (ll k = 2; k <= 100; ++k) {
      check(k);
    }
    ll x = 1;
    {
      ll tn = n;
      while (tn % 2 == 0) {
        tn /= 2;
        x *= 2;
      }
    }
    check(2 * x);
    check(2 * n / (2 * x));
    cout << good << '\n';
  }



  // n = l * (2s - 1)
  // k = 2 * l
  // (k - 1) * k / 2 = (2l - 1) * l = 2l^2 - l = k / 2
  // k = 2 * l + 1
  // (k - 1) * k / 2 = 2l * (2l + 1) ---> k | n
  /*for (int n = 2; n <= 100000; ++n) {
    cout << n << ' ';
    for (int k = 2; k * (k - 1) / 2 <= n; ++k) {
      if ((n - (k - 1) * k / 2) % k == 0) {
        cout << k << ' ';
      }
    }
    cout << '\n';
  }*/
}