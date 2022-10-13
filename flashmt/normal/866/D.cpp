#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  long long ans = 0;
  set<pair<int, int>> s = {{oo, -1}};
  vector<int> sold(n);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    auto [y, id] = *begin(s);
    if (y < x)
    {
      ans += x - y;
      if (!sold[id]) s.erase({y, id});
      else sold[id] = 0;
      sold[i] = 1;
    }
    s.insert({x, i});
  }
  cout << ans << endl;
}