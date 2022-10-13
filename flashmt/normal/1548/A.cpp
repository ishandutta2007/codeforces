#include <bits/stdc++.h>
using namespace std;

int n, m, isAlive[200200];
set<int> a[200200];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    isAlive[i] = 1;
    a[i].insert(0);
  }
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    if (x > y)
      swap(x, y);
    a[x].insert(y);
    a[y].insert(x);
    isAlive[x] = 0;
  }

  int cntAlive = accumulate(isAlive + 1, isAlive + n + 1, 0);
  int q;
  cin >> q;
  while (q--)
  {
    int op, x, y;
    cin >> op;
    if (op == 3) cout << cntAlive << '\n';
    else
    {
      cin >> x >> y;
      if (x > y)
        swap(x, y);
      if (op == 1)
      {
        a[x].insert(y);
        a[y].insert(x);
        if (isAlive[x])
        {
          isAlive[x] = 0;
          cntAlive--;
        }
      }
      else
      {
        a[x].erase(y);
        a[y].erase(x);
        if (*a[x].rbegin() < x)
        {
          isAlive[x] = 1;
          cntAlive++;
        }
      }
    }
  }
}