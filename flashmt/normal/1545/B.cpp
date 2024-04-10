#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

long long fact[100100], invFact[100100];

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

  for (int i = 0; i <= 100000; i++)
  {
    fact[i] = i ? fact[i - 1] * i % BASE : 1;
    invFact[i] = power(fact[i], BASE - 2);
  }

  int test;
  cin >> test;
  while (test--)
  {
    int n;
    string s;
    cin >> n >> s;
    int cntOne = 0, cntZero = 0;
    for (int i = 0; i < n;)
    {
      int j = i;
      while (j < n && s[j] == s[i])
        j++;
      if (s[i] == '1')
      {
        if (j - i >= 2)
          cntOne += (j - i) / 2;
      }
      else cntZero += j - i;
      i = j;
    }

    long long ans = fact[cntOne + cntZero] * invFact[cntOne] % BASE * invFact[cntZero] % BASE;
    cout << ans << endl;
  }
}