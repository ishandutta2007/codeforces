#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int C = 26;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<vector<int>> cnt(C, vector<int>(C));
    for (int i = 0; i < n; i++)
    {
      int x = b[i] - 'a', y = a[n - 1 - i] - 'a';
      if (x > y)
        swap(x, y);
      cnt[x][y]++;
    }

    int ans = 1, same = -1;
    for (int i = 0; i < C; i++)
      for (int j = i; j < C; j++)
        if (cnt[i][j] % 2)
        {
          if (i != j) ans = 0;
          else if (same >= 0) ans = 0;
          else same = i;
        }

    if ((n % 2) ^ (same >= 0))
      ans = 0;

    cout << (ans ? "YES" : "NO") << '\n';
  }
}