#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ll n, m, s;
  cin >> n >> m >> s;
  ll a = n / s * (n % s ? n % s : s) + n % s;
  ll b = m / s * (m % s ? m % s : s) + m % s;
  cout << a * b;
  return 0;
}