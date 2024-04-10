#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  int mx = 0;
  {
    set<int> used;
    for (int i = 0; i < n; ++i) {
      for (int d : {-1, 0, 1}) {
        if (used.insert(a[i] + d).second) {
          mx++;
          break;
        }
      }
    }
  }
  a.erase(unique(a.begin(), a.end()), a.end());
  n = (int) a.size();
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1] + 1;
    if (i > 1 && a[i - 1] - a[i - 2] <= 2) {
      dp[i] = min(dp[i], dp[i - 2] + 1);
    }
    if (i > 2 && a[i - 1] == a[i - 2] + 1 && a[i - 2] == a[i - 3] + 1) {
      dp[i] = min(dp[i], dp[i - 3] + 1);
    }
  }
  cout << dp.back() << ' ' << mx << '\n';
  return 0;
}