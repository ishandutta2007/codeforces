#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if (a < b) cout << 2LL * c + min(b, a + 1) + a << endl;
  else cout << 2LL * c + min(a, b + 1) + b << endl;
}