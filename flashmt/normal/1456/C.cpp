#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k, a[500500];
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);

  long long sum[500500] = {0};
  for (int i = 1; i <= n; i++)
    sum[i] = sum[i - 1] + a[i];

  vector<vector<int>> blocks(k + 1, vector<int>());
  for (int i = 0; i <= n; i++)
    if (sum[n] - sum[i] >= 0)
    {
      for (int j = 1; j <= i; j++)
        blocks[(j - 1) % (k + 1)].push_back(a[j]);
      for (int j = i + 1; j <= n; j++)
        blocks[0].push_back(a[j]);
      break;
    }

  long long ans = 0;
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < blocks[i].size(); j++)
      ans += 1LL * j * blocks[i][j];

  cout << ans << endl;
}