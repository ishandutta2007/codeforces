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

int f(const vector<int> &a, const vector<int> &b) {
  int n = a.size(), m = b.size();
  if (n == 0 || m == 0) return 0;
  vector<bool> match(m, false);
  REP(i, m) {
    auto it = lower_bound(ALL(a), b[i]);
    match[i] = it != a.end() && *it == b[i];
  }
  int l = 0, r = 0, tmp = count(ALL(match), true), ans = tmp;
  REP(i, m) {
    while (l < n && a[l] <= b[i] + l) ++l;
    while (r < m && b[r] < b[i] + l) {
      if (match[r]) --tmp;
      ++r;
    }
    chmax(ans, tmp + min(l, r - i));
  }
  return ans;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  REP(i, n) cin >> a[i];
  REP(i, m) cin >> b[i];
  int a0 = lower_bound(ALL(a), 0) - a.begin(), b0 = lower_bound(ALL(b), 0) - b.begin();
  vector<int> a_neg(a.rend() - a0, a.rend()), b_neg(b.rend() - b0, b.rend());
  for (int &e : a_neg) e = -e;
  for (int &e : b_neg) e = -e;
  cout << f(a_neg, b_neg) + f(vector<int>(a.begin() + a0, a.end()), vector<int>(b.begin() + b0, b.end())) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}