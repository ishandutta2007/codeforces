#include <bits/stdc++.h>
using namespace std;
const int N = 18180180;

char sieve[N];

int main()
{
  sieve[1] = 1;
  for (int i = 2; i * i < N; i++)
    if (!sieve[i])
      for (int j = i * i; j < N; j += i)
        sieve[j] = 1;

  int n;
  cin >> n;

  int sum = n * (n + 1) / 2, sum2 = 0;
  vector<int> ans(n, 1);
  if (sieve[sum])
  {
    for (int i = 2; i * 2 <= sum; i++)
      if (!sieve[i] && !sieve[sum - i])
      {
        sum2 = i;
        break;
      }

    if (!sum2)
    {
      ans[2] = 3;
      for (int i = 2; i * 2 <= sum; i++)
        if (!sieve[i] && !sieve[sum - 3 - i])
        {
          sum2 = i;
          break;
        }
    }
  }

  for (int i = n; i; i--)
    if (sum2 >= i && ans[i - 1] == 1)
    {
      sum2 -= i;
      ans[i - 1] = 2;
    }

  for (int x : ans)
    cout << x << ' ';
}