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

std::vector<int> mobius_mu_init(const int n) {
  std::vector<int> is_prime(n + 1, true);
  is_prime[0] = false;
  if (n >= 1) {
    is_prime[1] = false;
  }
  std::vector<int> mu(n + 1, 1);
  mu[0] = 0;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      mu[i] = -mu[i];
      for (int j = i * 2; j <= n; j += i) {
        is_prime[j] = false;
        mu[j] = ((j / i) % i == 0 ? 0 : -mu[j]);
      }
    }
  }
  return mu;
}

int main() {
  int n; cin >> n;
  vector<ll> a(n + 1, 0); FOR(i, 1, n + 1) cin >> a[i];
  vector<int> b(n + 1, 0); FOR(i, 1, n + 1) cin >> b[i];
  vector<ll> diff(n + 1, 0);
  FOR(i, 2, n + 1) {
    diff[i] = b[i] - a[i];
    for (int j = i; j <= n; j += i) a[j] += diff[i];
  }
  // FOR(i, 1, n + 1) cerr << diff[i] << " \n"[i == n];
  vector<int> mu = mobius_mu_init(n);
  // FOR(i, 1, n + 1) cerr << mu[i] << " \n"[i == n];
  int q; cin >> q;
  vector<int> x(q); REP(i, q) cin >> x[i], x[i] -= a[1];
  vector<int> y = x;
  sort(ALL(y));
  y.erase(unique(ALL(y)), y.end());
  const int m = y.size(), p = lower_bound(ALL(y), 0) - y.begin();
  // REP(i, m) cerr << y[i] << " \n"[i + 1 == m];
  FenwickTreeSupportingRangeAddQuery<ll> ans1(m), ans2(m);
  FOR(i, 1, n + 1) {
    const ll ab = abs(diff[i]);
    ans1.add(0, m, ab);
    if (mu[i] != 0) {
      ans2.add(0, m, 1);
      if (mu[i] == 1) {
        if (diff[i] > 0) {
          const int l = upper_bound(ALL(y), -diff[i]) - y.begin();
          ans1.add(0, l, -ab * 2);
          ans2.add(l, p, -2);
        } else {
          const int r = lower_bound(ALL(y), -diff[i]) - y.begin();
          ans1.add(r, m, -ab * 2);
          ans2.add(p, r, -2);
        }
      } else if (mu[i] == -1) {
        if (diff[i] > 0) {
          const int r = lower_bound(ALL(y), diff[i]) - y.begin();
          ans1.add(r, m, -ab * 2);
          ans2.add(p, r, -2);
        } else {
          const int l = upper_bound(ALL(y), diff[i]) - y.begin();
          ans1.add(0, l, -ab * 2);
          ans2.add(l, p, -2);
        }
      }
    }
    // REP(j, m) cerr << ans1[j] << " \n"[j + 1 == m];
    // REP(j, m) cerr << ans2[j] << " \n"[j + 1 == m];
    // cerr << '\n';
  }
  vector<ll> ans(m, 0);
  REP(i, m) ans[i] = ans1[i] + abs(y[i]) * ans2[i];
  REP(i, q) cout << ans[lower_bound(ALL(y), x[i]) - y.begin()] << '\n';
  return 0;
}