#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int n;
  long long a[400400] = {0}, t[200200] = {0}, c;
  cin >> n >> c;
  for (int i = 1; i <= 2 * n - 1; i++)
  {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  set < pair <long long, int> > s;
  s.insert({0, 0});
  for (int i = 1, j = 0; i <= n; i++)
  {
    while (j < i && a[i * 2 - 1] - a[j * 2] > c)
      j++;
    if (j)
      t[i] = t[j - 1] + c;
    while (!s.empty())
    {
      auto u = *s.rbegin();
      if (u.second >= j)
      {
        t[i] = max(t[i], u.first + a[i * 2 - 1]);
        break;
      }
      s.erase(u);
    }
    s.insert({t[i] - a[i * 2], i});
  }

  cout << t[n] << endl;
}