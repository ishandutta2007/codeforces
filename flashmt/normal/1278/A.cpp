#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    string p, h;
    cin >> p >> h;
    sort(p.begin(), p.end());
    string ans = "NO";
    for (int i = 0; i + p.size() <= h.size(); i++)
    {
      string s = h.substr(i, p.size());
      sort(s.begin(), s.end());
      if (s == p)
        ans = "YES";
    }
    cout << ans << endl;
  }
}