#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll ans = 1;
    for (ll i = 1; i * i < 4 * n; i++)
      ans = i;
    cout << ans - 1 << '\n';
  }
  return 0;
}