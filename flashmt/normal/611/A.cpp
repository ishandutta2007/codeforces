#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x;
  string s, t;
  cin >> x >> s >> t;
  if (t == "week")
    cout << (x == 5 || x == 6 ? 53 : 52) << endl;
  else
  {
    if (x <= 29) cout << 12 << endl;
    else if (x == 30) cout << 11 << endl;
    else cout << 7 << endl;
  }
}