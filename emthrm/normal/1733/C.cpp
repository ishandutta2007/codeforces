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

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> l, r;
  l.reserve(n);
  r.reserve(n);
  const auto op = [&](const int l_i, const int r_i) -> void {
    if ((a[l_i] + a[r_i]) % 2 == 0) {
      a[l_i] = a[r_i];
    } else {
      a[r_i] = a[l_i];
    }
    l.emplace_back(l_i);
    r.emplace_back(r_i);
  };
  if (a.front() % 2 != a.back() % 2) op(0, n - 1);
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] % 2 == a.back() % 2) op(i, n - 1);
  }
  assert(a.front() == a.back());
  FOR(i, 1, n - 1) {
    if (a[i] != a.front()) op(0, i);
  }
  const int m = l.size();
  cout << m << '\n';
  REP(i, m) cout << l[i] + 1 << ' ' << r[i] + 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}