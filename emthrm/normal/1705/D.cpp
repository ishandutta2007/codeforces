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

template <typename T>
long long inversion_number(const std::vector<T>& a) {
  const int n = a.size();
  std::vector<T> b = a;
  std::sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());
  FenwickTree<int> bit(b.size());
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    const int idx = std::distance(
        b.begin(), std::lower_bound(b.begin(), b.end(), a[i]));
    res += i - bit.sum(idx + 1);
    bit.add(idx, 1);
  }
  return res;
}

void solve() {
  int n; string s, t; cin >> n >> s >> t;
  if (s.front() != t.front() || s.back() != t.back()) {
    cout << "-1\n";
    return;
  }
  vector<int> sd, td;
  sd.reserve(n - 1);
  td.reserve(n - 1);
  FOR(i, 1, n) sd.emplace_back((s[i - 1] - '0') ^ (s[i] - '0'));
  FOR(i, 1, n) td.emplace_back((t[i - 1] - '0') ^ (t[i] - '0'));
  if (count(ALL(sd), 0) != count(ALL(td), 0)) {
    cout << "-1\n";
    return;
  }
  vector<int> p[2]{};
  for (int i = n - 2; i >= 0; --i) p[sd[i]].emplace_back(i);
  vector<int> a(n - 1);
  REP(i, n - 1) {
    a[p[td[i]].back()] = i;
    p[td[i]].pop_back();
  }
  cout << inversion_number(a) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}