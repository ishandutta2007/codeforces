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
  int t;
  cin >> t;
  while (t--) {
    int n, u, v;
    cin >> n >> u >> v;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = u + v;
    for (int i = 0; i + 1 < n; ++i) {
      if (abs(a[i + 1] - a[i]) > 1) {
        ans = 0;
      }
    }
    set <int> gs;
    for (int i = 0; i < n; ++i) gs.insert(a[i]);
    if (gs.size() != 1) ans = min(ans, u);
    ans = min(ans, 2 * v);
    if (gs.size() != 1) ans = min(ans, v);
    cout << ans << '\n';
  }
}