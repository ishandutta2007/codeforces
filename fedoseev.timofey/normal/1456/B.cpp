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
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n > 100) {
    cout << "1\n";
    return 0;
  }
  int ans = n + 1;
  for (int i = 0; i + 1 < n; ++i) {
    int xr_x = 0;
    for (int x = i; x >= 0; --x) {
      xr_x ^= a[x];
      int xr_y = 0;
      for (int y = i + 1; y < n; ++y) {
        xr_y ^= a[y];
        if (xr_x > xr_y) {
          ans = min(ans, i - x + y - (i + 1));
        }
      }
    }
  }
  if (ans != n + 1) {
    cout << ans << '\n';
  } else {
    cout << "-1\n";
  } 
}