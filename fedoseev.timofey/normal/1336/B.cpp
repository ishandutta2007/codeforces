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
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector <int> a(n1), b(n2), c(n3);
    for (int i = 0; i < n1; ++i) cin >> a[i];
    for (int i = 0; i < n2; ++i) cin >> b[i];
    for (int i = 0; i < n3; ++i) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll ans = 5e18;
    auto solve = [&ans] (vector <int> a, vector <int> b, vector <int> c) {
      int n1 = a.size();
      int n2 = b.size();
      int n3 = c.size();
      for (int i = 0; i < n2; ++i) {
        auto it = upper_bound(a.begin(), a.end(), b[i]);
        auto jt = lower_bound(c.begin(), c.end(), b[i]);
        if (it != a.begin() && jt != c.end()) {
          int x = *prev(it);
          int y = b[i];
          int z = *jt;
          ans = min(ans, (ll)(x - y) * (x - y) + (ll)(y - z) * (y - z) + (ll)(x - z) * (x - z));
        }
      }
    };
    solve(a, b, c);
    solve(a, c, b);
    solve(b, a, c);
    solve(b, c, a);
    solve(c, a, b);
    solve(c, b, a);
    cout << ans << '\n';
  }
}