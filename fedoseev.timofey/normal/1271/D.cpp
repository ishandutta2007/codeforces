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

using namespace std;

typedef long long ll;

const int N = 5007;

int dp[N][N];
const int Inf = 1e9;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m, k;
  cin >> n >> m >> k;
  vector <int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
  vector <int> mx(n);
  for (int i = 0; i < n; ++i) mx[i] = i;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    mx[v] = max(mx[v], u);
  }
  vector <vector <int>> who(n);
  for (int i = 0; i < n; ++i) {
    who[mx[i]].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    sort(who[i].begin(), who[i].end(), [&] (int i, int j) {
        return c[i] > c[j];
    });
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < N; ++j) {
      dp[i][j] = -Inf;
    }
  }
  dp[0][k] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < N; ++j) {
      if (dp[i][j] == -Inf) continue;
      if (j < a[i]) continue;
      int nj = j + b[i];
      dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j]);
    }
    for (int j = 0; j < N; ++j) {
      if (dp[i + 1][j] == -Inf) continue;
      int have = 0;
      for (int cnt = 0; cnt < who[i].size(); ++cnt) {
        have += c[who[i][cnt]];
        if (j - cnt - 1 >= 0) {
          dp[i + 1][j - cnt - 1] = max(dp[i + 1][j - cnt - 1], dp[i + 1][j] + have);
        }
      }
    }
  }
  int ans = -Inf;
  for (int j = 0; j < N; ++j) ans = max(ans, dp[n][j]);
  if (ans == -Inf) cout << "-1\n";
  else cout << ans << '\n';
}