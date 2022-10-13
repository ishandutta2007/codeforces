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
    int n, k;
    string s;
    cin >> n >> k >> s;
    string target(n, '(');
    for (int i = 0; i < k - 1; i++)
      target[i * 2 + 1] = ')';
    for (int i = 0; i < n / 2 - k + 1; i++)
      target[n - 1 - i] = ')';

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
      if (s[i] != target[i])
      {
        int found = -1;
        for (int j = i + 1; j < n; j++)
          if (s[j] == target[i])
          {
            found = j;
            break;
          }
        assert(found >= 0);

        ans.push_back({i, found});
        for (int l = i, r = found; l < r; l++, r--)
          swap(s[l], s[r]);
      }

    cout << ans.size() << '\n';
    for (auto [l, r] : ans)
      cout << l + 1 << ' ' << r + 1 << '\n';
  }
}