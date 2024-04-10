#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll binp(ll a, ll p) {
  if (!p)
    return 1;
  if (p & 1)
    return a * binp(a, p - 1) % MOD;
  ll x = binp(a, p / 2);
  return x * x % MOD;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 1 || k > n)
    cout << binp(m, n);
  else if (k == n)
    cout << binp(m, (n + 1) / 2);
  else
    cout << binp(m, k % 2 + 1);
  return 0;
}