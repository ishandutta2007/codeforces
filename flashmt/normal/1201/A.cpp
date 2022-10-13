#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, a[1010];
  string s[1010];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int i = 0; i < m; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < m; i++)
  {
    int cnt[5] = {0};
    for (int j = 0; j < n; j++)
      cnt[s[j][i] - 'A']++;
    int cntMax = *max_element(cnt, cnt + 5);
    ans += cntMax * a[i];
  }

  cout << ans << endl;
}