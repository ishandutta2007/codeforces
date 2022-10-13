#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

long long fact(int n)
{
  return n < 2 ? 1 : fact(n - 1) * n % BASE;
}

int main()
{
  int n, T, t[55], g[55], cnt[3] = {0};
  cin >> n >> T;
  for (int i = 0; i < n; i++)
  {
    cin >> t[i] >> g[i];
    cnt[--g[i]]++;
  }

  int numState = 0, id[55][55][55];
  array<int, 3> states[5555];
  for (int i = 0; i <= cnt[0]; i++)
    for (int j = 0; j <= cnt[1]; j++)
      for (int k = 0; k <= cnt[2]; k++)
      {
        id[i][j][k] = numState;
        states[numState++] = {i, j, k};
      }

  // knapsack    
  vector <int> f[2525];
  for (int i = 0; i <= T; i++)
    f[i] = vector <int>(numState, 0);
  f[0][0] = 1;

  for (int i = 0; i < n; i++)
    for (int sum = T; sum >= t[i]; sum--)
      for (int state = numState - 1; state; state--)
        if (states[state][g[i]])
        {
          auto x = states[state];
          x[g[i]]--;
          int prevState = id[x[0]][x[1]][x[2]];
          f[sum][state] = (f[sum][state] + f[sum - t[i]][prevState]) % BASE;
        }

  // arrangement
  int ways[55][55][55][3] = {0};
  ways[0][0][0][0] = 1;
  for (int i = 0; i <= cnt[0]; i++)
    for (int j = 0; j <= cnt[1]; j++)
      for (int k = 0; k <= cnt[2]; k++)
        for (int prev = 0; prev < 3; prev++)
        {
          if (prev || i + j + k == 0)
            ways[i + 1][j][k][0] = (ways[i + 1][j][k][0] + ways[i][j][k][prev]) % BASE;
          if (prev != 1 || i + j + k == 0)
            ways[i][j + 1][k][1] = (ways[i][j + 1][k][1] + ways[i][j][k][prev]) % BASE;
          if (prev != 2 || i + j + k == 0)
            ways[i][j][k + 1][2] = (ways[i][j][k + 1][2] + ways[i][j][k][prev]) % BASE;
        }       

  long long ans = 0;
  for (int state = 0; state < numState; state++)
  {
    int i = states[state][0], j = states[state][1], k = states[state][2];
    long long value = fact(i) * fact(j) % BASE * fact(k) % BASE;
    value = value * (1LL * ways[i][j][k][0] + ways[i][j][k][1] + ways[i][j][k][2]) % BASE;
    value = value * f[T][state] % BASE;
    ans = (ans + value) % BASE;
  }

  cout << ans << endl;
}