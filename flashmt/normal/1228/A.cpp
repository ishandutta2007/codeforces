#include <bits/stdc++.h>
using namespace std;

int main()
{
  int l, r;
  cin >> l >> r;
  for (int i = l; i <= r; i++)
  {
    int tmp = i, flag[10] = {0}, isGood = 1;
    while (tmp)
    {
      int x = tmp % 10;
      tmp /= 10;
      if (flag[x]) isGood = 0;
      else flag[x] = 1;
    }

    if (isGood)
    {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}