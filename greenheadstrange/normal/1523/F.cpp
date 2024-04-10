// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn (1 << 14) + 10 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T> bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b)
    return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1)
    ns = ns * a % mod;
  return ns;
}

int n, m, ans;
int x[20], y[20], reach[110];
int dp[maxn][110], act[maxn][110];
vector<array<int, 3>> task;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
  }
  for (int i = 0; i < m; i++) {
    int xb, yb, t;
    scanf("%d%d%d", &xb, &yb, &t);
    task.push_back({t, xb, yb});
  }
  sort(task.begin(), task.end());
  for (int S = 0; S < (1 << n); S++)
    for (int j = 0; j <= m; j++)
      act[S][j] = (1 << 30);
  act[0][0] = 0;
  for (int S = 0; S < (1 << n); S++) {
    for (int j = m - 1; j >= 0; j--)
      act[S][j] = min(act[S][j], act[S][j + 1]);
    for (int j = 0; j < m; j++) {
      reach[j] = 1 << 25;
      for (int k = 0; k < n; k++)
        if (S & (1 << k))
          reach[j] =
              min(reach[j], abs(x[k] - task[j][1]) + abs(y[k] - task[j][2]));
    }
    for (int j = 0; j < m; j++) {
      dp[S][j] = -(1 << 30);
      if (S == 0)
        dp[S][j] = 1;
      for (int k = 0; k <= j; k++)
        if (act[S][k] + reach[j] <= task[j][0])
          dp[S][j] = max(dp[S][j], k + 1);

      for (int k = 0; k < j; k++) {
        if (abs(task[j][1] - task[k][1]) + abs(task[j][2] - task[k][2]) <=
                task[j][0] - task[k][0] ||
            reach[j] <= task[j][0] - task[k][0]) {
          dp[S][j] = max(dp[S][j], dp[S][k] + 1);
        }
      }
      ans = max(ans, dp[S][j]);
    }
    for (int k = 0; k < n; k++)
      if ((S & (1 << k)) == 0) {
        int reach2 = (1 << 30);
        for (int j = 0; j < n; j++)
          if (S & (1 << j)) {
            reach2 = min(reach2, abs(x[j] - x[k]) + abs(y[j] - y[k]));
          }
        for (int j = 0; j < m; j++)
          if (dp[S][j] >= 0)
            act[S | (1 << k)][dp[S][j]] =
                min(act[S | (1 << k)][dp[S][j]],
                    task[j][0] +
                        min(abs(task[j][1] - x[k]) + abs(task[j][2] - y[k]),
                            reach2));
        if (S == 0)
          reach2 = 0;
        for (int j = 0; j < m; j++)
          act[S | (1 << k)][j] = min(act[S | (1 << k)][j], act[S][j] + reach2);
      }
  }
  printf("%d\n", ans);
}