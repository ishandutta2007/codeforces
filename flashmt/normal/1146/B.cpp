#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  int cntA = 0, n = s.size();
  for (int i = 0; i < n; i++)
    cntA += s[i] == 'a';

  int remaining = n - cntA;
  if (remaining % 2)
  {
    cout << ":(\n";
    return 0;
  }

  int half = remaining / 2;
  for (int i = 1; i <= half; i++)
    if (s[n - i] == 'a')
    {
      cout << ":(\n";
      return 0;
    }
      
  for (int i = 0, j = n - half; i < n - half; i++)
    if (s[i] != 'a')
    {
      if (s[i] != s[j])
      {
        cout << ":(\n";
        return 0;
      }
      j++;
    }

  cout << s.substr(0, n - half) << endl;
}