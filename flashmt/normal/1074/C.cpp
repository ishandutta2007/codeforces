#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x[300300], y[300300];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];

  int minX = *min_element(x, x + n), maxX = *max_element(x, x + n);
  int minY = *min_element(y, y + n), maxY = *max_element(y, y + n);

  vector<int> a;
  for (int i = 0; i < n; i++)
    if (x[i] == minX || x[i] == maxX || y[i] == minY || y[i] == maxY)
      a.push_back(i);

  int ans3 = 0;
  for (int i = 0; i < a.size(); i++)
    for (int j = i + 1; j < a.size(); j++)
      for (int k = 0; k < n; k++)
        if (k != a[i] && k != a[j])
        {
          int perimeter = abs(x[a[i]] - x[a[j]]) + abs(y[a[i]] - y[a[j]]);
          perimeter += abs(x[a[i]] - x[k]) + abs(y[a[i]] - y[k]);
          perimeter += abs(x[k] - x[a[j]]) + abs(y[k] - y[a[j]]);
          ans3 = max(ans3, perimeter);
        }

  cout << ans3 << ' ';
  for (int i = 4; i <= n; i++)
    cout << (maxX - minX + maxY - minY) * 2 << " \n"[i == n];
}