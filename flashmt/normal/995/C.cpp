#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> x(n), y(n);
  vector<int> id(n), ans(n, 1);
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i];
    if (x[i] < 0)
    {
      x[i] = -x[i];
      y[i] = -y[i];
      ans[i] = -1; 
    }
    id[i] = i;
  }
 
  sort(begin(id), end(id), [&](int u, int v) { return x[u] > x[v] || (x[u] == x[v] && y[u] > y[v]); });
  long long curX = 0, curY = 0;
  for (int u : id)
  {
    long long x0 = curX + x[u], y0 = curY + y[u];
    long long x1 = curX - x[u], y1 = curY - y[u];
    if (x0 * x0 + y0 * y0 < x1 * x1 + y1 * y1)
    {
      curX = x0;
      curY = y0;
    }
    else
    {
      ans[u] *= -1;
      curX = x1;
      curY = y1;
    }
  }
 
  for (int x : ans)
    cout << x << ' ';
}