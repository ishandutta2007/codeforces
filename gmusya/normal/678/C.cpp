#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ll n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  ll cnta = n / a;
  ll cntb = n / b;
  ll cntab = n / ((a * b) / __gcd(a, b));
  cnta -= cntab;
  cntb -= cntab;
  cout << cnta * p + cntb * q + cntab * max(p, q);
  return 0;
}