#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s[100100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];

  int pre[1000100];
  for (int i = 1; i < n; i++)
  {
    pre[0] = -1;
    int j = 0, k = -1;
    while (j < s[i].size())
    {
      while (k >= 0 && s[i][j] != s[i][k])
        k = pre[k];
      j++;
      k++;
      pre[j] = (k >= s[i].size() || s[i][j] != s[i][k] ? k : pre[k]);
    }

    j = max(0, int(s[0].size()) - int(s[i].size()));
    k = 0;
    while (j < s[0].size())
    {
      while (k >= 0 && s[0][j] != s[i][k])
        k = pre[k];
      j++;
      k++;
    }
    s[0] += s[i].substr(k, s[i].size() - k);
  }

  cout << s[0] << endl;
}