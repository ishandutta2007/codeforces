#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
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
    int n, m;
    cin >> n >> m;
    if (m < n) cout  << "No\n";
    else if (n % 2)
    {
      cout << "Yes\n";
      for (int i = 0; i < n; i++)
        cout << (i ? 1 : m - n + 1) << ' ';
      cout << '\n';
    }
    else if (m % 2) cout << "No\n";
    else
    {
      cout << "Yes\n";
      for (int i = 0; i < n; i++)
        cout << (i < 2 ? 1 + (m - n) / 2 : 1) << ' ';
      cout << '\n';
    }
  }
}