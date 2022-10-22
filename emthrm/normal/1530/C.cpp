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

template <typename Abelian>
struct FenwickTree {
  FenwickTree(int n, const Abelian ID = 0) : n(n), ID(ID), dat(n, ID) {}

  void add(int idx, Abelian val) {
    while (idx < n) {
      dat[idx] += val;
      idx |= idx + 1;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    --idx;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) const {
    if (val <= ID) return 0;
    int res = 0, exponent = 1;
    while (exponent <= n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      if (res + mask - 1 < n && dat[res + mask - 1] < val) {
        val -= dat[res + mask - 1];
        res += mask;
      }
    }
    return res;
  }

private:
  int n;
  const Abelian ID;
  std::vector<Abelian> dat;
};

constexpr int M = 100;

void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  sort(ALL(a));
  REP(i, n) cin >> b[i];
  sort(ALL(b));
  int you = accumulate(ALL(a), 0), ilya = accumulate(ALL(b), 0);
  {
    int yo = you, il = ilya;
    REP(i, n / 4) {
      yo -= a[i];
      il -= b[i];
    }
    if (yo >= il) {
      cout << 0 << '\n';
      return;
    }
  }
  int lb = 0, ub = n;
  while (ub - lb > 1) {
    int stage = (lb + ub) / 2;
    int yo = you + 100 * stage, il = ilya;
    for (int i = 0, ed = (n + stage) / 4; i < n && i < ed; ++i) yo -= a[i];
    yo -= 100 * max((n + stage) / 4 - n, 0);
    for (int i = 0, ed = (n + stage) / 4 - stage; i < n && i < ed; ++i) il -= b[i];
    (yo >= il ? ub : lb) = stage;
  }
  cout << ub << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}