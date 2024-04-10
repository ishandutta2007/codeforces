#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, p;
  cin >> n >> p;

  for (int i = 1; i <= 50; i++)
  {
    int x = n - p * i;
    if (x < 0)
      continue;
    if (i <= x && i >= __builtin_popcount(x))
    {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}