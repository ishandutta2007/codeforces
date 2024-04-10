#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  int length = s.size();
  for (int i = 0; i < length; i++)
    if (s[i] != s[length - 1 - i])
    {
      cout << length << endl;
      return 0;
    }

  for (int i = 1; i < length; i++)
    if (s[i] != s[i - 1])
    {
      cout << length - 1 << endl;
      return 0;
    }

  cout << 0 << endl;
}