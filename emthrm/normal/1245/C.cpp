#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
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

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
int mod = MOD;
struct ModInt {
  unsigned val;
  ModInt(): val(0) {}
  ModInt(long long x) : val(x >= 0 ? x % mod : x % mod + mod) {}
  ModInt pow(long long exponent) {
    ModInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  ModInt &operator+=(const ModInt &rhs) { if((val += rhs.val) >= mod) val -= mod; return *this; }
  ModInt &operator-=(const ModInt &rhs) { if((val += mod - rhs.val) >= mod) val -= mod; return *this; }
  ModInt &operator*=(const ModInt &rhs) { val = static_cast<unsigned long long>(val) * rhs.val % mod; return *this; }
  ModInt &operator/=(const ModInt &rhs) { return *this *= rhs.inv(); }
  bool operator==(const ModInt &rhs) const { return val == rhs.val; }
  bool operator!=(const ModInt &rhs) const { return val != rhs.val; }
  bool operator<(const ModInt &rhs) const { return val < rhs.val; }
  bool operator<=(const ModInt &rhs) const { return val <= rhs.val; }
  bool operator>(const ModInt &rhs) const { return val > rhs.val; }
  bool operator>=(const ModInt &rhs) const { return val >= rhs.val; }
  ModInt operator-() const { return ModInt(val ? mod - val : 0); }
  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs; }
  friend ostream &operator<<(ostream &os, const ModInt &rhs) { return os << rhs.val; }
  friend istream &operator>>(istream &is, ModInt &rhs) { long long x; is >> x; rhs = ModInt(x); return is; }
private:
  ModInt inv() const {
    // if (__gcd(val, mod) != 1) assert(false);
    unsigned a = val, b = mod; int x = 1, y = 0;
    while (b) {
      unsigned tmp = a / b;
      swap(a -= tmp * b, b);
      swap(x -= tmp * y, y);
    }
    return ModInt(x);
  }
};
int abs(const ModInt &x) { return x.val; }
struct Combinatorics {
  int val;
  vector<ModInt> fact, fact_inv, inv;
  Combinatorics(int val = 10000000) : val(val), fact(val + 1), fact_inv(val + 1), inv(val + 1) {
    fact[0] = 1;
    FOR(i, 1, val + 1) fact[i] = fact[i - 1] * i;
    fact_inv[val] = ModInt(1) / fact[val];
    for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
    FOR(i, 1, val + 1) inv[i] = fact[i - 1] * fact_inv[i];
  }
  ModInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    // assert(n <= val && k <= val);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    // assert(n <= val);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) {
    if (n < 0 || k < 0) return ModInt(0);
    return (k == 0 ? ModInt(1) : nCk(n + k - 1, k));
  }
};

int main() {
  string s; cin >> s;
  for (char c : s) {
    if (c == 'w' || c == 'm') {
      cout << 0 << '\n';
      return 0;
    }
  }
  int n = s.length();
  vector<ModInt> dp(n + 1);
  dp[0] = dp[1] = 1;
  FOR(i, 2, n + 1) dp[i] = dp[i - 1] + dp[i - 2];
  ModInt ans = 1;
  for (int i = 0; i < n;) {
    if (s[i] != 'u' && s[i] != 'n') {
      ++i;
      continue;
    }
    char now = s[i];
    int cnt = 1;
    int j = i + 1;
    while (j < n && s[j] == now) {
      ++j;
      ++cnt;
    }
    ans *= dp[cnt];
    i = j;
  }
  cout << ans << '\n';
  return 0;
}