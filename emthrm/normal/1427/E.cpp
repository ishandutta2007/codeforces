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
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
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

template <typename T>
std::pair<T, T> ext_gcd(T a, T b) {
  if (b == 0) return {1, 0};
  T fst, snd; std::tie(fst, snd) = ext_gcd(b, a % b);
  return {snd, fst - a / b * snd};
}

int main() {
  ll x; cin >> x;
  // for (ll x = 3; x <= 999999; x += 2) {
  vector<ll> a, b;
  vector<char> symbol;
  auto add = [&](ll ai, char si, ll bi) {
    a.emplace_back(ai);
    symbol.emplace_back(si);
    b.emplace_back(bi);
  };
  int d = 0;
  while ((x >> d) > 1) ++d;
  ll cur = x;
  REP(_, d) {
    add(cur, '+', cur);
    cur = cur + cur;
  }
  add(cur, '^', x);
  cur = cur ^ x;
  assert(gcd(cur, x) == 1);
  auto [p, q] = ext_gcd(cur, -x);
  if (p < 0) {
    p = -p;
    q = -q;
  }
  assert(p > 0 && q > 0 && (cur * p - x * q == 1 || x * q - cur * p == 1));
  auto solve = [&](ll val, ll mul) {
    if (mul == 1) return;
    int bit = 0;
    while ((mul >> bit) > 0) ++bit;
    vector<ll> bi(bit, val);
    FOR(i, 1, bit) {
      add(bi[i - 1], '+', bi[i - 1]);
      bi[i] = bi[i - 1] + bi[i - 1];
    }
    if (__builtin_popcountll(mul) == 1) return;
    int lb = 0;
    while (!((mul >> lb) & 1)) ++lb;
    ll tmp = bi[lb];
    FOR(i, lb + 1, bit) {
      if (mul >> i & 1) {
        add(tmp, '+', bi[i]);
        tmp += bi[i];
      }
    }
  };
  solve(cur, p);
  solve(x, q);
  cur *= p;
  x *= q;
  add(cur, '^', x);
  ll last = cur ^ x;
  if (last > 1) {
    assert(1LL << __builtin_popcountll(last) == last + 1);
    add(last, '+', last);  // 1110
    add(last, '^', last << 1);  // 1001
    ll tmp1 = last ^ (last << 1);
    add(last << 1, '+', tmp1);  // 10111
    add(last, '^', (last << 1) + tmp1);  // 10000
    ll tmp2 = last ^ ((last << 1) + tmp1);
    assert(__builtin_popcountll(tmp2) == 1);
    add(tmp1, '+', tmp1);  // 10010
    add(tmp1 << 1, '^', tmp2);  // 2
    assert(((tmp1 << 1) ^ tmp2) == 2);
    ll tmp3 = 2;
    for (int bit = 1; ; ++bit) {
      if (!(last >> bit & 1)) break;
      if (bit > 1) {
        add(tmp3, '+', tmp3);
        tmp3 <<= 1;
      }
      add(last, '^', tmp3);
      last ^= tmp3;
    }
    assert(last == 1);
  }
  int Q = a.size();
  assert(Q <= 100000);
  cout << Q << '\n';
  constexpr ll MAX = 5000000000000000000;
  REP(i, Q) {
    assert(a[i] <= MAX && b[i] <= MAX);
    cout << a[i] << ' ' << symbol[i] << ' ' << b[i] << '\n';
  }
  // }
  return 0;
}