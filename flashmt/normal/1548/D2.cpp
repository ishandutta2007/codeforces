#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x[6060], y[6060];
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];

  auto mod4 = [&](int x)
  {
    return x >= 0 ? x % 4 : (4 - (-x) % 4) % 4;
  };

  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    int cnt[4][4][4] = {0};
    for (int j = 0; j < n; j++)
      if (j != i)
        cnt[mod4(x[j] - x[i])][mod4(y[j] - y[i])][gcd(abs(x[i] - x[j]), abs(y[i] - y[j])) % 4]++;

    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        for (int p = 0; p < 4; p++)
          for (int jj = j; jj < 4; jj++)
            for (int kk = j == jj ? k : 0; kk < 4; kk++)
            {
              int dj = mod4(jj - j), dk = mod4(kk - k);
              if (dj % 2 || dk % 2)
                continue;

              int opp = dj || dk ? 2 : 0;
              int area = (j * k + (jj - j) * (kk + k) + (4 - jj) * kk) % 4;
              int pp = mod4(area - p - opp);
              if (j == jj && k == kk && p > pp)
                continue;

              int coef = p % 2 ? 3 : 1;
              if (j == jj && k == kk && p == pp) ans += cnt[j][k][p] * (cnt[j][k][p] - 1) / 2 * coef;
              else ans += cnt[j][k][p] * cnt[jj][kk][pp] * coef;
            }
  }

  cout << ans / 3 << endl;
}