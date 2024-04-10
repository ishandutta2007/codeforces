#include <bits/stdc++.h>
using namespace std;
const int Z = 100000;

struct Dancer {
  int id, x, y;

  bool operator <(const Dancer& u)
  {
    if (y != u.y)
      return y > u.y;
    return x < u.x;
  }
};

int n, width, height, curId[200200];
vector <Dancer> dancers[200200];
pair <int, int> ans[100100];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int g, p, t;
  cin >> n >> width >> height;
  for (int i = 0; i < n; i++)
  {
    cin >> g >> p >> t;
    if (g == 1) dancers[p - t + Z].push_back({i, p, 0});
    else dancers[p - t + Z].push_back({i, 0, p});
  }

  for (int delta = 0; delta <= Z * 2; delta++)
  {
    int sz = dancers[delta].size();
    if (!sz) continue;
    sort(dancers[delta].begin(), dancers[delta].end());
    for (int i = 0; i < sz; i++)
    {
      if (!dancers[delta][i].x) dancers[delta][i].x = width;
      else dancers[delta][i].y = height;
      curId[i] = dancers[delta][i].id;
    }
    sort(dancers[delta].begin(), dancers[delta].end());
    for (int i = 0; i < sz; i++)
      ans[curId[i]] = {dancers[delta][i].x, dancers[delta][i].y};
  }

  for (int i = 0; i < n; i++)
    cout << ans[i].first << ' ' << ans[i].second << '\n';
}