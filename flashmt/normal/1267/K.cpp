#include <bits/stdc++.h>
using namespace std;

long long c[22][22];

long long solve(long long x)
{
  vector<int> a;
  int d = 1;
  while (x > 0)
  {
    d++;
    a.push_back(x % d);
    x /= d;
  }
  sort(a.begin(), a.end(), greater<int>());

  long long res = 1;
  for (int i = 0; i < a.size();)
  {
    int j = i + 1;
    while (j < a.size() && a[j] == a[i])
      j++;
    res *= c[d - max(a[i], 1) - i][j - i];
    i = j;
  }

  // 0 can't be the last remainder
  if (!a.back())
  {
    long long bad = 1;
    for (int i = 0; i < a.size();)
    {
      int j = i + 1;
      while (j < a.size() && a[j] == a[i])
        j++;
      bad *= c[d - 1 - max(a[i], 1) - i][j - i];
      i = j;
      if (!a[i])
        break;
    }
    res -= bad;
  }

  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i <= 20; i++)
    for (int j = 0; j <= i; j++)
      c[i][j] = j ? c[i - 1][j] + c[i - 1][j - 1] : 1;

  int test;
  cin >> test;
  while (test--)
  {
    long long x;
    cin >> x;
    cout << solve(x) - 1 << '\n';
  }
}