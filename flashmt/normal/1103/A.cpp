#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  int ver = 0, hor = 0;
  for (char c : s)
    if (c == '0')
    {
      cout << ver * 2 + 1 << ' ' << 3 << endl;
      ver ^= 1;
    }
    else
    {
      cout << hor + 1 << ' ' << 1 << endl;
      hor = (hor + 1) & 3;
    }
}