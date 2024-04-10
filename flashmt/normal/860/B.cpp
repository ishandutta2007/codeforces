#include <bits/stdc++.h>
using namespace std;

set <int> a[77777][9];
map <int, int> cnt[9];

string solve(int i)
{
  for (int length = 0; length < 9; length++)
    for (int x : a[i][length])
      if (cnt[length][x] == 1)
      {
        string res = "";
        while (x)
        {
          res += char(x % 10 + '0');
          x /= 10;
        }
        while (res.size() <= length)
          res += '0';
        reverse(res.begin(), res.end());
        return res;
      }

  return "";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    for (int j = 0; j < 9; j++)
    {
      int x = 0;
      for (int k = j; k < 9; k++)
      {
        x = x * 10 + s[k] - '0';
        a[i][k - j].insert(x);
      }
    }

    for (int length = 0; length < 9; length++)
      for (int x : a[i][length])
        cnt[length][x]++;
  }

  for (int i = 0; i < n; i++)
    cout << solve(i) << '\n';
}