#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int g = 0;
    for (int i = 0; i < m; i++)
    {

      int x;
      cin >> x;
      g = gcd(g, x);
    }

    vector<vector<long long>> f(g, {0, -oo});
    for (int i = 0; i < n; i++)
    {
      vector<long long> newF(2, -oo);
      for (int j : {0, 1})
      {
        newF[j] = max(newF[j], f[i % g][j] + a[i]);
        newF[j ^ 1] = max(newF[j ^ 1], f[i % g][j] - a[i]);
      }
      swap(f[i % g], newF);
    }

    vector<long long> ans(2);
    for (int i = 0; i < g; i++)
      for (int j : {0, 1})
        ans[j] += f[i][j];

    cout << max(ans[0], ans[1]) << '\n';
  }
}