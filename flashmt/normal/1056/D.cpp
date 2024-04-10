#include <bits/stdc++.h>
using namespace std;

int n, leaves[100100], cnt[100100];
vector<int> a[100100];

void dfs(int x)
{
  if (a[x].empty()) leaves[x] = 1;
  else
    for (int y : a[x])
    {
      dfs(y);
      leaves[x] += leaves[y];
    }
  cnt[leaves[x]]++;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 2; i <= n; i++)
  {
    int p;
    cin >> p;
    a[p].push_back(i);
  }
  dfs(1);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= cnt[i]; j++)
      cout << i << ' ';
}