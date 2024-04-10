#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n), b(n);
  vector<int> degOut(n);
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    degOut[x]++;
    b[y].push_back(x);
  }

  vector<int> dist(n, oo), done(n);
  dist[n - 1] = 0;
  set<pair<int, int>> s;
  s.insert({0, n - 1});
  while (!empty(s))
  {
    auto [_, x] = *begin(s);
    s.erase(begin(s));
    if (done[x])
      continue;
    done[x] = 1;

    for (int y : b[x])
    {
      degOut[y]--;
      if (dist[x] + 1 + degOut[y] < dist[y])
      {
        dist[y] = dist[x] + 1 + degOut[y];
        s.insert({dist[y], y});
      }
    }
  }

  cout << dist[0] << endl;
}