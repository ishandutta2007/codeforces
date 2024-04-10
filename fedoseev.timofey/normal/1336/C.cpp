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

const int md = 998244353;

void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  vector <int> dp(m + 1);
  for (int i = 0; i <= m; ++i) dp[i] = 1;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    vector <int> ndp(m + 1);
    for (int j = 0; j <= m; ++j) {
      if (j > 0 && t[j - 1] == s[i]) {
        add(ndp[j - 1], dp[j]);
      }
      int lst = j + i;
      if (lst >= m || t[lst] == s[i]) {
        add(ndp[j], dp[j]);
      }
    }
    add(ndp[m], dp[m]);
    dp = ndp;
    if (i >= m - 1) add(ans, dp[0]);
    /*(for (int j = 0; j <= m; ++j) {
      cout << dp[j] << ' ';
    }
    cout << endl;*/
  }
  cout << ans << '\n';
}