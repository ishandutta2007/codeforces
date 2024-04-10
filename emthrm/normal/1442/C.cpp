#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

template <int MOD>
struct MInt {
  unsigned val;
  MInt(): val(0) {}
  MInt(long long x) : val(x >= 0 ? x % MOD : x % MOD + MOD) {}
  static int get_mod() { return MOD; }
  static void set_mod(int divisor) { assert(divisor == MOD); }
  MInt pow(long long exponent) const {
    MInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  MInt &operator+=(const MInt &x) { if((val += x.val) >= MOD) val -= MOD; return *this; }
  MInt &operator-=(const MInt &x) { if((val += MOD - x.val) >= MOD) val -= MOD; return *this; }
  MInt &operator*=(const MInt &x) { val = static_cast<unsigned long long>(val) * x.val % MOD; return *this; }
  MInt &operator/=(const MInt &x) {
    // assert(std::__gcd(static_cast<int>(x.val), MOD) == 1);
    unsigned a = x.val, b = MOD; int u = 1, v = 0;
    while (b) {
      unsigned tmp = a / b;
      std::swap(a -= tmp * b, b);
      std::swap(u -= tmp * v, v);
    }
    return *this *= u;
  }
  bool operator==(const MInt &x) const { return val == x.val; }
  bool operator!=(const MInt &x) const { return val != x.val; }
  bool operator<(const MInt &x) const { return val < x.val; }
  bool operator<=(const MInt &x) const { return val <= x.val; }
  bool operator>(const MInt &x) const { return val > x.val; }
  bool operator>=(const MInt &x) const { return val >= x.val; }
  MInt &operator++() { if (++val == MOD) val = 0; return *this; }
  MInt operator++(int) { MInt res = *this; ++*this; return res; }
  MInt &operator--() { val = (val == 0 ? MOD : val) - 1; return *this; }
  MInt operator--(int) { MInt res = *this; --*this; return res; }
  MInt operator+() const { return *this; }
  MInt operator-() const { return MInt(val ? MOD - val : 0); }
  MInt operator+(const MInt &x) const { return MInt(*this) += x; }
  MInt operator-(const MInt &x) const { return MInt(*this) -= x; }
  MInt operator*(const MInt &x) const { return MInt(*this) *= x; }
  MInt operator/(const MInt &x) const { return MInt(*this) /= x; }
  friend std::ostream &operator<<(std::ostream &os, const MInt &x) { return os << x.val; }
  friend std::istream &operator>>(std::istream &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }
};
namespace std { template <int MOD> MInt<MOD> abs(const MInt<MOD> &x) { return x; } }
template <int MOD>
struct Combinatorics {
  using ModInt = MInt<MOD>;
  int val;  // "val!" and "mod" must be disjoint.
  std::vector<ModInt> fact, fact_inv, inv;
  Combinatorics(int val = 10000000) : val(val), fact(val + 1), fact_inv(val + 1), inv(val + 1) {
    fact[0] = 1;
    for (int i = 1; i <= val; ++i) fact[i] = fact[i - 1] * i;
    fact_inv[val] = ModInt(1) / fact[val];
    for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
    for (int i = 1; i <= val; ++i) inv[i] = fact[i - 1] * fact_inv[i];
  }
  ModInt nCk(int n, int k) const {
    if (n < 0 || n < k || k < 0) return 0;
    assert(n <= val && k <= val);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) const {
    if (n < 0 || n < k || k < 0) return 0;
    assert(n <= val);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) const {
    if (n < 0 || k < 0) return 0;
    return k == 0 ? 1 : nCk(n + k - 1, k);
  }
};
using ModInt = MInt<MOD>;

int main() {
  constexpr int X = 20;
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n * 2);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u * 2].emplace_back(v * 2);
    graph[v * 2 + 1].emplace_back(u * 2 + 1);
  }
  vector dist1(n * 2, vector(X, INF));
  vector<map<int, int>> dist2(n * 2);
  dist1[0][0] = 0;
  using P = pair<pair<int, int>, pair<int, int>>;
  priority_queue<P, vector<P>, greater<P>> que;
  que.emplace(make_pair(0, 0), make_pair(0, 0));
  while (!que.empty()) {
    auto [cost, node] = que.top(); que.pop();
    auto [p2, nor] = cost;
    auto [i, j] = node;
    // cout << p2 << ' ' << nor << " : " << i / 2 << ' ' << j << endl;
    if (j < X) {
      assert(p2 == 0);
      if (nor > dist1[i][j]) continue;
    } else {
      assert(p2 == j - X + 1);
      if (dist2[i].begin()->first < j || nor > dist2[i][j]) continue;
    }
    if (j < X) {
      for (int e : graph[i]) {
        if (dist1[e][j] > nor + 1) {
          dist1[e][j] = nor + 1;
          que.emplace(make_pair(0, dist1[e][j]), make_pair(e, j));
        }
      }
    } else {
      for (int e : graph[i]) {
        if (dist2[e].empty() || dist2[e].begin()->first > j || dist2[e][j] > nor + 1) {
          dist2[e][j] = nor + 1;
          que.emplace(make_pair(p2, dist2[e][j]), make_pair(e, j));
        }
      }
    }
    int nx = i ^ 1;
    if (j + 1 < X) {
      if (dist1[nx][j + 1] > nor + (1 << j)) {
        dist1[nx][j + 1] = nor + (1 << j);
        que.emplace(make_pair(0, dist1[nx][j + 1]), make_pair(nx, j + 1));
      }
    } else {
      if (dist2[nx].empty() || dist2[nx].begin()->first > j + 1 || dist2[nx][j + 1] > nor) {
        dist2[nx][j + 1] = nor;
        que.emplace(make_pair(p2 + 1, dist2[nx][j + 1]), make_pair(nx, j + 1));
      }
    }
  }
  int u = (n - 1) * 2, v = u + 1;
  int min_ans = min(*min_element(ALL(dist1[u])), *min_element(ALL(dist1[v])));
  if (min_ans != INF) {
    cout << min_ans << '\n';
    return 0;
  }
  assert(!dist2[u].empty() && !dist2[v].empty());
  ModInt ans = 0;
  if (dist2[u].begin()->first < dist2[v].begin()->first) {
    ans = dist2[u].begin()->second;
    ModInt tmp = ModInt(2).pow(X - 1);
    FOR(b, X - 1, dist2[u].begin()->first) {
      ans += tmp;
      tmp *= 2;
    }
  } else if (dist2[u].begin()->first > dist2[v].begin()->first) {
    ans = dist2[v].begin()->second;
    ModInt tmp = ModInt(2).pow(X - 1);
    FOR(b, X - 1, dist2[v].begin()->first) {
      ans += tmp;
      tmp *= 2;
    }
  } else {
    ans = min(dist2[u].begin()->second, dist2[v].begin()->second);
    ModInt tmp = ModInt(2).pow(X - 1);
    FOR(b, X - 1, dist2[u].begin()->first) {
      ans += tmp;
      tmp *= 2;
    }
  }
  cout << ans << '\n';
  return 0;
}