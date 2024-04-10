#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int x, y;
    cin >> x >> y;
    long long ans = 0;
    for (int i = 1; i * (i + 2) <= x; i++)
      ans += max(min((x - i) / i, y) - i, 0);
    cout << ans << endl;
  }
}