#include <bits/stdc++.h>
using namespace std;

int n, p[6666], ans;
vector <int> a[6666], lis;

void visit(int x, int par)
{
  int replacedId = -1, replacedValue = -1, oldSize = lis.size();
  if (lis.empty() || p[x] > lis.back()) lis.push_back(p[x]);
  else
  {
    replacedId = lower_bound(lis.begin(), lis.end(), p[x]) - lis.begin();
    replacedValue = lis[replacedId];
    lis[replacedId] = p[x];
  }
  ans = max(ans, int(lis.size()));
  
  for (int i = 0; i < int(a[x].size()); i++)
  {
    int y = a[x][i];
    if (y == par) continue;
    visit(y, x);
  }
  
  if (oldSize != lis.size()) lis.resize(oldSize);
  if (replacedId >= 0)
    lis[replacedId] = replacedValue;
}

int main()
{
  ios::sync_with_stdio(0);
  int x, y;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  
  for (int i = 1; i <= n; i++)
  {
    lis.clear();
    visit(i, 0);
  }
  
  cout << ans << endl;
}