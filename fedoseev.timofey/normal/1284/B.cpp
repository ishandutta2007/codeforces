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
#include <cassert>
#include <complex>
 
using namespace std;
 
typedef long long ll;

const int Inf = 1e9;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <vector <int>> a(n);
  vector <bool> ok(n);
  vector <int> mn(n, Inf), mx(n, -Inf);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    a[i].resize(k);
    int cmin = Inf;
    for (int j = 0; j < k; ++j) {
      cin >> a[i][j];
      mn[i] = min(mn[i], a[i][j]);
      mx[i] = max(mx[i], a[i][j]);
      cmin = min(cmin, a[i][j]);
      if (cmin < a[i][j]) {
        ok[i] = true;
      }
    }
  }
  ll ans = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (ok[i]) {
      ++cnt;
    }
  }
  ans = (ll)cnt * 2 * n;
  ans -= (ll)cnt * cnt;
  vector <int> mxs;
  for (int i = 0; i < n; ++i) {
    if (!ok[i]) {
      mxs.push_back(mx[i]);
    }
  }
  sort(mxs.begin(), mxs.end());
  for (int i = 0; i < n; ++i) {
    if (!ok[i]) {
      ans += mxs.end() - upper_bound(mxs.begin(), mxs.end(), mn[i]);
    }
  }
  cout << ans << '\n';
}