#include <bits/stdc++.h>
using namespace std;

int isGood(vector<string> &a, vector<string> &b)
{
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < a[i].size(); j++)
      if (a[i][j] != '.' && a[i][j] != b[i][j])
        return 0;
  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int m, n;
    cin >> m >> n;
    vector<string> a(m);
    for (int i = 0; i < m; i++)
      cin >> a[i];

    vector<string> b[2];
    for (int i = 0; i < m; i++)
    {
      string s[2];
      for (int j = 0; j < n; j++)
        if (i % 2 == j % 2)
        {
          s[0] += 'R';
          s[1] += 'W';
        }
        else
        {
          s[0] += 'W';
          s[1] += 'R';
        }
      b[0].push_back(s[0]);
      b[1].push_back(s[1]);
    }

    int found = 0;
    for (int k = 0; k < 2; k++)
      if (isGood(a, b[k]))
      {
        cout << "YES\n";
        for (int i = 0; i < m; i++)
          cout << b[k][i] << '\n';
        found = 1;
        break;
      }

    if (!found)
      cout << "NO\n";
  }
}