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
#include <numeric>
#include <queue>
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
vector<pair<long long, int> > prime_factorization(long long val) {
  vector<pair<long long, int> > res;
  for (long long i = 2; i * i <= val; ++i) {
    if (val % i != 0) continue;
    int exponent = 0;
    while (val % i == 0) {
      ++exponent;
      val /= i;
    }
    res.emplace_back(i, exponent);
  }
  if (val != 1) res.emplace_back(val, 1);
  return res;
}

long long mod_pow(long long base, long long exponent, long long mod = MOD) {
  base %= mod;
  long long res = 1;
  while (exponent > 0) {
    if (exponent & 1) (res *= base) %= mod;
    (base *= base) %= mod;
    exponent >>= 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int x; long long n; cin >> x >> n;
  auto p = prime_factorization(x);
  long long ans = 1;
  for (auto pr : p) {
    long long prime = pr.first;
    while (prime <= 1e18) {
      long long cnt = n / prime;
      (ans *= mod_pow(pr.first, cnt)) %= MOD;
      if (cnt == 1) break;
      prime *= pr.first;
    }
  }
  cout << ans << '\n';
  return 0;
}