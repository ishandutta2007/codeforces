#include <bits/stdc++.h>
using namespace std;

long long brute(long long w0, long long w1, long long v0, long long v1, long long c)
{
  long long ans = 0;
  for (int i = 0; i * w0 <= c; i++)
    ans = max(ans, i * v0 + (c - i * w0) / w1 * v1);
  return ans;
}

int main()
{
  ios::sync_with_stdio(0);
  long long c, hr, hb, wr, wb;
  cin >> c >> hr >> hb >> wr >> wb;
  
  long long ans = 0;
  if (wr >= 1000) ans = brute(wr, wb, hr, hb, c);
  else if (wb >= 1000) ans = brute(wb, wr, hb, hr, c);
  else
  {
    long long L = wr * wb / __gcd(wr, wb);
    if (c / L > 1)
    {
      ans = (c / L - 1) * brute(wr, wb, hr, hb, L);
      c = c % L + L;
    }
    ans += brute(wr, wb, hr, hb, c);
  }
  
  cout << ans << endl;
}