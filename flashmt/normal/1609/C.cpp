#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int A = 1e6 + 5;

int sieve[A];

int main()
{
  for (int i = 2; i * i < A; i++)
    if (!sieve[i])
      for (int j = i * i; j < A; j += i)
        sieve[j] = i;

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, e;
    cin >> n >> e;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    long long ans = 0;
    for (int i = 0; i < e; i++)
    {
      int lastPrime = -1, bound = -1;
      for (int j = i; j < n; j += e)
        if (a[j] == 1)
        {
          if (lastPrime >= 0)
            ans += lastPrime - bound;
        }
        else if (!sieve[a[j]])
        {
          if (lastPrime >= 0)
            bound = lastPrime;
          lastPrime = j / e;
          ans += lastPrime - bound - 1;
        }
        else
        {
          lastPrime = -1;
          bound = j / e;
        }
    }

    cout << ans << '\n';
  }
}