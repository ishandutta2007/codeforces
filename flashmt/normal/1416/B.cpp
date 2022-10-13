#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];

    int sum = accumulate(begin(a) + 1, end(a), 0);
    if (sum % n)
    {
      cout << "-1\n";
      continue;
    }

    int each = sum / n;
    vector<tuple<int, int, int>> ans;
    for (int i = 2; i <= n; i++)
    {
      if (a[i] % i)
      {
        int x = i - a[i] % i;
        assert(a[1] >= x);
        a[1] -= x;
        a[i] += x;
        ans.push_back({1, i, x});
      }

      int x = a[i] / i;
      a[1] += a[i];
      a[i] = 0;
      ans.push_back({i, 1, x});
    }

    for (int i = 2; i <= n; i++)
      if (a[i] < each)
      {
        int x = each - a[i];
        a[1] -= x;
        ans.push_back({1, i, x});
      }

    assert(a[1] == each);
    cout << ans.size() << '\n';
    for (auto [i, j, x] : ans)
      cout << i << ' ' << j << ' ' << x << '\n';
  }
}