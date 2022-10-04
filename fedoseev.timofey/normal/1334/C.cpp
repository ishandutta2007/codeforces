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
    int n;
    cin >> n;
    vector <ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) ans += a[i];
    ll mn = 1e18;
    for (int i = 0; i < n; ++i) {
      ll can = min(a[i], b[(i - 1 + n) % n]);
      ans -= can;
      mn = min(mn, can);
    }
    ans += mn;
    cout << ans << '\n';
  }
}