#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n;
  cin >> n;
  set<long long> divisors;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0)
    {
      divisors.insert(i);
      divisors.insert(n / i);
    }

  if (divisors.empty()) cout << n << endl;
  else
  {
    long long d = *divisors.begin();
    for (auto divisor : divisors)
      if (divisor % d)
      {
        cout << 1 << endl;
        return 0;
      }

    cout << d << endl;
  }
}