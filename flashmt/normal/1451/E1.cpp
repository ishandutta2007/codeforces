#include <bits/stdc++.h>
using namespace std;

int ask(string op, int x, int y)
{
  cout << op << ' ' << x << ' ' << y << '\n';
  cout.flush();
  int v;
  cin >> v;
  return v;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[1 << 17] = {0};
  cin >> n;
  int x12 = ask("XOR", 1, 2);
  int x13 = ask("XOR", 1, 3);
  int o12 = ask("OR", 1, 2);
  int o13 = ask("OR", 1, 3);
  int o23 = ask("OR", 2, 3);

  for (int bit = 0; bit < 16; bit++)
  {
    if (!(x12 >> bit & 1))
    {
      if (o12 >> bit & 1)
      {
        a[1] |= 1 << bit;
        a[2] |= 1 << bit;
      }
      if ((a[1] >> bit & 1) ^ (x13 >> bit & 1))
        a[3] |= 1 << bit;
    }
    else if (!(x13 >> bit & 1))
    {
      if (o13 >> bit & 1)
      {
        a[1] |= 1 << bit;
        a[3] |= 1 << bit;
      }
      if ((a[1] >> bit & 1) ^ (x12 >> bit & 1))
        a[2] |= 1 << bit;
    }
    else
    {
      if (o23 >> bit & 1)
      {
        a[2] |= 1 << bit;
        a[3] |= 1 << bit;
      }
      if ((a[2] >> bit & 1) ^ (x12 >> bit & 1))
        a[1] |= 1 << bit;
    }
  }

  for (int i = 4; i <= n; i++)
    a[i] = ask("XOR", 1, i) ^ a[1];

  cout << "!";
  for (int i = 1; i <= n; i++)
    cout << ' ' << a[i];
  cout.flush();
}