#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
      cin >> x[i];
    vector<string> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int ans = -1;
    vector<int> pAns;
    for (int mask = 0; mask < 1 << n; mask++)
    {
      vector<int> coef(m);
      int score = 0;
      for (int i = 0; i < n; i++)
      {
        score += mask >> i & 1 ? -x[i] : x[i];
        for (int j = 0; j < m; j++)
          if (a[i][j] == '1')
            coef[j] += mask >> i & 1 ? 1 : -1;
      }

      vector<int> id(m);
      iota(begin(id), end(id), 0);
      sort(begin(id), end(id), [&](int u, int v) { return coef[u] < coef[v]; });
      vector<int> p(m);
      for (int i = 0; i < m; i++)
        p[id[i]] = i + 1;

      int isValid = 1;
      for (int i = 0; i < n; i++)
      {
        int curScore = 0;
        for (int j = 0; j < m; j++)
          if (a[i][j] == '1')
            curScore += p[j];
        if ((curScore >= x[i]) ^ (mask >> i & 1))
          isValid = 0;
      }

      for (int i = 0; i < m; i++)
        score += coef[i] * p[i];

      if (isValid && score > ans)
      {
        ans = score;
        pAns = p;
      }
    }

    for (int x : pAns)
      cout << x << ' ';
    cout << '\n';
  }
}