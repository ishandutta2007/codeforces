#include <bits/stdc++.h>
using namespace std;
const int K = 18;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q, n = 1;
  cin >> q;
  vector<int> w(q);
  vector<vector<int>> p(q, vector<int>(K + 1));
  vector<vector<long long>> sum(q, vector<long long>(K + 1));
  long long ans = 0;
  while (q--)
  {
    int op;
    long long x, y;
    cin >> op >> x >> y;
    x ^= ans;
    y ^= ans;
    if (op == 1)
    {
      w[++n] = y;
      while (x && w[x] < w[n])
        x = p[x][0];
      if (!x)
        continue;
      p[n][0] = x;
      sum[n][0] = w[x];
      for (int i = 0; i < K; i++)
      {
        p[n][i + 1] = p[p[n][i]][i];
        sum[n][i + 1] = sum[n][i] + sum[p[n][i]][i];
      }
    }
    else
    {
      ans = 0;
      if (y >= w[x])
      {
        y -= w[x];
        ans = 1;
        for (int i = K; i >= 0; i--)
          if (p[x][i] && sum[x][i] <= y)
          {
            ans += 1 << i;
            y -= sum[x][i];
            x = p[x][i];
          }
      }
      cout << ans << '\n';
    }
  }
}