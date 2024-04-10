#include <bits/stdc++.h>
using namespace std;

int n, sz[200200];
vector <int> a[200200];
long long fDown[200200], fUp[200200], ans;

void visit(int x, int par)
{
  sz[x] = 1;
  for (int y : a[x])
    if (y != par)
    {
      visit(y, x);
      sz[x] += sz[y];
      fDown[x] += fDown[y];
    }
  fDown[x] += sz[x];
}

void visit2(int x, int par)
{
  int isLeaf = 1;
  for (int y : a[x])
    if (y != par)
    {
      fUp[y] = fUp[x] - sz[y] * 2 + n;
      isLeaf = 0;
      visit2(y, x);
    }

  if (isLeaf)
    ans = max(ans, fUp[par] - fDown[x] - sz[x] + n);
}

int main()
{
  int x, y;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  visit(1, 0);
  ans = fUp[1] = fDown[1];
  visit2(1, 0);
  cout << ans << endl;
}