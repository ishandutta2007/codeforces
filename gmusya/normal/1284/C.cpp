#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n, mod;
  cin >> n >> mod;
  ll res = 0;
  vector <ll> fact(300'000);
  fact[0] = 1;
  for (int i = 1; i <= 300'000; i++)
    fact[i] = fact[i - 1] * i % mod;
  ll ans = 0;
  for (int len = 1; len <= n; len++) {
    int pos = (n - len + 1);
    ll var = fact[len] * fact[n - len + 1] % mod;
    ans = (ans + pos * var) % mod;
  }
  cout << ans;
  return 0;
}