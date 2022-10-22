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
struct FenwickTreeSupportingRangeAddQuery {
  explicit FenwickTreeSupportingRangeAddQuery(
      const int n_, const Abelian ID = 0)
      : n(n_ + 1), ID(ID) {
    data_const.assign(n, ID);
    data_linear.assign(n, ID);
  }

  void add(int left, const int right, const Abelian val) {
    if (right < ++left) return;
    for (int i = left; i < n; i += i & -i) {
      data_const[i] -= val * (left - 1);
      data_linear[i] += val;
    }
    for (int i = right + 1; i < n; i += i & -i) {
      data_const[i] += val * right;
      data_linear[i] -= val;
    }
  }

  Abelian sum(const int idx) const {
    Abelian res = ID;
    for (int i = idx; i > 0; i -= i & -i) {
      res += data_linear[i];
    }
    res *= idx;
    for (int i = idx; i > 0; i -= i & -i) {
      res += data_const[i];
    }
    return res;
  }

  Abelian sum(const int left, const int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

 private:
  const int n;
  const Abelian ID;
  std::vector<Abelian> data_const, data_linear;
};

void solve() {
  int n; cin >> n;
  FenwickTreeSupportingRangeAddQuery<ll> c(n);
  ll one = 0;
  REP(i, n) {
    int c_i; cin >> c_i;
    c.add(i, i + 1, c_i);
    one += c_i;
  }
  one /= n;
  vector<int> a(n, 0);
  for (int i = n - 1; i >= 0 && one > 0; --i) {
    c.add(i - one + 1, i + 1, -1);
    if (c[i] == i) {
      a[i] = 1;
      --one;
    }
  }
  REP(i, n) cout << a[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}