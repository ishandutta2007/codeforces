#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

ll query(bool is_or, int i, int j) {
  cout << (is_or ? "or" : "and") << ' ' << i + 1 << ' ' << j + 1 << endl;
  ll x; cin >> x;
  assert(x != -1);
  return x;
}

tuple<int, int, int> fn(int a, int b, int c, int d, int e, int f) {
  REP(x, 2) REP(y, 2) REP(z, 2) {
    if ((x | y) == a
        && (x & y) == b
        && (y | z) == c
        && (y & z) == d
        && (z | x) == e
        && (z & x) == f) {
      return {x, y, z};
    }
  }
  assert(false);
}

int main() {
  constexpr int B = 30;
  int n, k; cin >> n >> k;
  vector<ll> ans(n, 0);
  int a = query(true, 0, 1), b = query(false, 0, 1);
  int c = query(true, 1, 2), d = query(false, 1, 2);
  int e = query(true, 2, 0), f = query(false, 2, 0);
  REP(bit, B) {
    auto [x, y, z] = fn(a >> bit & 1, b >> bit & 1, c >> bit & 1, d >> bit & 1, e >> bit & 1, f >> bit & 1);
    ans[0] |= x << bit;
    ans[1] |= y << bit;
    ans[2] |= z << bit;
  }
  FOR(i, 3, n) {
    int ai = query(true, 0, i), bi = query(false, 0, i);
    REP(bit, B) {
      if (ans[0] >> bit & 1) {
        ans[i] |= (bi >> bit & 1) << bit;
      } else {
        ans[i] |= (ai >> bit & 1) << bit;
      }
    }
  }
  sort(ALL(ans));
  cout << "finish " << ans[k - 1] << endl;
  return 0;
}