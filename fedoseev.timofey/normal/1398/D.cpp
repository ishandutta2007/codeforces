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

const int N = 207;

ll dp[N][N][N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int R, G, B;
  cin >> R >> G >> B;
  vector <int> r(R), g(G), b(B);
  for (int i = 0; i < R; ++i) cin >> r[i];
  for (int i = 0; i < G; ++i) cin >> g[i];
  for (int i = 0; i < B; ++i) cin >> b[i];
  sort(r.begin(), r.end());
  sort(g.begin(), g.end());
  sort(b.begin(), b.end());
  for (int i = R; i >= 0; --i) {
    for (int j = G; j >= 0; --j) {
      for (int k = B; k >= 0; --k) {
        if (i < R && j < G) dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j + 1][k] + r[i] * g[j]);
        if (i < R && k < B) dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j][k + 1] + r[i] * b[k]);
        if (j < G && k < B) dp[i][j][k] = max(dp[i][j][k], dp[i][j + 1][k + 1] + g[j] * b[k]);
        dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j][k]);
        dp[i][j][k] = max(dp[i][j][k], dp[i][j + 1][k]);
        dp[i][j][k] = max(dp[i][j][k], dp[i][j][k + 1]);
      } 
    }
  }
  cout << dp[0][0][0] << '\n';
}