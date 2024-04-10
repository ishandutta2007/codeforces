#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  map<int, int> cnt;
  while (n--)
  {
    string s;
    cin >> s;
    int x = 0, minX = 0;
    for (auto c : s)
    {
      if (c == '(') x++;
      else x--;
      minX = min(minX, x);
    }

    if ((x >= 0 && minX >= 0) || (x < 0 && minX >= x))
      cnt[x]++;
  }

  int ans = cnt[0] / 2;
  for (auto u : cnt)
    if (u.first > 0)
      ans += min(u.second, cnt[-u.first]);
  cout << ans << endl;
}