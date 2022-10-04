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
    vector <int> xs, ys;
    for (int i = 0; i < 2 * n; ++i) {
      int x, y;
      cin >> x >> y;
      if (x == 0) ys.push_back(abs(y));
      else xs.push_back(abs(x));
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    double ans = 8e18;
    for (int rot = 0; rot <= 1; ++rot) {
      double cur = 0;
      for (int i = 0; i < n; ++i) {
        cur += sqrt((ll)xs[i] * xs[i] + (ll)ys[i] * ys[i]);
      }         
      ans = min(ans, cur);
      reverse(xs.begin(), xs.end());
    }
    cout << fixed << setprecision(20) << ans << '\n';
  }
}