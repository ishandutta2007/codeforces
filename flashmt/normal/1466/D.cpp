#include <bits/stdc++.h>
using namespace std;

int n, w[100100], deg[100100];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> w[i];
      ans += w[i];
      deg[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      deg[--x]++;
      deg[--y]++;
    }
    cout << ans << ' ';

    vector<int> inc;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < deg[i] - 1; j++)
        inc.push_back(w[i]);

    sort(inc.begin(), inc.end(), greater<int>());
    for (auto x : inc)
    {
      ans += x;
      cout << ans << ' ';
    }

    cout << '\n';
  }
}