#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  string s;
  cin >> n >> k >> s;
  k /= 2;

  string ans;
  int x = 0;
  for (char c : s)
    if (c == '(')
    {
      if (k)
      {
        x++;
        cout << c;
        k--;
      }
    }
    else if (x)
    {
      x--;
      cout << c;
    }
}