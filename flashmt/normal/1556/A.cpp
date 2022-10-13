#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int a, b;
    cin >> a >> b;
    if ((a + b) % 2) cout << -1 << '\n';
    else if (a == b) cout << (a > 0) << '\n';
    else cout << 2 << '\n';
  }
}