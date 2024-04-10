#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b, ll &x, ll &y) {
  if (a % b == 0) {
    x = 1;
    y = 1 - (a / b);
    return b;
  }
  ll x1, y1;
  ll g = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a, b, c, x, y;
  cin >> a >> b >> c;
  if (b == 0)
    swap(a, b);
  ll g = gcd(a, b, x, y);
  if (c % g) {
    cout << -1;
    return 0;
  }
  c = -c;
  x *= (c / g), y *= (c / g);
  x = (x % (b / g) + (b / g)) % (b / g);
  y = (c - a * x) / b;
  cout << x << ' ' << y;
  return 0;
}