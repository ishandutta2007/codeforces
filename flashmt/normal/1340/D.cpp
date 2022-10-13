#include <bits/stdc++.h>
using namespace std;

vector<int> a[100100];
vector<pair<int, int>> ans;
int maxT;

void visit(int x, int par, int &t)
{
  int tOut = t;
  ans.push_back({x, ++t});
  int children = size(a[x]) - (par >= 0);
  for (int y : a[x])
    if (y != par)
    {
      if (t == maxT)
      {
        t = tOut - children;
        ans.push_back({x, t});
      }
      visit(y, x, t);
      children--;
      ans.push_back({x, ++t});
    }

  if (x && t != tOut)
  {
    t = tOut;
    ans.push_back({x, tOut});
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }
  for (int i = 0; i < n; i++)
    maxT = max(maxT, int(size(a[i])));
  int t = -1;
  visit(0, -1, t);
  cout << size(ans) << '\n';
  for (auto [x, y] : ans)
    cout << x + 1 << ' ' << y << '\n';
}