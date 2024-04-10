#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int BASE = 998244353;
const int oo = 1 << 30;

int main()
{
  int n;
  cin >> n;
  vector<int> x(n), y(n), d(n);
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i];
    d[i] = i;
  }

  auto getDist = [&](int u, int v)
  {
    return abs(x[u] - x[v]) + abs(y[u] - y[v]);
  };

  vector<vector<int>> cand(n);
  vector<int> minDist(n, oo);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j)
      {
        int dist = getDist(i, j);
        if (dist == minDist[i]) cand[i].push_back(j);
        else if (dist < minDist[i])
        {
          minDist[i] = dist;
          cand[i] = {j};
        }
      }

  for (int i = 0; i < n; i++)
    if (d[i] == i)
    {
      vector<int> flag(n), q = cand[i];
      for (int j : cand[i])
        flag[j] = 1;
      for (int cur = 0; cur < size(q); cur++)
      {
        int x = q[cur];
        for (int y : cand[x])
          if (!flag[y])
          {
            flag[y] = 1;
            q.push_back(y);
          }
      }

      int isGood = 1;
      for (int x : q)
        isGood &= minDist[x] == minDist[i];

      for (int x : q)
        for (int y : q)
          if (x != y && getDist(x, y) != minDist[i])
            isGood = 0;

      if (isGood)
        for (int j : cand[i])
          d[j] = d[i];
    }

  vector<int> cnt(n);
  for (int i : d)
    cnt[i]++;

  vector<long long> f(n + 1);
  f[n] = 1;
  for (int i : cnt)
    if (i)
    {
      vector<long long> newF(n + 1);
      for (int j = 1; j <= n; j++)
      {
        newF[j - 1] += f[j] * j;
        newF[j - 1] %= BASE;
        if (i <= j && i > 1)
        {
          long long cur = f[j];
          for (int k = 0; k < i; k++)
            cur = cur * (j - k) % BASE;
          newF[j - i] += cur;
          newF[j - i] %= BASE;
        }
      }
      swap(f, newF);
    }

  long long ans = accumulate(begin(f), end(f), 0LL) % BASE;
  cout << ans << endl;
}