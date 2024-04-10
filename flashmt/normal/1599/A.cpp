#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(begin(a), end(a));

  string s;
  cin >> s;
  int change = 0;
  for (int i = 1; i < n; i++)
    change += s[i] != s[i - 1];

  int l = n - 1 - change, r = l;
  cout << a[l] << ' ' << s[0] << '\n';
  char leftSide = s[0];
  for (int i = 1; i < n; i++)
    if (s[i] != s[i - 1]) cout << a[++r] << ' ' << s[i] << '\n';
    else
    {
      leftSide ^= 'L' ^ 'R';
      cout << a[--l] << ' ' << leftSide << '\n';
    }
}