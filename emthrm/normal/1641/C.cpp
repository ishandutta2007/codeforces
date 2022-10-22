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

void merge(set<int>& a, set<int>& b) {
  if (a.size() < b.size()) swap(a, b);
  a.merge(b);
  b.clear();
}

int main() {
  int n, q; cin >> n >> q;
  vector<int> has_sick(n, -1);
  set<int> nas, wells;
  REP(i, n) nas.emplace(i);
  FenwickTree<int> sick(n);
  vector<set<int>> queries(n);
  while (q--) {
    int t; cin >> t;
    if (t == 0) {
      int l, r, x; cin >> l >> r >> x; --l; --r;
      if (x == 0) {
        set<int> qs;
        auto it = nas.lower_bound(l);
        for (; it != nas.end() && *it <= r; it = nas.erase(it)) {
          const int i = *it;
          has_sick[i] = false;
          wells.emplace(i);
          merge(qs, queries[i]);
        }
        if (it != nas.end()) {
          const int j = *it;
          if (sick.sum(r + 1, j) == 0) merge(queries[j], qs);
        }
      } else if (x == 1) {
        if (sick.sum(l, r + 1) > 0) continue;
        auto it = nas.lower_bound(l);
        if (it != nas.end() && *it <= r) queries[*it].emplace(r);
      }
    } else if (t == 1) {
      int j; cin >> j; --j;
      if (has_sick[j] == -1 && !queries[j].empty()) {
        const int r = *queries[j].begin();
        if (sick.sum(j, r + 1) == 0) {
          const auto it = nas.upper_bound(j);
          if (it == nas.end() || *it > r) {
            nas.erase(j);
            has_sick[j] = true;
            sick.add(j, 1);
            queries[j].clear();
          }
        } else {
          queries[j].clear();
        }
      }
      switch (has_sick[j]) {
        case false:
          cout << "NO\n";
          break;
        case true:
          cout << "YES\n";
          break;
        default:
          cout << "N/A\n";
          break;
      }
    }
  }
  return 0;
}