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
    int m, n, d[200] = {0};
    cin >> m >> n;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
      {
        int x;
        cin >> x;
        d[i + j] ^= x;
      }

    string ans = "Jeel";
    for (int i = 0; i < m + n - 1; i++)
      if (d[i])
        ans = "Ashish";
    cout << ans << endl;
  }
}