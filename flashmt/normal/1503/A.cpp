#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    string s;
    int n;
    cin >> n >> s;
    int open = n / 2, cnt = 0;
    string a(n, ' '), b(n, ' ');
    for (int i = 0; i < n; i++)
      if (s[i] == '0')
      {
        if (!cnt)
        {
          a[i] = '(';
          b[i] = ')';
          open--;
        }
        else
        {
          a[i] = ')';
          b[i] = '(';
        }
        cnt ^= 1;
      }

    if (cnt)
    {
      cout << "NO\n";
      continue;
    }

    for (int i = 0; i < n; i++)
      if (s[i] == '1')
      {
        if (open)
        {
          a[i] = b[i] = '(';
          open--;
        }
        else a[i] = b[i] = ')';
      }

    int isGood = 1;
    for (int i = 0, cntA = 0, cntB = 0; i < n; i++)
    {
      if (a[i] == '(') cntA++;
      else cntA--;
      if (b[i] == '(') cntB++;
      else cntB--;
      if (cntA < 0 || cntB < 0)
        isGood = 0;
    }

    if (!isGood) cout << "NO\n";
    else
    {
      cout << "YES\n";
      cout << a << '\n' << b << '\n';
    }
  }
}