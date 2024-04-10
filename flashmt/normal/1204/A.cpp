#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int ans = s.size() / 2;
  if (s.size() % 2)
    for (int i = 1; i < s.size(); i++)
      if (s[i] == '1')
      {
        ans++;
        break;
      }
  cout << ans << endl;
}