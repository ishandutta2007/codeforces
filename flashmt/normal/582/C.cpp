#include <bits/stdc++.h>
using namespace std;

int n, a[400200], f[200200], maxOf[200200], id[200200], numDivisor, cnt[200][200200];

void calc(int period)
{
  for (int i = 0; i < n * 2; i++)
    if (i < period) maxOf[i] = a[i];
    else maxOf[i % period] = max(maxOf[i % period], a[i]);

  for (int i = 0, length = 0; i < n * 2; i++)
  {
    if (a[i] == maxOf[i % period]) length++;
    else length = 0;
    if (length > n) 
      length = n;
    if (i >= n)
      cnt[numDivisor - 1][length]++;
  }

  for (int i = 1; i <= n; i++)
    cnt[numDivisor - 1][i] += cnt[numDivisor - 1][i - 1];
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[n + i] = a[i];
  }

  for (int i = 1; i < n; i++)
    if (n % i == 0)
    {
      id[i] = numDivisor++;
      calc(i);
    }

  long long ans = 0;
  for (int l = 1; l < n; l++)
  {
    int period = __gcd(l, n), curId = id[period];
    ans += cnt[curId][n] - cnt[curId][l - 1];
  }

  cout << ans << endl;
}