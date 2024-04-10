#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, d, m, x, y;
  cin >> n >> d >> m;
  while (m--)
  {
    cin >> x >> y;
    cout << (d <= x + y && x + y <= n * 2 - d && abs(x - y) <= d ? "YES" : "NO") << endl;  
  }
}