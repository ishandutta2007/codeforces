#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int cnt[10][3] = {0};
  while (cin >> s)
  {
    if (s[1] == 'm') cnt[s[0] - '0'][0]++;
    else if (s[1] == 'p') cnt[s[0] - '0'][1]++;
    else cnt[s[0] - '0'][2]++;
  }
  
  int ans = 2;
  for (int i = 1; i < 10; i++)
    for (int j = 0; j < 3; j++)
      ans = min(ans, 3 - cnt[i][j]);
  
  for (int j = 0; j < 3; j++)
  {
    int cur = 0;
    for (int i = 1; i < 10; i++)
      if (cnt[i][j]) ans = min(ans, 3 - (++cur));
      else cur = 0;
    for (int i = 2; i < 9; i++)
      if (cnt[i - 1][j] && cnt[i + 1][j])
        ans = min(ans, 1);
  }
  
  cout << ans << endl;
}