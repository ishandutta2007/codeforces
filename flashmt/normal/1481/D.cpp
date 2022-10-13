#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, m;
string a[1010];

void solve()
{
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i][j] == a[j][i])
      {
        cout << "YES\n";
        for (int k = 0; k <= m; k++)
          cout << (k % 2 ? i : j) + 1 << " \n"[k == m];
        return;
      }

  if (m % 2)
  {
    cout << "YES\n";
    for (int i = 0; i <= m; i++)
      cout << (i % 2 + 1) << " \n"[i == m];
    return;
  }

  for (int i = 0; i < n; i++)
  {
    int hasIn[2] = {-1, -1}, hasOut[2] = {-1, -1};
    for (int j = 0; j < n; j++)
      if (i != j)
        hasIn[a[j][i] - 'a'] = hasOut[a[i][j] - 'a'] = j;

    for (int c = 0; c < 2; c++)
      if (hasIn[c] >= 0 && hasOut[c] >= 0)
      {
        vector<int> pattern;
        if (m / 2 % 2) pattern = {hasIn[c], i, hasOut[c], i};
        else pattern = {i, hasIn[c], i, hasOut[c]};

        cout << "YES\n";
        for (int j = 0; j <= m; j++)
          cout << pattern[j % pattern.size()] + 1 << " \n"[j == m];
        return;
      }
  }

  cout << "NO\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    solve();
  }
}