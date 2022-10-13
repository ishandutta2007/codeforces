#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  set<int> a[100100];
  cin >> n >> m;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[x].insert(y);
    a[y].insert(x);
  }

  set<int> unseen;
  for (int i = 2; i <= n; i++)
    unseen.insert(i);

  int ans = 0;
  vector<int> flag(n + 1, 0), dist(n + 1, 2);
  deque<int> dq;
  dq.push_back(1);
  dist[1] = 0;
  while (!dq.empty())
  {
    int x = dq.front();
    dq.pop_front();
    if (flag[x])
      continue;
    flag[x] = 1;
    ans += dist[x];

    vector<int> toRemove;
    for (int y : unseen)
    {
      int curDist = a[x].count(y);
      if (!flag[y] && curDist < dist[y])
      {
        dist[y] = curDist;
        if (curDist) dq.push_back(y);
        else
        {
          dq.push_front(y);
          toRemove.push_back(y);
        }
      }
    }
    for (int y : toRemove)
      unseen.erase(y);
  }

  cout << ans << endl;
}