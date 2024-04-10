#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

vector<int> a[N];
int v[N], sumV[N], ans;
unordered_set<int> s[N];

void dfs(int x, int par = -1)
{
  int isGood = 1;
  s[x] = {sumV[x]};
  for (int y : a[x])
    if (y != par)
    {
      sumV[y] = sumV[x] ^ v[y];
      dfs(y, x);
      if (size(s[y]) > size(s[x]))
        swap(s[x], s[y]);
      for (int u : s[y])
        if (s[x].count(u ^ v[x]))
          isGood = 0;
      for (int u : s[y])
        s[x].insert(u);
    }

  if (!isGood)
  {
    ans++;
    s[x].clear();
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  sumV[0] = v[0];
  dfs(0);
  cout << ans << endl;
}