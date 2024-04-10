#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

long long power(long long x, long long y)
{
  if (!y)
    return 1;
  long long res = power(x, y >> 1);
  res = res * res % BASE;
  if (y & 1)
    res = res * x % BASE;
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    if (p == 1) cout << (n % 2) << '\n';
    else
    {
      sort(begin(a), end(a), greater<int>());
      long long v = 0;
      int pw = -1, i;
      for (i = 0; i < n; i++)
        if (!v)
        {
          pw = a[i];
          v = 1;
        }
        else
        {
          while (pw > a[i] && v <= n)
          {
            pw--;
            v *= p;
          }

          if (v > n)
            break;
          v--;
        }

      long long ans = v % BASE * power(p, pw) % BASE;
      for (int j = i; j < n; j++)
        ans = (ans - power(p, a[j]) + BASE) % BASE;
      cout << ans << '\n';
    }
  }
}