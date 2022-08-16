#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;


int64 X, K;

int64 mod_pow(int64 x, int64 n, int64 mod) {
  int64 ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}

int main() {
  cin >> X >> K;
  if(X == 0) {
    cout << 0 << endl;
  } else {
    cout << ((1 + (X - 1) * 2) % mod * mod_pow(2, K, mod) + 1) % mod << endl;
  }
}