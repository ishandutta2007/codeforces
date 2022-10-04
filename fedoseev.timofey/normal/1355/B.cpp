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
    vector <int> e(n);
    for (int i = 0; i < n; ++i) cin >> e[i];
    sort(e.begin(), e.end());
    vector <int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1];
      if (i >= e[i - 1]) dp[i] = max(dp[i], dp[i - e[i - 1]] + 1);
    }
    cout << dp[n] << '\n';
  }
}