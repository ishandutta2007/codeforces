#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n, k;
    cin >> n >> k;

    auto xorK = [&](int x, int y, int signY)
    {
      int res = 0;
      for (int p = 1; x || y; x /= k, y /= k, p *= k)
        res += (x % k + y % k * signY + k) % k * p;
      return res;
    };

    for (int i = 0, sum = 0, sign = 1; i < n; i++)
    {
      int x = xorK(sum, i, sign);
      cout << x << endl;
      cout.flush();
      int resp;
      cin >> resp;
      if (resp)
        break;
      sum = xorK(x, sum, -1);
      sign = -sign;
    }
  }
}