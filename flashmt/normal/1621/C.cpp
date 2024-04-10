#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

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
    vector<int> p(n, -1), flag(n);
    while (1)
    {
      int x = -1;
      for (int i = 0; i < n; i++)
        if (p[i] < 0)
        {
          x = i;
          break;
        }

      if (x < 0)
        break;

      vector<int> allV;
      while (1)
      {
        cout << "? " << x + 1 << endl;
        cout.flush();
        int v;
        cin >> v;
        v--;
        if (flag[v])
          break;
        flag[v] = 1;
        allV.push_back(v);
      }

      int len = size(allV);
      for (int i = 0; i < len; i++)
        p[allV[i]] = allV[(i + 1) % len];
    }

    cout << "! ";
    for (int x : p)
      cout << x + 1 << ' ';
    cout << endl;
    cout.flush();
  }
}