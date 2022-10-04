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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ok = 0;
    int xr = 0;
    for (int f = 0; f + 1 < n; ++f) {
      xr ^= a[f];
      int cur = 0;
      int fnd = 0;
      for (int i = f + 1; i < n; ++i) {
        cur ^= a[i];
        if (cur == xr) {
          cur = 0;
          fnd = 1;
        }
      }
      if (cur == 0 && fnd == 1) ok = 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}