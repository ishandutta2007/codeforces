#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, cnt[60] = {0};
  long long a[100100];

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    for (int j = 0; j < 60; j++)
      if (a[i] >> j & 1)
        cnt[j]++;
  }

  for (int i = 0; i < 60; i++)
    if (cnt[i] >= 3)
    {
      cout << 3 << endl;
      return 0;
    }

  int id = 0;
  for (int i = 0; i < n; i++)
    if (a[i])
      a[id++] = a[i];
  n = id;
  // there should be at most 120 numbers
  int ans = oo;
  for (int i = 0; i < n; i++)
  {
    vector<int> dist(n, oo), flag(n, 0), from(n, -1);
    queue<int> q;
    q.push(i);
    dist[i] = 0;
    flag[i] = 1;
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      for (int y = 0; y < n; y++)
        if ((a[x] & a[y]) && x != y)
        {
          if (!flag[y])
          {
            dist[y] = dist[x] + 1;
            flag[y] = 1;
            from[y] = x;
            q.push(y);
          }
          else if (y != i && y != from[x])
            ans = min(ans, dist[x] + dist[y] + 1);
        }
    }
  }

  cout << (ans < oo ? ans : -1) << endl;
}