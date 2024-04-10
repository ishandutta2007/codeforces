#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int ds[200200];

int get(int x)
{
  return ds[x] == x ? x : ds[x] = get(ds[x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++)
    {
      int x, y, z;
      cin >> x >> y >> z;
      edges.push_back({z, x, y});
    }
    sort(edges.begin(), edges.end());

    // normal MST
    for (int i = 1; i <= n; i++)
      ds[i] = i;
    long long ans = 0;
    int cnt = 0, closestId = -1, minDiff = oo;
    for (int i = 0; i < m; i++)
    {
      auto [z, x, y] = edges[i];
      if (abs(z - k) < minDiff)
      {
        closestId = i;
        minDiff = abs(z - k);
      }
      int dx = get(x), dy = get(y);
      if (dx != dy)
      {
        ds[dy] = dx;
        cnt++;
        if (z >= k || cnt == n - 1)
          ans += abs(z - k);
      }
    }

    // pick 1 edge closest to k
    for (int i = 1; i <= n; i++)
      ds[i] = i;
    auto [z, x, y] = edges[closestId];
    ds[y] = x;
    long long otherAns = minDiff;
    for (int i = 0; i < m; i++)
    {
      auto [z, x, y] = edges[i];
      int dx = get(x), dy = get(y);
      if (dx != dy)
      {
        ds[dy] = dx;
        otherAns += max(0, z - k);
      }
    }
    ans = min(ans, otherAns);

    cout << ans << endl;
  }
}