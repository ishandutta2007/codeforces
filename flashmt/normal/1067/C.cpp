#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x = i / 3 * 2;
    if (i % 3 == 1)
      x++;
    cout << x << ' ' << i % 3 << '\n';
  }
}