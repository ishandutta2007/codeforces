#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int r, n;
  cin >> r >> n;
  vector<int> t(n + 1), x(n + 1), y(n + 1), f(n + 1, -oo), maxF(n + 1, -oo);
  x[0] = y[0] = 1;
  f[0] = maxF[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> t[i] >> x[i] >> y[i];
    for (int j = i - 1; j >= 0; j--)
      if (t[i] - t[j] >= 1000)
      {
        f[i] = max(f[i], maxF[j] + 1);
        break;
      }
      else if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
      {
        f[i] = max(f[i], f[j] + 1);
      }

    maxF[i] = max(maxF[i - 1], f[i]);
  }
  cout << maxF[n] << endl;
}