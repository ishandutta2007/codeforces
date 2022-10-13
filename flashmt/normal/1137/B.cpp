#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s, t;
  cin >> s >> t;

  int pre[500500] = {-1}, i = 0, j = -1;
  while (i < t.size())
  {
    while (j >= 0 && t[i] != t[j])
      j = pre[j];
    pre[++i] = ++j;
  }

  int cntS[2] = {0}, cntT[2] = {0}, suffixT[2] = {0};
  for (auto c : s)
    cntS[c - '0']++;
  for (auto c : t)
    cntT[c - '0']++;
  string suffix = t.substr(pre[t.size()], t.size() - pre[t.size()]);
  for (auto c : suffix)
    suffixT[c - '0']++;

  if (cntT[0] > cntS[0] || cntT[1] > cntS[1])
  {
    cout << s << endl;
    return 0;
  }

  string ans = t;
  cntS[0] -= cntT[0];
  cntS[1] -= cntT[1];
  while (cntS[0] >= suffixT[0] && cntS[1] >= suffixT[1])
  {
    cntS[0] -= suffixT[0];
    cntS[1] -= suffixT[1];
    ans += suffix;
  }
  for (int i = 0; i < 2; i++)
    if (cntS[i])
      ans += string(cntS[i], char('0' + i));

  cout << ans << endl;
}