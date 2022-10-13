#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, one = 0, zero = 0;
  string s;
  cin >> n >> s;
  for (char c : s)
    if (c == 'n') one++;
    else if (c == 'z') zero++;
  while (one--)
    cout << 1 << ' ';
  while (zero--)
    cout << 0 << ' ';
}