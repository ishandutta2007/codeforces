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
    int n, m, x;
    vector<int> id[10100];
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
    {
      int h;
      cin >> h;
      id[h].push_back(i);
    }

    set<pair<int, int>> towers;
    for (int i = 0; i < m; i++)
      towers.insert({0, i});

    vector<int> ans(n);
    for (int h = x; h; h--)
      for (int i : id[h])
      {
        auto u = *towers.begin();
        towers.erase(u);
        ans[i] = u.second;
        u.first += h;
        towers.insert(u);
      }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
      cout << ans[i] + 1 << " \n"[i == n - 1];
  }
}