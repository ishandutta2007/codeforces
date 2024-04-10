#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<int> primes;
  for (int i = 2; i * i <= 1e9; i++)
  {
    int isPrime = 1;
    for (int j = 2; j * j <= i; j++)
      if (i % j == 0)
        isPrime = 0;
    if (isPrime)
      primes.push_back(i);
  }

  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    set<int> d;
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0)
      {
        d.insert(i);
        if (i * i < n)
          d.insert(n / i);
      }
    d.insert(n);

    int nn = n;
    vector<int> p;
    for (int x : primes)
      if (nn % x == 0)
      {
        p.push_back(x);
        while (nn % x == 0)
          nn /= x;
      }
    if (nn > 1)
      p.push_back(nn);

    if (size(p) == 1 || size(d) == 3)
    {
      for (int x : d)
        cout << x << ' ';
      cout << '\n' << (size(p) > 1) << '\n';
      continue;
    }

    if (size(p) == 2)
    {
      int u = p[0] * p[1];
      d.erase(u);
      for (int x : d)
        if (x % p[0])
          cout << x << ' ';
      cout << u << ' ';
      for (int x : d)
        if (x % p[0] == 0)
          cout << x << ' ';
    }
    else
    {
      for (int i = 0; i < size(p); i++)
        d.erase(p[i] * p[(i + 1) % size(p)]);
      for (int i = 0; i < size(p); i++)
      {
        vector<int> tmp;
        for (int x : d)
          if (x % p[i] == 0)
          {
            cout << x << ' ';
            tmp.push_back(x);
          }
        for (int x : tmp)
          d.erase(x);
        cout << p[i] * p[(i + 1) % size(p)] << ' ';
      }
    }
    cout << '\n' << 0 << '\n';
  }
}