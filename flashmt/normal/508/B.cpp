#include <bits/stdc++.h>
using namespace std;

int isEven(char c)
{
  return (c - '0') % 2 == 0;
}

int main()
{
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  
  for (int i = 0; i < s.size(); i++)
    if (isEven(s[i]) && s[i] < s.back())
    {
      swap(s[i], s.back());
      cout << s << endl;
      return 0;
    }
    
  for (int i = int(s.size()) - 2; i >= 0; i--)
    if (isEven(s[i]) && s[i] > s.back())
    {
      swap(s[i], s.back());
      cout << s << endl;
      return 0;
    }
    
  cout << -1 << endl;
}