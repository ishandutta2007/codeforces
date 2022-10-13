#include <bits/stdc++.h>
using namespace std;

bitset<7000> a[100100];
bitset<7000> b[7070]; // for op 1
bitset<7000> c[7070]; // for op 4

int isSqrFree(int x)
{
  for (int i = 2; i * i <= x; i++)
    if (x % (i * i) == 0)
      return 0;
  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 7000; i++)
    for (int j = i; j <= 7000; j += i)
    {
      b[j][i - 1] = 1;
      if (isSqrFree(j / i))
        c[i][j - 1] = 1;
    }

  int n, q;
  cin >> n >> q;
  while (q--)
  {
    int op, x, y, z, v;
    cin >> op >> x;

    if (op == 1)
    {
      cin >> v;
      a[x] = b[v];
    }
    else if (op == 2)
    {
      cin >> y >> z;
      a[x] = a[y] ^ a[z];
    }
    else if (op == 3)
    {
      cin >> y >> z;
      a[x] = a[y] & a[z];
    }
    else
    {
      cin >> v;
      cout << (a[x] & c[v]).count() % 2;
    }
  }
}