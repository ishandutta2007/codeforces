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

const ll Inf = 1e18;

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
    vector <int> a(n), b(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
      ans += (ll)(k - 1) * b[i];
    }
    vector <int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&] (int i, int j) {
      return b[i] < b[j];
    });
    vector <vector <ll>> dp(n + 1, vector <ll> (k + 1, -Inf));
    vector <vector <int>> p(n + 1, vector <int> (k + 1, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= k; ++j) {
        dp[i][j] = dp[i - 1][j];
        p[i][j] = 0;
        if (j > 0) {
          if (dp[i - 1][j - 1] + a[id[i - 1]] - (ll)b[id[i - 1]] * (k - j) > dp[i][j]) {
            dp[i][j] = dp[i - 1][j - 1] + a[id[i - 1]] - (ll)b[id[i - 1]] * (k - j);
            p[i][j] = 1;
          }
        }
      }
    }
    vector <int> who;
    int j = k;
    for (int i = n; i >= 1; --i) {
      if (p[i][j]) {
        who.push_back(id[i - 1]);
        --j;
      }
    }
    reverse(who.begin(), who.end());
    vector <int> used(n);
    for (int i : who) used[i] = true;
    cout << (int)who.size() + 2 * (n - (int)who.size()) << '\n';
    for (int i = 0; i + 1 < (int)who.size(); ++i) {
      cout << who[i] + 1 << ' ';
    }
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        cout << i + 1 << ' ' << -(i + 1) << ' ';
      }
    }
    cout << who.back() + 1 << '\n';
  }
}