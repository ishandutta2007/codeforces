#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;
const int MAX = 100100;

long long cnt[MAX], sum[MAX], sumSqr[MAX], sumPair[MAX], ans[MAX];

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

void add(int i, int freq, long long newSum, long long newSumSqr, long long newSumPair)
{
  cnt[i] += freq;
  sumPair[i] = (sumPair[i] + newSumPair + 2 * newSum * sum[i]) % BASE;
  sum[i] = (sum[i] + newSum) % BASE;
  sumSqr[i] = (sumSqr[i] + newSumSqr) % BASE;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m;
  cin >> m;
  while (m--)
  {
    int x, freq;
    cin >> x >> freq;
    long long newSum = 1LL * x * freq % BASE;
    long long newSumSqr = newSum * x % BASE;
    long long newSumPair = freq * (freq - 1LL) % BASE * x % BASE * x % BASE;
    for (int i = 1; i * i <= x; i++)
      if (x % i == 0)
      {
        add(i, freq, newSum, newSumSqr, newSumPair);
        if (i * i < x)
          add(x / i, freq, newSum, newSumSqr, newSumPair);
      }
  }

  for (int i = 1; i < MAX; i++)
    if (cnt[i] >= 2)
    {
      long long sqrWay = (cnt[i] - 1) % BASE * power(2, cnt[i] - 2) % BASE;
      long long pairWay = power(2, cnt[i] - 2);
      if (cnt[i] >= 3)
        pairWay = (pairWay + (cnt[i] - 2) % BASE * power(2, cnt[i] - 3)) % BASE;
      ans[i] = (sumSqr[i] * sqrWay + sumPair[i] * pairWay) % BASE;
    }

  for (int i = MAX - 1; i; i--)
    for (int j = i * 2; j < MAX; j += i)
      ans[i] = (ans[i] - ans[j] + BASE) % BASE;

  cout << ans[1] << endl;
}