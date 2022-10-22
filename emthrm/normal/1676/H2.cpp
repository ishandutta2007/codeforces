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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename Abelian>
struct FenwickTree {
  explicit FenwickTree(const int n, const Abelian ID = 0)
      : n(n), ID(ID), data(n, ID) {}

  void add(int idx, const Abelian val) {
    for (; idx < n; idx |= idx + 1) {
      data[idx] += val;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    for (--idx; idx >= 0; idx = (idx & (idx + 1)) - 1) {
      res += data[idx];
    }
    return res;
  }

  Abelian sum(const int left, const int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) const {
    if (val <= ID) return 0;
    int res = 0, exponent = 1;
    while (exponent <= n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      const int idx = res + mask - 1;
      if (idx < n && data[idx] < val) {
        val -= data[idx];
        res += mask;
      }
    }
    return res;
  }

 private:
  const int n;
  const Abelian ID;
  std::vector<Abelian> data;
};

void solve() {
  int n; cin >> n;
  FenwickTree<int> bit(n);
  ll ans = 0;
  REP(i, n) {
    int a; cin >> a; --a;
    ans += bit.sum(a, n);
    bit.add(a, 1);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}