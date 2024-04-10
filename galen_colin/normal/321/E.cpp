#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

int n, grid[4004][4004], pre[4004][4004], dp[4004][808];

int cost(int i, int j) {
  if (i == 0) return pre[j][j] / 2;
  return (pre[j][j] - pre[j][i-1] - pre[i-1][j] + pre[i-1][i-1]) / 2;
}

void div(int k, int il, int ih, int optl, int optr) {
  if (il > ih) return;
  int mid = (il + ih) / 2;
  dp[mid][k] = 1e9;
  int opt = optl;
  for (int i = max(0, optl - 1); i <= min(mid, optr + 1); i++) {
    int v = cost(i, mid);
    if (i > 0) v += dp[i - 1][k - 1];
    if (v < dp[mid][k]) {
      dp[mid][k] = v;
      opt = i;
    }
  }

  div(k, il, mid - 1, optl, opt);
  div(k, mid + 1, ih, opt, optr);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      grid[i][j] = c - '0';
    }
  }

  f0r(i, n) {
    pre[i][0] = grid[i][0];
    f1r(j, 1, n) pre[i][j] = grid[i][j] + pre[i][j-1];
  }

  f1r(i, 1, n) f0r(j, n) pre[i][j] += pre[i-1][j];

  f0r(i, n) dp[i][0] = cost(0, i);
  f1r(j, 1, k) {
    div(j, 0, n-1, 0, n-1);
  }

  cout << dp[n-1][k-1] << endl;
}