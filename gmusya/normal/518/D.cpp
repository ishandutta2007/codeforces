#include <iostream>
#include <iomanip>

#define fsp(x) fixed << setprecision(x)

using namespace std;

typedef long double ld;

bool used[2001][2001];
ld dp[2001][2001];

ld p;

ld solve(int n, int t) {
  if (!n || !t)
    return 0;
  if (used[n][t])
    return dp[n][t];
  used[n][t] = true;
  return dp[n][t] = p * (solve(n - 1, t - 1) + 1) + (1 - p) * solve(n, t - 1);
}

int main() {
  for (int i = 0; i <= 2000; i++)
    for (int j = 0; j <= 2000; j++)
      used[i][j] = false;
  int n, t;
  cin >> n >> p >> t;
  cout << fsp(15) << solve(n, t);
  return 0;
}