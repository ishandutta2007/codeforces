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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i + 1 < k; ++i) {
      int mn = 9, mx = 0;
      ll cn = n;
      while (cn > 0) {
        int d = cn % 10;
        cn /= 10;
        mn = min(mn, d);
        mx = max(mx, d);
      }
      n += mn * mx;
      if (mn == 0) break;
    }
    cout << n << '\n';
  }
}