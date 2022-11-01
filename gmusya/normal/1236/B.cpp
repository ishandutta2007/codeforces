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
  int n, m;
  cin >> n >> m;
  ll ans1 = binp(2, m) - 1;
  ll ans2 = binp(ans1, n);
  cout << ans2;
}