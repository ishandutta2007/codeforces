#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> baseTriples, smallTriples;

void init()
{
  baseTriples.push_back({0, 0, 0});
  baseTriples.push_back({1, 2, 3});
  baseTriples.push_back({2, 3, 1});
  baseTriples.push_back({3, 1, 2});

  int seen[16] = {0};
  for (int i = 1; i < 16; i++)
    for (int j = 1; j < 16; j++)
    {
      int k = i ^ j;
      if (!seen[i] && !seen[j] && !seen[k] && k)
      {
        seen[i] = seen[j] = seen[k] = 1;
        smallTriples.push_back({i, j, k});
      }
    }
}

long long solve(long long n)
{
  n--;
  int id = n % 3;
  n /= 3;
  if (n < size(smallTriples))
    return smallTriples[n][id];
  n -= size(smallTriples);

  int bit = 4;
  while (n >= 1LL << bit)
  {
    n -= 1LL << bit;
    bit += 2;
  }
  long long x0 = 1LL << bit | n;
  if (!id)
    return x0;

  long long x1 = 1LL << bit + 1;
  for (int i = 0; i < bit; i += 2)
  {
    int v = x0 >> i & 3;
    if (v == 1) x1 |= 2LL << i;
    else if (v == 2) x1 |= 3LL << i;
    else if (v == 3) x1 |= 1LL << i;
  }

  return id == 1 ? x1 : x0 ^ x1;
}

int main()
{
  init();

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    long long n;
    cin >> n;
    cout << solve(n) << '\n';
  }
}