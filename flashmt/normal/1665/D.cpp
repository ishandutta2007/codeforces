#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int x = 0;
    for (int i = 0; i < 30; i++)
    {
      int a = (1 << i) - x;
      int b = (3 << i) - x;
      cout << "? " << a << ' ' << b << endl;
      cout.flush();
      int g;
      cin >> g;
      if (g == 2 << i)
        x |= 1 << i;
    }
    cout << "! " << x << endl;
    cout.flush();
  }
}