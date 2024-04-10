#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll p, y;
  cin >> p >> y;

  bool flag;
  for (ll i = y; i > p; i--) {
    flag = 1;
    ll pp = p*p;
    for (ll j = 2; j*j <= min(pp, i); j++) {
      if (i % j == 0) {
        flag = 0;
        break;
      }
    }

    if (flag) {
      cout << i << endl;
      exit(0);
    }
  }
  cout << -1 << endl;
}