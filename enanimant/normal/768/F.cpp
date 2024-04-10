// March 31, 2020
// https://codeforces.com/contest/768/problem/F

/*

*/


#include <bits/stdc++.h>

using namespace std;


const long long MOD = 1e9 + 7;
const int MAX = 200005;

int inv[MAX];
long long fact[MAX];
long long ifact[MAX];

long long choose(int n, int k) {
  assert(k >= 0 && n < MAX);
  if (n < k) {
    return 0;
  }
  return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

long long power(long long b, long long e, long long m) {
  b = (b % m + m) % m;
  long long res = 1;
  while (e > 0) {
    if (e & 1) {
      res = res * b % m;
    }
    b = b * b % m;
    e >>= 1;
  }
  return res;
}

long long inverse(long long a, long long p) {
  return power(a, p - 2, p);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    inv[i] = -MOD / i * inv[MOD % i] % MOD;
  }
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < MAX; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    ifact[i] = ifact[i - 1] * inv[i] % MOD;
  }

  long long a, b, h;
  cin >> a >> b >> h;
  h++;
  long long cnt = 0;
  for (long long k = 1; k <= a + b; k++) {
    int x = k / 2;
    int y = k - x;
    for (int j = 0; j < 2; j++) {
      if ((x == 0 && a > 0) || (y == 0 && b > 0)) {
        swap(x, y);
        continue;
      }
      if (h * y <= b) {
        long long p = (x == 0 ? 1 : choose(a - 1, x - 1));
        long long q = (y == 0 ? 1 : choose(b - h * y + y - 1, y - 1));
        // cerr << x << ' ' << y << ' ' << p << ' ' << q << '\n';
        cnt += p * q % MOD;
        cnt %= MOD;
      }
      swap(x, y);
    }
  }
  long long tot = choose(a + b, a);
  // cerr << cnt << ' ' << tot << '\n';
  long long ans = cnt * inverse(tot, MOD) % MOD;
  if (ans < 0) {
    ans += MOD;
  }
  cout << ans << '\n';


  return 0;
}