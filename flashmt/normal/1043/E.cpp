#include <bits/stdc++.h>
using namespace std;

struct Person
{
  int x, y, id;

  bool operator <(Person u)
  {
    return x - y < u.x - u.y;
  }
};

Person a[300300];
long long ans[300300], sumX[300300], sumY[300300];

int main()
{
  ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i].x >> a[i].y;
    a[i].id = i;
  }

  while (m--)
  {
    cin >> u >> v;
    if (a[u].x > a[v].x)
      swap(u, v);
    if (a[u].y > a[v].y || a[v].y - a[u].y < a[v].x - a[u].x)
    {
      ans[u] -= a[u].x + a[v].y;
      ans[v] -= a[u].x + a[v].y;
    }
    else 
    {
      ans[u] -= a[u].y + a[v].x;
      ans[v] -= a[u].y + a[v].x;
    }
  }
  
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
  {
    sumX[i] = sumX[i - 1] + a[i].x;
    sumY[i] = sumY[i - 1] + a[i].y;
  }

  for (int i = 1; i <= n; i++)
  {
    ans[a[i].id] += (i - 1LL) * a[i].y + sumX[i - 1];
    ans[a[i].id] += 1LL * (n - i) * a[i].x + sumY[n] - sumY[i];
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
}