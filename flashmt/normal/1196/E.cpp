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
    int b, w, flipped = 0;
    cin >> b >> w;
    if (b > w)
    {
      flipped = 1;
      swap(b, w);
    }

    if (b * 3 + 1 < w) cout << "NO\n";
    else
    {
      cout << "YES\n";
      w -= b;
      for (int i = 0; i < b * 2; i++)
        cout << 2 << ' ' << i + 2 - flipped << '\n';
      if (w)
      {
        cout << 2 << ' ' << b * 2 + 2 - flipped << '\n';
        w--;
      }
      for (int x = 1; x <= 3; x += 2)
        for (int i = 0; i < b; i++)
          if (w)
          {
            cout << x << ' ' << 3 + i * 2 - flipped << '\n';
            w--;
          }
    }
  }
}