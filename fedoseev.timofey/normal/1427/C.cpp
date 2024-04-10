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

const int Inf = 1e9;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int r, n;
  cin >> r >> n;
  vector <int> t(n + 1), x(n + 1), y(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> t[i] >> x[i] >> y[i];
  }
  x[0] = 1, y[0] = 1;
  vector <int> dp(n + 1, -Inf), pmax(n + 1, -Inf);
  dp[0] = 0;
  pmax[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int pr = max(0, i - 2 * r);
    for (int j = i - 1; j >= pr; --j) {
      int d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
      if (d <= t[i] - t[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    if (pr > 0) dp[i] = max(dp[i], pmax[pr - 1] + 1);
    pmax[i] = max(pmax[i - 1], dp[i]);
  }
  cout << pmax[n] << '\n';
}