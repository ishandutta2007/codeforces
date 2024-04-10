#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

int main()
{
  ios::sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  long long ans = 0;
  for (int r = 1; r < b; r++)
  {
    ans += a * (a + 1LL) / 2 % BASE * r % BASE * b % BASE + 1LL * a * r % BASE;
    ans %= BASE;
  }
  cout << ans << endl;
}