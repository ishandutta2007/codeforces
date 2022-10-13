#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  string s, t;
  cin >> m >> n >> s >> t;

  int id = -1;
  for (int i = 0; i < m; i++)
    if (s[i] == '*')
      id = i;

  if (m - 1 > n)
  {
    cout << "NO" << endl;
    return 0;
  }

  if (id < 0)
  {
    cout << (s == t ? "YES" : "NO") << endl;
    return 0;
  }

  int ans = 1;
  for (int i = 0; i < id; i++)
    if (s[i] != t[i])
      ans = 0;
  for (int i = m - 1, j = n - 1; i > id; i--, j--)
    if (s[i] != t[j])
      ans = 0;

  cout << (ans ? "YES" : "NO") << endl;
}