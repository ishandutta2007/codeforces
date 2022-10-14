#include <bits/stdc++.h>
using namespace std;
const int A = 1000100;
const int N = 150150;

int n, sieve[A], ds[N + 80000], idPrime[A], a[N];
unordered_set<int> canConnect[N + 80000], hasPair[N + 80000];

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

void join(int x, int y)
{
  int dx = get(x), dy = get(y);
  if (dx != dy)
    ds[dx] = dy;
}

vector<int> factorize(int x)
{
  vector<int> res;
  while (sieve[x])
  {
    res.push_back(sieve[x]);
    x /= sieve[x];
  }
  if (x > 1)
    res.push_back(x);
  return res;
}

int check(int x, int y)
{
  int dx = get(x), dy = get(y);
  if (canConnect[dx].count(dy) || canConnect[dy].count(dx))
    return 1;
  return hasPair[dx].count(dy) || hasPair[dy].count(dx);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int numPrime = 0;
  for (int i = 2; i < A; i++)
    if (!sieve[i])
    {
      idPrime[i] = numPrime++;
      for (int j = i * 2; j < A; j += i)
        sieve[j] = i;
    }

  int q;
  cin >> n >> q;
  for (int i = 0; i < n + numPrime; i++)
    ds[i] = i;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    auto p = factorize(a[i]);
    for (int x : p)
      join(i, n + idPrime[x]);
  }

  for (int i = 0; i < n; i++)
  {
    int d = get(i);
    auto p = factorize(a[i] + 1);
    for (int x : p)
    {
      canConnect[d].insert(get(n + idPrime[x]));
      for (int y : p)
        hasPair[get(n + idPrime[x])].insert(get(n + idPrime[y]));
    }
  }

  while (q--)
  {
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    int dx = get(x), dy = get(y);
    if (dx == dy) cout << "0\n";
    else if (check(x, y)) cout << "1\n";
    else cout << "2\n";
  }
}