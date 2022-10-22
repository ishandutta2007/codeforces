#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    vector<vector<int> > nxt(2, vector<int>(2, n));
    vector<int> e(n +1, 0);
    e[n] = n;
    for (int i = n-1; i >=0;i--)
    {
      e[i] = e[i+1];
      if (s[i] != '?')
      {
        int b = s[i]-'0';
        e[i] = min({e[i], nxt[(i&1)][b^1], nxt[(i&1)^1][b]});
        nxt[i&1][b] = i;
      }
      ans += e[i] - i;
    }
    cout << ans << "\n";
  }
  return 0;
}