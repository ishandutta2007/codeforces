#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll p, a, b, c;
    cin >> p >> a >> b >> c;
    if (p % a == 0 || p % b == 0 || p % c == 0) {
      cout << 0 << '\n';
      continue;
    }
    cout << min({a - p % a, b - p % b, c - p % c}) << '\n';
  }
  return 0;
}