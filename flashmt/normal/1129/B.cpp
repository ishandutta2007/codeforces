#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int k, n = 2000;
  cin >> k;
  int x = (n - k % n) + 251 * n, y = x - (k + x) / n;

  cout << n << endl;
  for (int i = 0; i < n - 2; i++)
    cout << 0 << ' ';
  cout << -y << ' ' << x << endl;
}