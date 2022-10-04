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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      a[i] = c - '0';
    }
    for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      b[i] = c - '0';
    }

    vector <int> ans;
    function <void(int, int, int, int)> go = [&] (int l, int r, int fl, int xr) {
      if (l > r) return;
      int sz = r - l;
      if (fl == 1) {
        if ((a[l] ^ xr) == b[sz]) {
          ans.push_back(0);
          a[l] ^= 1;
        }
        ans.push_back(sz);
        go(l + 1, r, fl ^ 1, xr ^ 1);
      } else {
        if ((a[r] ^ xr) == b[sz]) {
          ans.push_back(0);
          a[r] ^= 1;
        }
        ans.push_back(sz);
        go(l, r - 1, fl ^ 1, xr ^ 1);
      }
    };
    go(0, n - 1, 1, 0);
    cout << ans.size() << ' ';
    for (int x : ans) cout << x + 1 << ' ';
    cout << endl;
  }
}