#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x, zero = 0, product = 1;
  long long ans = 0;
  cin >> n;
  while (n--)
  {
    cin >> x;
    if (x >= 1) ans += x - 1;
    else if (x <= -1)
    {
      ans += -1 - x;
      product *= -1;
    }
    else zero++;
  }
  
  ans += (zero ? zero : 1 - product);
  cout << ans << endl;
}