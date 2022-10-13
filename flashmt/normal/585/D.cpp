#include <bits/stdc++.h>
using namespace std;
const string S = "LMW";
const int oo = 1 << 30, Z = 250000001;

int n, a[33][3], sum[3], ans = -oo, p[15];
long long ansS;
unordered_map < long long, pair<int,int> > m;

void go(int i, int to, int isQuery, int s)
{
  if (i == to)
  {
    if (isQuery)
    {
      long long h = 1LL * (sum[0] - sum[1] + Z) * oo + (sum[1] - sum[2] + Z);
      if (m.count(h))
      {
        auto u = m[h];
        if (u.first + sum[0] > ans)
        {
          ans = u.first + sum[0];
          ansS = 1LL * u.second * p[n - n / 2] + s;
        }
      }
    }
    else
    {
      long long h = 1LL * (sum[1] - sum[0] + Z) * oo + (sum[2] - sum[1] + Z);
      if (!m.count(h)) m[h] = {sum[0], s};
      else 
      {
        auto u = m[h];
        if (u.first < sum[0])
          m[h] = {sum[0], s};
      }
    }

    return;
  }

  for (int j = 0; j < 3; j++)
    for (int jj = j + 1; jj < 3; jj++)
    {
      sum[j] += a[i][j];
      sum[jj] += a[i][jj];
      go(i + 1, to, isQuery, s * 3 + 3 - j - jj);
      sum[j] -= a[i][j];
      sum[jj] -= a[i][jj];
    }
}

int main()
{
  ios::sync_with_stdio(0);
  p[0] = 1;
  for (int i = 1; i < 15; i++)
    p[i] = p[i - 1] * 3;

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++)
      cin >> a[i][j];

  if (n == 1)
  {
    for (int j = 0; j < 3; j++)
      for (int jj = j + 1; jj < 3; jj++)
        if (!a[0][j] && !a[0][jj])
        {
          cout << S[j] << S[jj] << endl;
          return 0;
        }
    cout << "Impossible" << endl;
    return 0;
  }

  go(0, n / 2, 0, 0);
  go(n / 2, n, 1, 0);
  if (ans == -oo) cout << "Impossible" << endl;
  else
  {
    vector <string> res;
    for (int i = 0; i < n; i++)
    {
      if (ansS % 3 == 0) res.push_back("MW");
      else if (ansS % 3 == 1) res.push_back("LW");
      else res.push_back("LM");
      ansS /= 3;
    }
    for (int i = n - 1; i >= 0; i--)
      cout << res[i] << endl;
  }
}