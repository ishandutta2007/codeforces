#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> sz(n);
  vector<vector<int>> a(n);
  vector<long long> sum(n);
  for (int i = 0; i < n; i++)
  {
    cin >> sz[i];
    a[i].resize(sz[i]);
    for (int j = 0; j < sz[i]; j++)
    {
      cin >> a[i][j];
      sum[i] += a[i][j];
    }
  }

  long long ans = 0;

  auto solve = [&](auto self, int low, int high, vector<long long> f)
  {
    if (low == high)
    {
      ans = max(ans, f[k]);
      long long curSum = 0;
      for (int i = 1; i <= min(sz[low], k); i++)
      {
        curSum += a[low][i - 1];
        ans = max(ans, f[k - i] + curSum);
      }
      return;
    }

    int mid = (low + high) / 2;

    vector<long long> newF = f;
    for (int i = mid + 1; i <= high; i++)
      for (int j = k; j >= sz[i]; j--)
        newF[j] = max(newF[j], newF[j - sz[i]] + sum[i]);
    self(self, low, mid, newF);

    swap(newF, f);
    for (int i = low; i <= mid; i++)
      for (int j = k; j >= sz[i]; j--)
        newF[j] = max(newF[j], newF[j - sz[i]] + sum[i]);
    self(self, mid + 1, high, newF);
  };

  solve(solve, 0, n - 1, vector<long long>(k + 1));
  cout << ans << endl;
}