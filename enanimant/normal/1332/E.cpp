// March 29, 2020
// https://codeforces.com/contest/1332/problem/E

/*

*/


#include <bits/stdc++.h>

using namespace std;


const long long MOD = 998244353;

long long power(long long b, long long e, long long m) {
  b %= m;
  long long res = 1;
  while (e > 0) {
    if (e & 1) {
      res = res * b % m;
    }
    b = b * b % m;
    e >>= 1;
  }
  if (res < 0) {
    res += MOD;
  }
  return res;
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


  long long n, m, l, r;
  cin >> n >> m >> l >> r;
  if (n % 2 == 1 && m % 2 == 1) {
    long long ans = power(r - l + 1, m * n, MOD);
    cout << ans << '\n';
    return 0;
  }
  long long a = (r - l + 1) / 2;
  if (l % 2 == 0 && r % 2 == 0) {
    a++;
  }
  long long b = r - l + 1 - a;
  cerr << a << ' ' << b << '\n';
  long long ans = power(a + b, m * n, MOD) + power(a - b, m * n, MOD);
  cerr << ans << '\n';
  ans %= MOD;
  ans *= (MOD + 1) / 2;
  ans %= MOD;
  if (ans < 0) {
    ans += MOD;
  }
  cout << ans << '\n';


  return 0;
}