#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n, p, w, d;
  cin >> n >> p >> w >> d;

  for (int i = 0; i <= min(100000LL, n); i++)
  {
    long long rem = p - d * i;
    if (rem < 0 || rem % w)
      continue;
    if (rem / w + i <= n)
    {
      cout << rem / w << ' ' << i << ' ' << n - rem / w - i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}