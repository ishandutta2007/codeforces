#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

long long calc(long long n)
{
  if (!n)
    return 0;
  long long x = (long long)(sqrt(n));
  while ((x + 1) * (x + 1) <= n)
    x++;
  while (x * x > n)
    x--;
  long long res = (x - 1) * 3 + 1;
  for (int i : {1, 2})
    if (n >= x * (x + i))
      res++;
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
    long long l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << '\n';
  }
}