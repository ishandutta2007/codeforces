#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2000 + 7;
const ll INF = (ll) 1e18;
int n;
int k;
int l[N];
int r[N];
int a[N];
ll dp[N];
ll sol = INF;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i] >> a[i];
    dp[i] = INF;
  }
  dp[1] = 0;
  for (int i = 1; i <= n; i++) {
    ll rem = k, cost = 0;
    for (int j = i; j <= n; j++) {
      ll cnt = max(0LL, a[j] - rem + k - 1) / k + 1;
      ll len = r[j] - l[j] + 1;
      if (cnt > len) {
        break;
      }
      rem = (rem + max(0LL, (cnt - 1)) * k) - a[j];
      cost += a[j];
      if (j == n) {
        sol = min(sol, dp[i] + cost);
      } else {
        if (l[j] + cnt - 1 < l[j + 1]) {
          dp[j + 1] = min(dp[j + 1], dp[i] + cost + rem);
        }
      }
    }
  }
  if (sol == INF) {
    sol = -1;
  }
  cout << sol << "\n";
}