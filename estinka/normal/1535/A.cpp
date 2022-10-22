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
    vector<int> s(4);
    for (int i = 0; i < 4;i++) cin >> s[i];
    int a = max(s[0], s[1]), b = max(s[2], s[3]);
    if (a > b) swap(a, b);
    sort(s.begin(), s.end());
    cout << ((s[2] == a && s[3] == b) ? "YES\n" : "NO\n");
  }
  return 0;
}