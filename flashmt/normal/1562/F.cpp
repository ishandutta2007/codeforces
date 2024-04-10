#include <bits/stdc++.h>
using namespace std;
const int CHECK_POS = 100;
const int A = 200000;
const int K = 450;

int n, sieve[A + 5], a[A];
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
map<pair<int, int>, long long> cache;

long long ask(int x, int y)
{
  if (x > y)
    swap(x, y);
  if (cache.count({x, y}))
    return cache[{x, y}];
  cout << "? " << x + 1 << ' ' << y + 1 << endl;
  cout.flush();
  long long resp;
  cin >> resp;
  assert(int(size(cache)) < n + 5000);
  cache[{x, y}] = resp;
  return resp;
}

int getPrimeDivisor(long long x)
{
  for (long long i = 2; i * i < x; i++)
    if (!sieve[i] && x % i == 0)
    {
      long long j = x / i;
      if (j > A)
        return 0;
      if (!sieve[j])
        return j;
    }
  return 0;
}

int getMaxPrimeDivisor(long long x)
{
  for (long long i = 2; i * i <= x; i++)
    while (x % i == 0)
      x /= i;
  return x;
}

void solveSmall()
{
  set<long long> s, sAt[111];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
    {
      long long v = ask(i, j);
      s.insert(v);
      sAt[i].insert(v);
      sAt[j].insert(v);
    }

  vector<int> cand;
  for (int i = 2, cnt = 0; i <= A; i++)
    if (!s.count(i * (i - 1LL))) cnt = 0;
    else if (++cnt >= n - 1) cand.push_back(i);

  int high = 0;
  for (int to : cand)
  {
    int from = to - n + 1, isGood = 1;
    for (int i = from; i < to && isGood; i++)
      for (int j = i + 1; j <= to; j++)
        if (!s.count(1LL * i * j / gcd(i, j)))
        {
          isGood = 0;
          break;
        }

    if (isGood)
    {
      high = to;
      break;
    }
  }

  assert(high);
  int low = high - n + 1;
  set<long long> sVal[111];
  for (int i = low; i <= high; i++)
    for (int j = low; j <= high; j++)
      if (i != j)
      {
        long long v = 1LL * i * j / gcd(i, j);
        sVal[i - low].insert(v);
        sVal[j - low].insert(v);
      }

  vector<int> flag(n + 1);
  for (int i = 0; i < n; i++)
    for (int v = low; v < low + n; v++)
      if (sAt[i] == sVal[v - low])
        a[i] = v;
}

void solveMed()
{
  int maxPrime = 0, x = 0, y = 0;
  vector<int> id(n);
  iota(begin(id), end(id), 0);
  shuffle(begin(id), end(id), rng);
  for (int i = 0; i < n; i += 2)
  {
    int j = i + 1 < n ? i + 1 : i - 1;
    long long v = ask(id[i], id[j]);
    int d = getMaxPrimeDivisor(v);
    if (d > maxPrime)
    {
      maxPrime = d;
      x = id[i];
      y = id[j];
    }
  }

  for (int i = 0; i < n; i++)
    if (i != x && i != y)
    {
      if (ask(i, x) % maxPrime)
        swap(x, y);
      break;
    }

  a[x] = maxPrime;
  for (int i = 0; i < n; i++)
    if (!a[i])
      a[i] = ask(i, x) / maxPrime;
}

void solveLarge()
{
  // find a big prime vx
  int x, y, vx = 0;
  while (size(cache) + CHECK_POS < 4200)
  {
    int i = rng() % n, j = rng() % n;
    if (j == i)
      j = (i + 1) % n;
    long long v = ask(i, j);
    int d = getPrimeDivisor(v);
    if (d >= K)
    {
      vx = d;
      x = i;
      y = j;
      break;
    }
  }

  // verify if a[x] = vx or a[y] = vx
  for (int i = 0; i < CHECK_POS; i++)
  {
    int z = rng() % n;
    while (z == x || z == y)
      z = (z + 1) % n;
    if (ask(x, z) % vx)
    {
      swap(x, y);
      break;
    }
  }

  // find the rest, assume they are all coprime with vx
  a[x] = vx;
  int maxPrime = 0, idPrime = -1;
  for (int i = 0; i < n; i++)
    if (i != x)
    {
      long long v = ask(x, i);
      if (v > A)
      {
        a[i] = v / a[x];
        if (!sieve[a[i]] && a[i] > maxPrime)
        {
          maxPrime = a[i];
          idPrime = i;
        }
      }
    }

  assert(idPrime >= 0);
  // handle case both lcm(vx, i) = lcm(vx, i * vx) = i * vx
  for (int i = 0; i < n; i++)
    if (!a[i])
      a[i] = ask(i, idPrime) / a[idPrime];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i * i <= A; i++)
    if (!sieve[i])
      for (int j = i * i; j <= A; j += i)
        sieve[j] = 1;

  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    cache.clear();
    for (int i = 0; i < n; i++)
      a[i] = 0;
    if (n <= 100) solveSmall();
    else if (n <= 10000) solveMed();
    else solveLarge();
    cout << "!";
    for (int i = 0; i < n; i++)
      cout << ' ' << a[i];
    cout << endl;
    cout.flush();
  }
}