#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int main()
{
  ios::sync_with_stdio(0);
  int m, a, b;
  cin >> m >> a >> b;

  priority_queue < pair<long long, int> > q;
  vector <long long> dist(a, oo);
  vector <int> flag(a, 0);
  q.push({0, 0});
  dist[0] = 0;
  while (!q.empty())
  {
    int x = q.top().second;
    q.pop();
    if (flag[x])
      continue;
    flag[x] = 1;

    int y = x - b;
    if (y >= 0)
    {
      if (dist[y] > dist[x])
      {
        dist[y] = dist[x];
        q.push({-dist[y], y});
      }
    }
    else
    {
      long long add = (-y + a - 1) / a;
      y += add * a;
      if (dist[y] > max(x + add * a, dist[x]))
      {
        dist[y] = max(x + add * a, dist[x]);
        q.push({-dist[y], y});
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i < a; i++)
    if (flag[i])
    {
      if (dist[i] > m)
        continue;

      long long repeat = (dist[i] - i) / a;
      ans += (repeat + 1LL) * (m - dist[i] + 1);
      long long val = i + (repeat + 1LL) * a;
      if (val <= m)
      {
        long long repeat2 = (m - val) / a;
        long long last = val + repeat2 * a;
        ans += (repeat2 + 1LL) * (m * 2LL - val - last + 2) / 2;
      }
    }
  cout << ans << endl;  
}