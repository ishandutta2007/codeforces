#include <bits/stdc++.h>
using namespace std;
const int A = 5e6 + 5;

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

  vector<int> sieve(A), mobius(A, 1);
  for (int i = 2; i < A; i++)
    if (!sieve[i])
      for (int j = i; j < A; j += i)
      {
        sieve[j] = i;
        mobius[j] *= -1;
      }
  for (int i = 2; i * i < A; i++)
    if (sieve[i] == i)
      for (int j = i * i; j < A; j += i * i)
        mobius[j] = 0;

  vector<long long> f(A);
  vector<int> cntMult = cnt;
  for (int i = A - 1; i; i--)
  {
    for (int j = i * 2; j < A; j += i)
      cntMult[i] -= cntMult[j] * mobius[j / i];
    f[i] = 1LL * cntMult[i] * i;
    for (int j = i * 2; j < A; j += i)
      f[i] = max(f[i], f[j] + 1LL * (cntMult[i] - cntMult[j]) * i);
  }

  cout << *max_element(begin(f), end(f)) << endl;
}