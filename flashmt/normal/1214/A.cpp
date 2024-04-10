#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, d, e;
  cin >> n >> d >> e;
  int ans = n;
  for (int i = 0; i * e * 5 <= n; i++)
    ans = min(ans, (n - i * e * 5) % d);
  cout << ans << endl;
}