#include <iostream>

typedef long long ll;

using namespace std;

ll f(ll a, ll b) {
  if (!b)
    return 0;
  return f(b, a % b) + a / b;
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << f(a, b);
  return 0;
}