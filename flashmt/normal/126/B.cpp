#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string s)
{
  int n = size(s);
  vector<int> pre(n);
  pre[0] = -1;
  for (int i = 0, j = -1; i < n; i++)
  {
    while (j >= 0 && s[i] != s[j])
      j = j ? pre[j - 1] + 1 : -1;
    pre[i] = j++;
  }
  return pre;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = size(s);

  auto pre = prefixFunction(s);
  vector<int> seen(n);
  for (int i = 0; i < n - 1; i++)
    if (pre[i] >= 0)
      seen[pre[i]] = 1;

  int ans = pre[n - 1];
  while (ans >= 0)
    if (seen[ans]) break;
    else ans = pre[ans];
  ans++;

  cout << (ans ? s.substr(0, ans) : "Just a legend") << endl;
}