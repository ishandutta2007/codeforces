#include <bits/stdc++.h>
using namespace std;
const int A = 2e7 + 5;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cnt(A);
  while (n--)
  {
    int x;
    cin >> x;
    cnt[x]++;
  }

  vector<int> primes, sieve(A);
  for (int i = 2; i < A; i++)
    if (!sieve[i])
    {
      primes.push_back(i);
      for (int j = i * 2; j < A; j += i)
        sieve[j] = 1;
      for (int j = (A - 1) / i; j; j--)
        cnt[j] += cnt[j * i];
    }

  vector<long long> f(A);
  for (int i = A - 1; i; i--)
  {
    for (int p : primes)
    {
      int j = i * p;
      if (j >= A)
        break;
      f[i] = max(f[i], f[j] - 1LL * cnt[j] * i);
    }
    f[i] += 1LL * cnt[i] * i;
  }

  cout << *max_element(begin(f), end(f)) << endl;
}