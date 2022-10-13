#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;

  vector<vector<int>> cnt(2, vector<int>(n));
  for (int i = 1; i < n; i++)
    for (int v : {0, 1})
      cnt[v][i] = cnt[v][i - 1] + (s[i] == s[i - 1] && s[i] - '0' == v);

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    l--; r--;
    cout << max(cnt[0][r] - cnt[0][l], cnt[1][r] - cnt[1][l]) + 1 << '\n';
  }
}