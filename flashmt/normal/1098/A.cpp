#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int n, p[100100], s[100100];
vector<int> a[100100];

void dfs(int x)
{
  int minChild = oo;
  for (int y : a[x])
  {
    dfs(y);
    minChild = min(minChild, s[y]);
  }

  if (s[x] >= 0)
    return;

  if (s[p[x]] > minChild)
  {
    cout << -1 << endl;
    exit(0);
  }
  if (minChild == oo) s[x] = s[p[x]];
  else s[x] = minChild;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 2; i <= n; i++)
  {
    cin >> p[i];
    a[p[i]].push_back(i);
  }

  for (int i = 1; i <= n; i++)
    cin >> s[i];

  dfs(1);
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    ans += s[i] - s[p[i]];
  cout << ans << endl;
}