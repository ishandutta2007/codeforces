#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  if((a + b + c + d + e) % 5 == 0) {
    if((a + b + c + d + e) / 5 == 0) cout << -1 << endl;
    else cout << (a + b + c + d + e) / 5 << endl;
  } else {
    cout << -1 << endl;
  }
}