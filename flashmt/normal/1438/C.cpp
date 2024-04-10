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
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
      {
        int x;
        cin >> x;
        if (x % 2 == (i + j) % 2) cout << x << ' ';
        else cout << x + 1 << ' ';
        if (j == n - 1)
          cout << '\n';
      }
  }
}