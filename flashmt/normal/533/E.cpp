#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;

int check(int l, int r)
{
  int res = 0, ok = 1;
  for (int i = l; i < r; i++)
    if (s[i] != t[i + 1])
      ok = 0;
  res += ok;
  
  ok = 1;
  for (int i = l; i < r; i++)
    if (t[i] != s[i + 1])
      ok = 0;
  res += ok;
  
  return res;
}

int main()
{
  cin >> n >> s >> t;
  
  int l = 0, r = n - 1;
  while (s[l] == t[l]) l++;
  while (s[r] == t[r]) r--;
  
  if (l == r) cout << 2 << endl;
  else cout << check(l, r) << endl;
}