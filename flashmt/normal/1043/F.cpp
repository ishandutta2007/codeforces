#include <bits/stdc++.h>
using namespace std;
const int A = 3e5, BASE = 1e9 + 7;

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

  int n, x, cnt[A + 5] = {0};
  cin >> n;
  while (n--)
  {
    cin >> x;
    cnt[x]++;
  }

  for (int i = 1; i <= A; i++)
    for (int j = i * 2; j <= A; j += i)
      cnt[i] += cnt[j];

  vector<long long> c(A + 5, 1), ways(A + 5);
  for (int pick = 1; pick <= 7; pick++)
  {
    for (int i = A; i; i--)
    {
      c[i] = c[i] * (cnt[i] - pick + 1) % BASE * power(pick, BASE - 2) % BASE;
      ways[i] = c[i];
      for (int j = i * 2; j <= A; j += i)
        ways[i] = (ways[i] - ways[j] + BASE) % BASE;
    }

    if (ways[1])
    {
      cout << pick << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}