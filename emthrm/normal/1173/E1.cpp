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
const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
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
  ModInt &operator*=(const ModInt &rhs) { val = (unsigned long long)val * rhs.val % mod; return *this; }
  ModInt &operator/=(const ModInt &rhs) { return *this *= rhs.inv(); }
  bool operator==(const ModInt &rhs) const { return val == rhs.val; }
  bool operator!=(const ModInt &rhs) const { return val != rhs.val; }
  bool operator<(const ModInt &rhs) const { return val < rhs.val; }
  bool operator<=(const ModInt &rhs) const { return val <= rhs.val; }
  bool operator>(const ModInt &rhs) const { return val > rhs.val; }
  bool operator>=(const ModInt &rhs) const { return val >= rhs.val; }
  ModInt operator-() const { return ModInt(-val); }
  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs; }
  friend ostream &operator<<(ostream &os, const ModInt &rhs) { return os << rhs.val; }
  friend istream &operator>>(istream &is, ModInt &rhs) { long long x; is >> x; rhs = ModInt(x); return is; }
private:
  ModInt inv() const {
    // if (__gcd((int)val, mod) != 1) assert(false);
    unsigned a = val, b = mod; int x = 1, y = 0;
    while (b) {
      unsigned tmp = a / b;
      a -= tmp * b; swap(a, b);
      x -= tmp * y; swap(x, y);
    }
    return ModInt(x);
  }
};
ModInt abs(const ModInt &x) { return x.val; }
struct Combinatorics {
  Combinatorics(int MAX = 5000000) {
    MAX <<= 1;
    fact.resize(MAX + 1);
    fact_inv.resize(MAX + 1);
    fact[0] = 1;
    FOR(i, 1, MAX + 1) fact[i] = fact[i - 1] * i;
    fact_inv[MAX] = ModInt(1) / fact[MAX];
    for (int i = MAX; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
  }
  ModInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) {
    if (n < 0 || k < 0) return ModInt(0);
    return (k == 0 ? ModInt(1) : nCk(n + k - 1, k));
  }
private:
  vector<ModInt> fact, fact_inv;
};
// using ModInt = double;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> w(n); REP(i, n) cin >> w[i];
  int dislike = 0, like = 0;
  REP(i, n) {
    if (a[i] == 0) dislike += w[i];
    else like += w[i];
  }
  REP(i, n) {
    vector<vector<vector<ModInt> > > dp(m + 1, vector<vector<ModInt> >(m + 1, vector<ModInt>(m + 1, 0)));
    dp[0][0][0] = 1;
    int dl = dislike, l = like;
    if (a[i] == 0) dl -= w[i];
    else l -= w[i];
    REP(x, m) {
      REP(y, m + 1) REP(z, m + 1) {
        int sum = like + dislike - z + (x - y - z) + (a[i] == 0 ? -y : y);
        if (a[i] == 0 && y > w[i]) continue;
        if (z > dl || y + z > x || sum <= 0) continue;
        // cout << x << ' ' << y << ' ' << z << '|' << dp[x][y][z] << ' ' << sum << '\n';
        dp[x + 1][y + 1][z] += dp[x][y][z] * (w[i] + (a[i] == 0 ? -y : y)) / sum;
        dp[x + 1][y][z + 1] += dp[x][y][z] * (dl - z) / sum;
        dp[x + 1][y][z] += dp[x][y][z] * (l + (x - y - z)) / sum;
      }
    }
    ModInt ans = 0;
    REP(y, m + 1) REP(z, m + 1) {
      if (a[i] == 0 && y > w[i]) continue;
      if (z > dl || y + z > m) continue;
      ans += dp[m][y][z] * (w[i] + (a[i] == 0 ? -y : y));
    }
    cout << ans << '\n';
  }
  return 0;
}