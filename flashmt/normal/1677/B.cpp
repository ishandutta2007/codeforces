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
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> sum(n * m + 1);
    for (int i = 0; i < n * m; i++)
      sum[i + 1] = sum[i] + s[i] - '0';

    vector<int> ans(n * m);
    for (int i = 0; i < n * m; i++)
      if (i < m) ans[i] = sum[i + 1] > 0;
      else ans[i] = ans[i - m] + (sum[i + 1] > sum[i + 1 - m]);

    vector<int> col(m);
    int numCol = 0;
    for (int i = 0; i < n * m; i++)
    {
      if (s[i] == '1' && !col[i % m])
      {
        col[i % m] = 1;
        numCol++;
      }
      ans[i] += numCol;
    }

    for (int x : ans)
      cout << x << ' ';
    cout << '\n';
  }
}