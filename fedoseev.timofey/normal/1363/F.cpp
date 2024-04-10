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

const int Inf = 1e9;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    string ss = s, tt = t;
    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());
    if (ss != tt) {
      cout << "-1\n";
      continue;
    }
    vector <int> cnt(26);
    int uk = 0;
    vector <int> mn(n);
    for (int i = 0; i < n; ++i) {
      while (uk < n && cnt[s[i] - 'a'] == 0) {
        ++cnt[t[uk] - 'a'];
        ++uk;
      }
      if (cnt[s[i] - 'a'] == 0) {
        mn[i] = n;
      } else {
        --cnt[s[i] - 'a'];
        mn[i] = uk - 1;
      }
    }
    vector <vector <int>> nxt(n, vector <int> (26, n));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < 26; ++j) {
        if (i + 1 < n) {
          nxt[i][j] = nxt[i + 1][j];
        }
      }
      nxt[i][t[i] - 'a'] = i;
    }

    vector <vector <int>> dp(n, vector <int> (n, -Inf));
    for (int i = 0; i < n; ++i) {
      if (s[0] == t[i]) {
        dp[0][i] = 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (nxt[j][t[j] - 'a'] != n) {
          dp[i][nxt[j][t[j] - 'a']] = max(dp[i][nxt[j][t[j] - 'a']], dp[i][j]);
        }
        if (i + 1 < n && mn[i + 1] <= j) {
          dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
        if (i + 1 < n && j + 1 < n) {
          int id = nxt[j + 1][s[i + 1] - 'a'];
          if (id < n) dp[i + 1][id] = max(dp[i + 1][id], dp[i][j] + 1);
        }
      }
    }
    cout << n - dp[n - 1][n - 1] << '\n'; 
  }
}