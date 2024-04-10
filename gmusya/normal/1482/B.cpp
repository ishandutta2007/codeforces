#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, m, x;
    cin >> n >> m >> x;
    ll a = (x - 1) / n, b = (x - 1) % n;
    cout << b * m + a + 1 << '\n';
  }
  return 0;
}