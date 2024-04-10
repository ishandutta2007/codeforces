#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
long long mod_inv(long long a, long long mod = MOD) {
  a %= mod;
  if (__gcd(a, mod) != 1) return -1;
  long long b = mod, x = 1, y = 0;
  while (b > 0) {
    long long tmp = a / b;
    a -= tmp * b;
    swap(a, b);
    x -= tmp * y;
    swap(x, y);
  }
  x %= mod;
  if (x < 0) x += mod;
  return x;
}

const int MAX = 10000000;
long long fact[MAX + 1], fact_inv[MAX + 1];
void nCk_init(int val = MAX, long long mod = MOD) {
  fact[0] = 1;
  FOR(i, 1, val + 1) fact[i] = fact[i - 1] * i % mod;
  fact_inv[val] = mod_inv(fact[val], mod);
  for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i % mod;
}

long long nCk(int n, int k, long long mod = MOD) {
  if (n < 0 || n < k || k < 0) return 0;
  return fact[n] * fact_inv[k] % mod * fact_inv[n - k] % mod;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; long long T; cin >> n >> T;
  nCk_init(n);
  vector<int> t(n); REP(i, n) cin >> t[i];
  long long ans = 0, len = 0, beki = 1, tmp = -1;
  int sigma = -1;
  REP(i, n) {
    len += t[i];
    (beki *= 2) %= MOD;
    if (len + i + 1 <= T) {
      // cout << 1 << '\n';
      (ans += 1) %= MOD;
      continue;
    }
    if (len > T) {
      // cout << 0 << '\n';
      continue;
    }
    int m = min(T - len, i + 1LL);
    if (tmp == -1) {
      tmp = 0;
      REP(j, m + 1) (tmp += nCk(i + 1, j)) %= MOD;
      sigma = m;
    } else {
      (tmp *= 2) %= MOD;
      ++sigma;
      (tmp += nCk(i, sigma)) %= MOD;
      for (; sigma > m; --sigma) {
        tmp -= nCk(i + 1, sigma);
        tmp %= MOD;
        if (tmp < 0) tmp += MOD;
      }
    }
    // cout << tmp << '/' << beki << '\n';
    (ans += tmp * mod_inv(beki) % MOD) %= MOD;
  }
  cout << ans << '\n';
  return 0;
}