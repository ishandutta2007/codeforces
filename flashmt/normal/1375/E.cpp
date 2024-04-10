#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.push_back({x, i});
  }
  sort(a.begin(), a.end());

  vector<int> b(n);
  for (int i = 0; i < n; i++)
    b[a[i].second] = i;

  vector<pair<int, int>> ans;
  for (int x = n - 1; x >= 0; x--)
  {
    vector<int> larger;
    int i;
    for (i = 0; i < n; i++)
      if (b[i] > x) larger.push_back(i);
      else if (b[i] == x) break;

    for (int j : larger)
    {
      ans.push_back({j, i});
      swap(b[i], b[j]);
    }
  }

  for (int i = 1; i < n; i++)
    assert(b[i - 1] < b[i]);

  cout << ans.size() << '\n';
  for (auto [x, y] : ans)
    cout << x + 1 << ' ' << y + 1 << '\n';
}