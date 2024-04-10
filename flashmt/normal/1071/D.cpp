#include <bits/stdc++.h>
using namespace std;
const int SUM = 25;
const int DIVISORS = 1000;
const int N = 1e6;
const int oo = 27081993;

vector<vector<int>> all;
vector<int> numDivisors, deg;
map<vector<int>, int> id;
int sieve[N + 5];

void att(int p, int divisors, long long v, long long n, int maxPower)
{
  int isPrime = 1;
  for (int i = 2; i * i <= p; i++)
    if (p % i == 0)
      isPrime = 0;
  if (!isPrime) att(p + 1, divisors, v, n, maxPower);
  else
  {
    id[deg] = size(all);
    all.push_back(deg);
    numDivisors.push_back(divisors);
    if (v * p > n)
      return;
    for (int i = 1; i <= maxPower; i++)
    {
      if (n / p < v)
        break;
      v *= p;
      deg.push_back(i);
      att(p + 1, divisors * (i + 1), v, n, i);
      deg.pop_back();
    }
  }
}

void gen(vector<int> &a, int sum, int divisors, int last)
{
  if (sum > SUM || divisors > DIVISORS)
    return;
  if (!id.count(a))
  {
    id[a] = size(all);
    all.push_back(a);
    numDivisors.push_back(divisors);
  }
  for (int i = last; i; i--)
  {
    a.push_back(i);
    gen(a, sum + i, divisors * (i + 1), i);
    a.pop_back();
  }
}

int factorize(int x)
{
  vector<int> res;
  while (sieve[x])
  {
    int d = sieve[x], p = 0;
    while (x % d == 0)
    {
      x /= d;
      p++;
    }
    res.push_back(p);
  }
  if (x > 1)
    res.push_back(1);
  sort(rbegin(res), rend(res));
  return id[res];
}

int main()
{
  att(2, 1, 1, 1000000, 100);
  int numSource = size(all);
  for (int i = 1; i <= SUM; i++)
  {
    vector<int> a = {i};
    gen(a, i, i + 1, i);
  }
  int numNode = size(all);

  vector<vector<int>> dist(numSource, vector<int>(DIVISORS + 1, oo));
  for (int s = 0; s < numSource; s++)
  {
    queue<int> q;
    q.push(s);
    vector<int> nodeDist(numNode, -1);
    dist[s][numDivisors[s]] = 0;
    nodeDist[s] = 0;
    while (!empty(q))
    {
      int x = q.front();
      q.pop();
      vector<int> cur = all[x];

      auto update = [&](int y)
      {
        if (nodeDist[y] < 0)
        {
          dist[s][numDivisors[y]] = min(dist[s][numDivisors[y]], nodeDist[x] + 1);
          nodeDist[y] = nodeDist[x] + 1;
          q.push(y);
        }
      };

      for (int i = 0; i < size(cur); i++)
      {
        cur[i]++;
        if (id.count(cur))
          update(id[cur]);
        cur[i] -= 2;
        if (id.count(cur))
          update(id[cur]);
        cur[i]++;
      }

      cur.push_back(1);
      if (id.count(cur))
        update(id[cur]);
    }
  }

  for (int i = 2; i * i <= N; i++)
    if (!sieve[i])
      for (int j = i * i; j <= N; j += i)
        sieve[j] = i;

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int x, y;
    cin >> x >> y;
    x = factorize(x);
    y = factorize(y);
    int ans = oo;
    for (int i = 1; i <= DIVISORS; i++)
      ans = min(ans, dist[x][i] + dist[y][i]);
    cout << ans << '\n';
  }
}