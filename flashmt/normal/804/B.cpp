#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  long long b = 0, ans = 0;
  for (int i = n - 1; i >= 0; i--)
    if (s[i] == 'b') b = (b + 1) % BASE;
    else
    {
      ans = (ans + b) % BASE;
      b = b * 2 % BASE;
    }
  cout << ans << endl;
}