#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test, n, a[300300], b[300300];
  long long f[300300][3];
  cin >> test;
  while (test--)
  {
    cin >> n >> a[0] >> b[0];
    f[0][0] = 0;
    f[0][1] = b[0];
    f[0][2] = b[0] * 2;
    for (int i = 1; i < n; i++)
    {
      cin >> a[i] >> b[i];
      for (int j = 0; j < 3; j++)
      {
        f[i][j] = oo;
        for (int k = 0; k < 3; k++)
          if (a[i - 1] + k != a[i] + j)
            f[i][j] = min(f[i][j], f[i - 1][k] + j * b[i]);
      }
    }

    cout << min(f[n - 1][0], f[n - 1][1]) << '\n';
  }
}