#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x, p, k;
  map <int, int> cnt;
  long long ans = 0;
  cin >> n >> p >> k;
  while (n--)
  {
    cin >> x;
    long long y = 1;
    for (int i = 0; i < 4; i++)
      y = y * x % p;
    y = (y + 1LL * k * (p - x)) % p;
    ans += cnt[y]++;
  }
  cout << ans << endl;
}