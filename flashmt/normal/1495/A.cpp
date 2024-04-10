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
    vector<int> ox, oy;
    for (int i = 0; i < n * 2; i++)
    {
      int x, y;
      cin >> x >> y;
      if (!x) oy.push_back(abs(y));
      else ox.push_back(abs(x));
    }

    sort(ox.begin(), ox.end());
    sort(oy.begin(), oy.end());

    double ans = 0;
    for (int i = 0; i < n; i++)
      ans += sqrt(1. * ox[i] * ox[i] + 1. * oy[i] * oy[i]);
    cout << fixed << setprecision(12) << ans << '\n';
  }
}