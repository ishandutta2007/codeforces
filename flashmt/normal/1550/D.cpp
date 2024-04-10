#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;
const int N = 500500;

long long fact[N], invFact[N];

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

long long c(int n, int k)
{
  if (k < 0 || k > n)
    return 0;
  return fact[n] * invFact[k] % BASE * invFact[n - k] % BASE;
}

long long calc(int n, int numPos, int numNeg)
{
  long long res = 0;
  int shared = numPos + numNeg - n;
  numPos -= shared;
  res += c(shared, n / 2 - numPos);
  if (n % 2)
    res += c(shared, n / 2 + 1 - numPos);
  return res % BASE;
}

int main()
{
  for (int i = 0; i < N; i++)
  {
    fact[i] = i ? fact[i - 1] * i % BASE : 1;
    invFact[i] = power(fact[i], BASE - 2);
  }

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, l, r;
    cin >> n >> l >> r;

    long long ans = c(n, n / 2);
    if (n % 2)
      ans = (ans + c(n, n / 2 + 1)) % BASE;
    ans = ans * min(abs(l - 1), r - n) % BASE;

    for (int i = 1; i < n; i++)
    {
      int value = r - n + i, numPos = n - i;
      int numNeg = n - max(l - 1 + value, 0);
      if (numPos + numNeg >= n)
        ans += calc(n, numPos, numNeg);
    }

    for (int i = 1; i < n; i++)
    {
      int value = l - 1 - i, numNeg = n - i;
      int numPos = n - max(-value - (r - n), 0);
      if (numPos < n) // already computed above
        continue;
      if (numPos + numNeg >= n)
        ans += calc(n, numPos, numNeg);
    }

    ans %= BASE;
    cout << ans << '\n';
  }
}