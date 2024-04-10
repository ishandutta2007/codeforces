#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

long long f[100100];

int main()
{
  ios::sync_with_stdio(0);
  int t, k, x, y;
  cin >> t >> k;
  
  f[0] = 1;
  for (int i = 1; i <= 100000; i++)
  {
    f[i] = f[i - 1];
    if (i >= k) f[i] = (f[i] + f[i - k]) % BASE;
  }
  
  for (int i = 1; i <= 100000; i++) f[i] = (f[i] + f[i - 1]) % BASE;
  
  while (t--)
  {
    cin >> x >> y;
    cout << (f[y] - f[x - 1] + BASE) % BASE << '\n';
  }
}