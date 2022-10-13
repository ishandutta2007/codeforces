#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

struct Matrix
{
  long long a[3][3];

  Matrix()
  {
    memset(a, 0, sizeof a);
  }

  friend Matrix operator * (Matrix u, Matrix v)
  {
    Matrix res;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++)
          res.a[i][j] = (res.a[i][j] + u.a[i][k] * v.a[k][j]) % (BASE - 1);
    return res;
  }
};

Matrix power(const Matrix u, long long k)
{
  if (k == 1)
    return u;
  Matrix res = power(u, k / 2);
  res = res * res;
  if (k % 2)
    res = res * u;
  return res;
}

long long power(long long x, long long y)
{
  if (!y)
    return 1;
  long long res = power(x, y / 2);
  res = res * res % BASE;
  if (y % 2)
    res = res * x % BASE;
  return res;
}

set <int> primes;

map <int, int> factorize(int n)
{
  map <int, int> res;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
    {
      res[i] = 0;
      while (n % i == 0)
      {
        res[i]++;
        n /= i;
      }
    }

  if (n > 1)
    res[n] = 1;
  for (auto u : res)
    primes.insert(u.first);
  return res;
}

int main()
{
  long long n, c;
  map <int, int> fPrimes[3];
  cin >> n;
  for (int i = 0; i < 3; i++)
  {
    int f;
    cin >> f;
    fPrimes[i] = factorize(f);
  }
  cin >> c;
  auto cPrimes = factorize(c);

  Matrix matrix;
  matrix.a[0][2] = matrix.a[1][0] = matrix.a[1][2] = matrix.a[2][1] = matrix.a[2][2] = 1;
  matrix = power(matrix, n - 3);

  long long ans = 1;
  for (int prime : primes)
  {
    long long k = 0;
    for (int i = 0; i < 3; i++)
      k += (fPrimes[i][prime] + cPrimes[prime] * (i + 1)) * matrix.a[i][2];
    ans = ans * power(prime, k) % BASE;
  }

  ans = ans * power(power(c, n), BASE - 2) % BASE;
  cout << ans << endl;
}