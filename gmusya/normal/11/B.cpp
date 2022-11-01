#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll x;
  cin >> x;
  if (!x) {
    cout << 0;
    return 0;
  }
  x = abs(x);
  int ans = 0;
  while (x > 0 || x % 2) {
    ans += 1;
    x -= ans;
  }
  cout << ans;
  return 0;
}