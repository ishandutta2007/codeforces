#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, cnt8 = 0;
  string s;
  cin >> n >> s;
  for (char c : s)
    cnt8 += c == '8';
  for (int i = cnt8; i >= 0; i--)
    if (i * 11 <= n)
    {
      cout << i << endl;
      return 0;
    }
}