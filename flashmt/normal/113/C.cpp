#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int A = 3e8 + 5;

int id(int x)
{
  if (x % 6 == 1)
    return x / 6 * 2;
  if (x % 6 == 5)
    return x / 6 * 2 + 1;
  return 0;
}

int main()
{
  int l, r;
  cin >> l >> r;

  bitset<A / 3> good, sieve;
  sieve[0] = 1;
  for (int i = 5; i * i <= r; i += 2)
    if (!sieve[id(i)])
      for (int j = i; 1LL * i * j <= r; j += 2)
        sieve[id(i * j)] = 1;

  for (int i = 1; i * i <= r; i++)
    for (int j = i + 1; i * i + j * j <= r; j += 2)
      good[id(i * i + j * j)] = 1;

  int ans = l <= 2 && 2 <= r;
  good &= sieve.flip();
  int toShift = 1;
  for (int i = max(l - 1, 4); i; i--)
    if (id(i))
    {
      toShift += id(i);
      break;
    }

  ans += (good >> toShift).count();
  cout << ans << endl;
}