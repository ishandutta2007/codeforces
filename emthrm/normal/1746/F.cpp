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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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

struct Xor128 {
  int rand() {
    unsigned int t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }
  int rand(const int ub) {
    const int res = rand() % ub;
    return res < 0 ? res + ub : res;
  }
  int rand(const int lb, const int ub) { return lb + rand(ub - lb); }
  long long randll() {
    return (static_cast<unsigned long long>(rand()) << 32) | rand();
  }
  long long randll(const long long ub) {
    const long long res = randll() % ub;
    return res < 0 ? res + ub : res;
  }
  long long randll(const long long lb, const long long ub) {
    return lb + randll(ub - lb);
  }
 private:
  unsigned int x = 123456789, y = 362436069, z = 521288629;
  unsigned int w = std::time(nullptr);
} xor128;

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

int main() {
  int n, q; cin >> n >> q;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> l(q), r(q, -1), k(q);
  REP(i, q) {
    int type; cin >> type >> l[i]; --l[i];
    if (type == 1) {
      cin >> k[i];
    } else if (type == 2) {
      cin >> r[i] >> k[i]; --r[i];
    }
  }
  vector<int> x = a;
  x.reserve(n + q);
  REP(i, q) {
    if (r[i] == -1) x.emplace_back(k[i]);
  }
  sort(ALL(x));
  x.erase(unique(ALL(x)), x.end());
  const int m = x.size();
  REP(i, n) a[i] = lower_bound(ALL(x), a[i]) - x.begin();
  REP(i, q) {
    if (r[i] == -1) k[i] = lower_bound(ALL(x), k[i]) - x.begin();
  }
  vector<int> ans(q, true);
  REP(_, 30) {
    vector<int> rn(m);
    REP(i, m) rn[i] = xor128.rand(2);
    FenwickTree<int> bit(n);
    REP(i, n) {
      if (rn[a[i]]) bit.add(i, 1);
    }
    REP(i, q) {
      if (r[i] != -1) {
        if (bit.sum(l[i], r[i] + 1) % k[i] > 0) ans[i] = false;
      } else {
        const int prv = bit[l[i]];
        if (prv < rn[k[i]]) {
          bit.add(l[i], 1);
        } else if (rn[k[i]] < prv) {
          bit.add(l[i], -1);
        }
      }
    }
  }
  REP(i, q) {
    if (r[i] != -1) cout << (ans[i] ? "YES\n" : "NO\n");
  }
  return 0;
}