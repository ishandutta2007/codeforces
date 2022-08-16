#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 a, b, c, d;
  cin >> a >> b >> c >> d;

  int64 add = 0;
  add += a * 2;
  if(add == 0 && c > 0) {
    cout << 0 << endl;
    return 0;
  }
  add -= d * 2;
  if(add == 0) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
}