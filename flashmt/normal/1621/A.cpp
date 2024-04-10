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
    int n, k;
    cin >> n >> k;
    if (k * 2 - 1 > n) cout << -1 << endl;
    else
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
          if (i == j && j % 2 == 0 && j / 2 < k) cout << 'R';
          else cout << '.';
        cout << endl;
      }
    }
  }
}