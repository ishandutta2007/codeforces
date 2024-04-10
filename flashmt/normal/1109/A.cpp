#include <bits/stdc++.h>
using namespace std;

int cnt[2][1 << 20];

int main()
{
  ios::sync_with_stdio(0);
  int n, x, sumXor = 0;
  cin >> n;
  cnt[0][sumXor]++;
  long long ans = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    sumXor ^= x;
    ans += cnt[i & 1][sumXor]++;
  }
  cout << ans << endl;
}