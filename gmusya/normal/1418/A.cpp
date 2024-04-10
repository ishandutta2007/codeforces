#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    ll x, y, k;
    cin >> x >> y >> k;
    ll ans = 0;
    ans = k + (k + k * y + x - 3) / (x - 1);
    cout << ans << '\n';
  }
  return 0;
}