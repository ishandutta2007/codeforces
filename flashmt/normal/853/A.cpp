#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, k, c[300300];

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> c[i];

  priority_queue < pair<int, int> > q;
  long long cost = 0, ans[300300];
  for (int i = 1; i <= n + k; i++)
  {
    if (i <= n)
      q.push({c[i], i});
    if (i > k)
    {
      int x = q.top().second;
      q.pop();
      ans[x] = i;
      cost += 1LL * c[x] * (i - x);
    }
  }

  cout << cost << endl;
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " \n"[i == n];
}