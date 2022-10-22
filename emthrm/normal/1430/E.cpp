#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

template <typename Abelian>
struct BITRangeAdd {
  BITRangeAdd(int n_, const Abelian UNITY = 0) : n(n_), UNITY(UNITY) {
    ++n;
    dat_const.assign(n, UNITY);
    dat_linear.assign(n, UNITY);
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
    Abelian res = UNITY;
    for (int i = idx; i > 0; i -= i & -i) res += dat_linear[i];
    res *= idx;
    for (int i = idx; i > 0; i -= i & -i) res += dat_const[i];
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : UNITY;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

private:
  int n;
  const Abelian UNITY;
  std::vector<Abelian> dat_const, dat_linear;
};

int main() {
  int n; string s; cin >> n >> s;
  vector<vector<int>> pos(26);
  for (int i = n - 1; i >= 0; --i) pos[s[i] - 'a'].emplace_back(i);
  BITRangeAdd<ll> bit(n);
  FOR(i, 1, n) bit.add(i, n, 1);
  ll ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    int p = pos[s[i] - 'a'].back();
    pos[s[i] - 'a'].pop_back();
    ans += bit[p];
    bit.add(p, n, -1);
  }
  cout << ans << '\n';
  return 0;
}