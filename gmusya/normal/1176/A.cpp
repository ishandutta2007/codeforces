#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    int ans = 0;
    while (n % 5 == 0) {
      n /= 5;
      ans += 3;
    }
    while (n % 3 == 0) {
      n /= 3;
      ans += 2;
    }
    while (n % 2 == 0) {
      n /= 2;
      ans++;
    }
    if (n > 1)
      ans = -1;
    cout << ans << '\n';
  }
  return 0;
}