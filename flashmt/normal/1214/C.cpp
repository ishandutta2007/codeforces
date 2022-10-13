#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;
  for (int i = n - 1; i; i--)
    if (s[i] == '(')
    {
      rotate(s.begin(), s.begin() + i, s.begin() + i + 1);
      break;
    }

  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '(') cnt++;
    else if (!cnt--)
    {
      cout << "No" << endl;
      return 0;
    }

  cout << (!cnt ? "Yes" : "No") << endl;
}