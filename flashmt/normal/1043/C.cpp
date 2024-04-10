#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  int ans[1010] = {0};
  for (int i = 1; i < s.size(); i++)
    if (s[i] == 'a')
    {
      ans[i] = 1;
      ans[i - 1] ^= 1;
    }
  for (int i = 0; i < s.size(); i++)
    cout << ans[i] << ' ';
}