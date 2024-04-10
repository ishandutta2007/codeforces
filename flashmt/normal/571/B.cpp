#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int n, k, a[300300];
long long f[5050][5050];

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) 
    cin >> a[i];

  sort(a + 1, a + n + 1);
  int r = n % k, each = n / k;

  for (int i = 1; i <= k; i++)
    for (int j = 0; j <= r; j++)
      f[i][j] = oo;

  f[1][0] = a[each] - a[1];
  f[1][1] = a[each + 1] - a[1];

  for (int i = 1; i < k; i++)
    for (int j = 0; j <= r; j++)
    {
      int used = i * each + j;
      f[i + 1][j] = min(f[i + 1][j], f[i][j] + a[used + each] - a[used + 1]);
      if (j < r) 
        f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j] + a[used + each + 1] - a[used + 1]);
    }

  cout << f[k][r] << endl;
}