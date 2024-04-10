#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, x, y, ans = 0;
  cin >> n;
  while (n--) cin >> x >> y, ans += x + 1 < y;
  cout << ans << endl;
}