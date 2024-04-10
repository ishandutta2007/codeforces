#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> f(n + 5);
  f[n] = 1;
  for (int i = n - 1; i; i--)
  {
    f[i] = f[i + 1] * 2;
    if (f[i] >= m)
      f[i] -= m;
    for (int j = 2; i * j <= n; j++)
    {
      int to = min(i * j + j - 1, n);
      f[i] += f[i * j] - f[to + 1];
      if (f[i] >= m)
        f[i] -= m;
      if (f[i] < 0)
        f[i] += m;
    }
  }
  cout << (f[1] - f[2] + m) % m << endl;
}