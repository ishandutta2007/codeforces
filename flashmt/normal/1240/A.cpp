#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    long long p[200100], x, y, a, b, k;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      cin >> p[i];
      p[i] /= 100;
    }
    cin >> x >> a >> y >> b >> k;
    if (x < y)
    {
      swap(x, y);
      swap(a, b);
    }
    sort(p + 1, p + n + 1, greater<int>());
    for (int i = 1; i <= n; i++)
      p[i] += p[i - 1];
    long long lcm = a * b / __gcd(a, b);

    int found = 0;
    for (int i = 1; i <= n; i++)
    {
      int useAB = i / lcm;
      long long earn = (x + y) * p[useAB];
      int useA = i / a - useAB;
      earn += x * (p[useAB + useA] - p[useAB]);
      int useB = i / b - useAB;
      earn += y * (p[useAB + useA + useB] - p[useAB + useA]);
      if (earn >= k)
      {
        cout << i << '\n';
        found = 1;
        break;
      }
    }

    if (!found)
      cout << -1 << '\n';
  }
}