#include <bits/stdc++.h>
using namespace std;

long long choose(int n, int k)
{
  long long res = 1;
  for (int i = 1; i <= k; i++)
    res = res * (n - i + 1) / i;
  return res;
}

int main()
{
  int a, b, c, l;
  cin >> a >> b >> c >> l;

  long long total = choose(l + 3, 3), bad = 0;
  for (int i = 0; i <= l; i++)
  {
    if (a + i >= b + c)
      bad += choose(min(l - i, a + i - b - c) + 2, 2);
    if (b + i >= a + c)
      bad += choose(min(l - i, b + i - a - c) + 2, 2);
    if (c + i >= a + b)
      bad += choose(min(l - i, c + i - a - b) + 2, 2);
  }
  cout << total - bad << endl;
}