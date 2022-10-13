#include <bits/stdc++.h>
using namespace std;

int n, a[500500], f[500500], pos[500500];
vector<int> ids[500500];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    pos[i] = ids[a[i]].size();
    ids[a[i]].push_back(i);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    int x = a[i];
    if (ids[x].back() == i)
      f[i] = f[ids[x][0] - 1] + ids[x].size();
    f[i] = max(f[i], f[i - 1]);
    ans = max(ans, f[i - 1] + int(ids[x].size()) - pos[i]);
  }

  cout << n - ans << endl;
}