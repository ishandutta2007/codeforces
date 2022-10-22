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
struct FenwickTreeSupportingRangeAddQuery {
  FenwickTreeSupportingRangeAddQuery(int n_, const Abelian ID = 0) : n(n_), ID(ID) {
    ++n;
    dat_const.assign(n, ID);
    dat_linear.assign(n, ID);
  }

  void add(int left, int right, Abelian val) {
    if (right < ++left) return;
    for (int i = left; i < n; i += i & -i) {
      dat_const[i] -= val * (left - 1);
      dat_linear[i] += val;
    }
    for (int i = right + 1; i < n; i += i & -i) {
      dat_const[i] += val * right;
      dat_linear[i] -= val;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    for (int i = idx; i > 0; i -= i & -i) res += dat_linear[i];
    res *= idx;
    for (int i = idx; i > 0; i -= i & -i) res += dat_const[i];
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

private:
  int n;
  const Abelian ID;
  std::vector<Abelian> dat_const, dat_linear;
};

constexpr int C = 4;
const string ANTON = "ANOT";

void solve() {
  string a; cin >> a;
  int n = a.length();
  vector<int> ch[C]{};
  REP(c, C) REP(i, n) {
    if (a[i] == ANTON[c]) ch[c].emplace_back(i);
  }
  ll ans = 0;
  string b = a;
  int ord[C]{};
  iota(ord, ord + C, 0);
  do {
    FenwickTreeSupportingRangeAddQuery<int> bit(n);
    REP(i, n) bit.add(i + 1, n, 1);
    ll inv = 0;
    for (int c : ord) for (int i : ch[c]) {
      inv += bit[i];
      bit.add(i + 1, n, -1);
    }
    if (chmax(ans, inv)) {
      b = "";
      for (int c : ord) for (int _ : ch[c]) b += ANTON[c];
    }
  } while (next_permutation(ord, ord + C));
  cout << b << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}