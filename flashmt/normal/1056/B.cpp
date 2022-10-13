#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  long long ans = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++)
      if ((i * i + j * j) % m == 0)
      {
        int row = n / m + (n % m >= i);
        int col = n / m + (n % m >= j);
        ans += 1LL * row * col;
      }

  cout << ans << endl;
}