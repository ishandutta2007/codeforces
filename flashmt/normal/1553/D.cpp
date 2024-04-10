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
    string s, t;
    cin >> s >> t;
    int m = size(s), n = size(t);
    vector<int> a[2][26];
    int cur[2][26];
    for (int i = 0; i < m; i++)
      a[i % 2][s[i] - 'a'].push_back(i);

    int ans = 0;
    for (int ii = 0; ii < 2; ii++)
    {
      memset(cur, 0, sizeof cur);
      int i = ii, last = -1, j = 0;
      while (j < n)
      {
        int c = t[j] - 'a';
        while (cur[i][c] < size(a[i][c]) && a[i][c][cur[i][c]] <= last)
          cur[i][c]++;
        if (cur[i][c] == size(a[i][c]))
          break;
        last = a[i][c][cur[i][c]++];
        j++;
        i ^= 1;
      }

      ans |= j == n && last % 2 == (m - 1) % 2;
    }

    cout << (ans ? "YES\n" : "NO\n");
  }
}