#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int main()
{
  int m, n;
  cin >> m >> n;
  vector<int> a(m + 1, 0), b(n + 1, 0);
  for (int i = 1; i <= m; i++)
  {
    int x;
    cin >> x;
    a[i] = a[i - 1] + x;
  }
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    b[i] = b[i - 1] + x;
  }
  int maxSum;
  cin >> maxSum;

  vector<int> minA(m + 1, oo);
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j <= m; j++)
      minA[j - i] = min(minA[j - i], a[j] - a[i]);

  vector<int> minB(n + 1, oo);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j <= n; j++)
      minB[j - i] = min(minB[j - i], b[j] - b[i]);

  int ans = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (1LL * minA[i] * minB[j] <= maxSum)
        ans = max(ans, i * j);

  cout << ans << endl;
}