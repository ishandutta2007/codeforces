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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    bool good = false;
    int cnt = 0;
    int mn = 1e9;
    for (int i = 0; i < n; ++i) {
      int lcnt = cnt;
      if (a[i] >= k) ++cnt;
      else --cnt;
      if (cnt - mn > 0) {
        good = true;
      }
      mn = min(mn, lcnt);
    }
    cnt = 0;
    mn = 1e9;
    for (int i = n - 1; i >= 0; --i) {
      int lcnt = cnt;
      if (a[i] >= k) ++cnt;
      else --cnt;
      if (cnt - mn > 0) {
        good = true;
      }
      mn = min(mn, lcnt);
    }
    bool fnd = false;
    for (int i = 0; i < n; ++i) fnd |= (a[i] == k);
    if (!fnd) good = false;
    if (n == 1 && a[0] == k) good = true;
    cout << (good ? "Yes" : "No") << '\n';
  }
}