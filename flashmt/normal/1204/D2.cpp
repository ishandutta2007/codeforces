#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  int n = s.size(), dif = 0;
  for (int i = n - 1; i >= 0; i--)
    if (s[i] == '0') dif++;
    else
    {
      dif--;
      if (dif < 0)
      {
        s[i] = '0';
        dif = 0;
      }
    }

  cout << s << endl;
}