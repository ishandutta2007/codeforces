#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

int main()
{
  int k, q;
  cin >> k >> q;
  vector<double> f(k + 1);
  f[0] = 1;
  vector<double> ans = {0};
  for (int i = 0;; i++)
  {
    vector<double> newF(k + 1);
    for (int j = 0; j <= min(i, k); j++)
    {
      newF[j] += f[j] * j / k;
      newF[j + 1] += f[j] * (k - j) / k;
    }
    swap(f, newF);
    ans.push_back(f[k]);
    if (f[k] >= 0.5)
      break;
  }
  debug(size(ans), ans.back());

  while (q--)
  {
    int p;
    cin >> p;
    for (int i = 0; i < size(ans); i++)
      if (ans[i] * 2000 >= p)
      {
        cout << i << endl;
        break;
      }
  }
}