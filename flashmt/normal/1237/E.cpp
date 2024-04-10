#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int x = 2;
  while (x <= 1000000)
  {
    if (n == x - 1 || n == x)
    {
      cout << 1 << endl;
      return 0;
    }

    x = x * 2 + 1 - x % 2;
  }

  cout << 0 << endl;
}