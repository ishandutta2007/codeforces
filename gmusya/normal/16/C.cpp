#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) {
  if (a % b) return gcd(b, a % b);
  return b;
}

int main() {
  ll a, b, x, y;
  cin >> a >> b >> x >> y;
  {
    ll g = gcd(x, y);
    x /= g, y /= g;
  }
  ll x1, y1;
  {
    ll a1 = a, b1 = b;
    ll k = min(a1 / x, b1 / y);
    x1 = k * x, y1 = k * y;
  }
  /*ll x2, y2;
  {
    ll a1 = b, b1 = a;
    ll k = min(a1 / x, b1 / y);
    cout << "k = " << k << endl;x
    x2 = k * x, y2 = k * y;
  }*/
  cout << x1 << ' ' << y1;
  return 0;
}