#include <bits/stdc++.h>
using namespace std;

int n, m, color[300300], flag[300300];
vector<int> a[300300], iceCream[300300];
set<int> available;

void visit(int x, int par)
{
  for (auto kind : iceCream[x])
    if (color[kind])
      flag[color[kind]] = x;

  int curColor = 1;
  for (auto kind : iceCream[x])
    if (!color[kind])
    {
      while (flag[curColor] == x)
        curColor++;
      color[kind] = curColor++;
    }

  for (int y : a[x])
    if (y != par)
      visit(y, x);
}

int main()
{
  ios::sync_with_stdio(0);
  int x, y, s;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> s;
    while (s--)
    {
      cin >> x;
      iceCream[i].push_back(x);
    }
  }
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  visit(1, 0);

  set<int> usedColor;
  for (int i = 1; i <= m; i++)
  {
    if (!color[i])
      color[i] = 1;
    usedColor.insert(color[i]);
  }
  cout << usedColor.size() << endl;
  for (int i = 1; i <= m; i++)
    cout << color[i] << ' '; 
}