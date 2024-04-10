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
    vector <vector <int>> ans(n, vector <int> (n));
    for (int d = 0; d < n; ++d) {
      for (int i = 0; i < n; ++i) {
        int j = (i + d) % n;
        if (k > 0) {
          ans[i][j] = 1;
          --k;
        }
      } 
    }
    int res = 0;
    {
      int mn = n, mx = 0;
      for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
          cnt += ans[i][j];
        }
        mn = min(mn, cnt);
        mx = max(mx, cnt);
      }
      res += (mx - mn) * (mx - mn);
      mn = n, mx = 0;
      for (int j = 0; j < n; ++j) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
          cnt += ans[i][j];
        }
        mn = min(mn, cnt);
        mx = max(mx, cnt);
      }
      res += (mx - mn) * (mx - mn);
    }
    cout << res << '\n';
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << ans[i][j];
      }
      cout << '\n';
    }
  }
}