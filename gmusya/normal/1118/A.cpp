#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, a, b;
    cin >> n >> a >> b;
    b = min(b, 2 * a);
    cout << n % 2 * a + n / 2 * b << '\n';
  }
  return 0;
}