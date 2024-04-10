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

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n * m); REP(i, n * m) cin >> a[i];
  map<int, vector<int>> mp;
  for (int i = n * m - 1; i >= 0; --i) {
    mp[a[i]].emplace_back(i);
  }
  vector<int> row(n * m), col(n * m);
  int y = 0, x = 0;
  for (auto [_, peo] : mp) {
    while (x + peo.size() >= m) {
      vector<int> tmp;
      while (x + tmp.size() < m) {
        tmp.emplace_back(peo.back());
        peo.pop_back();
      }
      reverse(ALL(tmp));
      for (int id : tmp) {
        row[id] = y;
        col[id] = x++;
      }
      ++y;
      x = 0;
    }
    for (int id : peo) {
      row[id] = y;
      col[id] = x++;
    }
  }
  int ans = 0;
  vector bit(n, FenwickTree<int>(m));
  REP(i, n * m) {
    ans += bit[row[i]].sum(col[i]);
    bit[row[i]].add(col[i], 1);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}