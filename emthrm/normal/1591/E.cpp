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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
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
  int n, q; cin >> n >> q;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<vector<int>> graph(n);
  FOR(i, 1, n) {
    int p; cin >> p; --p;
    graph[p].emplace_back(i);
  }
  vector<int> l(q), k(q);
  vector<vector<int>> query(n);
  REP(i, q) {
    int v; cin >> v >> l[i] >> k[i]; --v;
    query[v].emplace_back(i);
  }
  vector<int> ans(q, -1), freq(n + 1, 0);
  vector<unordered_set<int>> nums(n + 1);
  FOR(i, 1, n + 1) nums[0].emplace(i);
  FenwickTree<int> bit(n + 1);
  bit.add(0, n);
  auto f = [&](auto&& f, int ver) -> void {
    nums[freq[a[ver]]].erase(a[ver]);
    bit.add(freq[a[ver]], -1);
    ++freq[a[ver]];
    nums[freq[a[ver]]].emplace(a[ver]);
    bit.add(freq[a[ver]], 1);
    for (int id : query[ver]) {
      k[id] += bit.sum(0, l[id]);
      if (k[id] <= n) ans[id] = *nums[bit.lower_bound(k[id])].begin();
    }
    for (int child : graph[ver]) f(f, child);
    nums[freq[a[ver]]].erase(a[ver]);
    bit.add(freq[a[ver]], -1);
    --freq[a[ver]];
    nums[freq[a[ver]]].emplace(a[ver]);
    bit.add(freq[a[ver]], 1);
  };
  f(f, 0);
  REP(i, q) cout << ans[i] << " \n"[i + 1 == q];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}