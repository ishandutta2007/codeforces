#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;
const int BASE = 998244353;
const int EVEN = 20;
const int ODD = 21;

int n, flag[200200][22];
vector<int> a[200200][2];
pair<int, int> dist[200200][22];
set<tuple<int, int, int>> q[22];

bool isBetter(pair<int, int> u, pair<int, int> v)
{
  if (max(u.first, v.first) < EVEN)
    return (1 << u.first) + u.second < (1 << v.first) + v.second;
  return u < v;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m;
  cin >> n >> m;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[x][0].push_back(y);
    a[y][1].push_back(x);
  }

  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= ODD; j++)
    {
      dist[i][j] = {oo, oo};
      flag[i][j] = 0;
    }

  dist[1][0] = {0, 0};
  q[0].insert({0, 0, 1});
  int numFlip = 0;
  pair<int, int> best(oo, oo);
  while (1)
  {
    if (q[numFlip].empty())
    {
      if (numFlip >= EVEN && q[numFlip ^ 1].empty())
      break;

      if (numFlip < EVEN) numFlip++;
      else numFlip ^= 1;
      continue;
    }

    auto tuple = *q[numFlip].begin();
    int flip = get<0>(tuple);
    int step = get<1>(tuple);
    int x = get<2>(tuple);
    q[numFlip].erase(tuple);

    if (x == n && isBetter(dist[x][numFlip], best))
      best = dist[x][numFlip];

    if (flag[x][numFlip])
      continue;
    flag[x][numFlip] = 1;

    // transpose
    pair<int, int> newDist(flip + 1, step);
    int newNumFlip = numFlip < EVEN ? numFlip + 1 : numFlip ^ 1;
    if (isBetter(newDist, dist[x][newNumFlip]))
    {
      dist[x][newNumFlip] = newDist;
      q[newNumFlip].insert({flip + 1, step, x});
    }

    // move
    for (int y : a[x][numFlip % 2])
    {
      pair<int, int> newDist(flip, step + 1);
      if (isBetter(newDist, dist[y][numFlip]))
      {
        dist[y][numFlip] = newDist;
        q[numFlip].insert({flip, step + 1, y});
      }
    }
  }

  int ans = 1;
  for (int i = 0; i < best.first; i++)
    ans = ans * 2 % BASE;
  ans = (ans + best.second - 1) % BASE;
  cout << ans << endl;
}