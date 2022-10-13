#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  auto solve = [&](auto self, int low, int high)
  {
    if (low >= high)
      return vector<long long>(1);

    vector<long long> f(high - low + 1);
    int mid = low;
    for (int i = low + 1; i < high; i++)
      if (a[i] < a[mid])
        mid = i;

    auto fLeft = self(self, low, mid);
    auto fRight = self(self, mid + 1, high);

    for (int i = 0; i < size(fLeft); i++)
      for (int j = 0; j < size(fRight); j++)
        {
          f[i + j] = max(f[i + j], fLeft[i] + fRight[j] - 2LL * i * j * a[mid]);
          f[i + j + 1] = max(f[i + j + 1], fLeft[i] + fRight[j] + (m - 1LL - 2 * i * j - 2 * i - 2 * j) * a[mid]);
        }

    return f;
  };

  auto f = solve(solve, 0, n);
  cout << f[m] << endl;
}