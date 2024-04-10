#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  long long n, l, r, k;
  while (cin >> n >> l >> r >> k)
  {
    r = (r - l + n) % n + 1;
    long long ans = -1;
    for (auto total : {k, k + 1})
      if (r == n)
      {
        for (long long i = 1; i * i <= total; i++)
          if (total % i == 0)
          {
            if (i >= n && i <= n * 2)
              ans = max(ans, i - n);
            if (total / i >= n && total / i <= n * 2)
              ans = max(ans, total / i - n);
          }
      }
      else
      {
        if (r <= total && total <= r * 2)
          ans = max(ans, total - r + n - r);

        auto check = [&](long long sweetN, long long sweetR)
        {
          if (sweetN >= 0 && sweetN <= n &&
              sweetR >= 0 && sweetR <= min(r, sweetN) &&
              sweetN <= sweetR + n - r && sweetR >= total - k)
            ans = max(ans, sweetN);
        };

        for (long long i = 1; i * i <= total; i++)
        {
          check(i - n, total % i - r);
          long long rem = total - i * n - r;
          if (rem >= 0)
          {
            long long sweetN = min((rem + n - r) / (i + 1), rem / i);
            check(sweetN, rem - i * sweetN);
          }
        }
      }

    cout << ans << endl;
  }
}