#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

int query(int x)
{
  cout << "? " << x + 1 << endl;
  cout.flush();
  int resp;
  cin >> resp;
  return resp - 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int &x : d)
      cin >> x;

    vector<int> c(n, -1);
    int curColor = 0;
    while (1)
    {
      int maxD = -1, x = -1;
      for (int i = 0; i < n; i++)
        if (c[i] < 0 && d[i] > maxD)
        {
          maxD = d[i];
          x = i;
        }

      if (x < 0)
        break;

      vector<int> comp;
      for (int i = 0; i < d[x]; i++)
      {
        int y = query(x);
        if (c[y] < 0) comp.push_back(y);
        else
        {
          // connected to an already colored component
          c[x] = c[y];
          break;
        }
      }

      // new component
      if (c[x] < 0)
        c[x] = curColor++;

      for (int y : comp)
        c[y] = c[x];
    }

    cout << "!";
    for (int x : c)
      cout << ' ' << x + 1;
    cout << endl;
    cout.flush();
  }
}