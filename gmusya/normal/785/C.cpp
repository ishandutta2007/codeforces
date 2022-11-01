#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ll n, m;
  cin >> n >> m;
  if (n <= m) {
    cout << n;
    return 0;
  }
  n -= m;
  ll L = 0, R = 2e9;
  while (L != R) {
    ll M = (L + R) / 2;
    ll f = M * (M + 1) / 2;
    if (f < n)
      L = M + 1;
    else
      R = M;
  }
  cout << m + L;
  return 0;
}