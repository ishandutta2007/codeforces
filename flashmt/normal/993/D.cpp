#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const long long oo = 1LL << 60;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i] < a[j] || (a[i] == a[j] && b[i] < b[j]))
      {
        swap(a[i], a[j]);
        swap(b[i], b[j]);
      }

  long long low = 0, high = 1e11, ans = high;
  while (low <= high)
  {
    long long mid = (low + high) / 2;
    vector<long long> f(n + 1, oo);
    f[0] = 0;
    for (int i = 0; i < n;)
    {
      int ii = i + 1;
      while (ii < n && a[ii] == a[i])
        ii++;

      vector<long long> newF(n + 1, oo);
      int cnt = ii - i;
      vector<int> sumB(cnt + 1);
      for (int j = 0; j < cnt; j++)
        sumB[j + 1] = sumB[j] + b[i + j];

      for (int j = 0; j < n; j++)
        for (int pick = 0; pick <= cnt; pick++)
          if (f[j] < oo && cnt - pick <= j)
          {
            int jj = j + pick - (cnt - pick);
            newF[jj] = min(newF[jj], f[j] + 1000LL * a[i] * pick - sumB[pick] * mid);
          }

      i = ii;
      swap(f, newF);
    }

    if (*min_element(begin(f), end(f)) <= 0)
    {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }

  cout << ans << endl;
}