#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll k = min(a, b);
  a -= k;
  b -= k;
  c += k;
  cout << 2 * c + (a || b);
  return 0;
}