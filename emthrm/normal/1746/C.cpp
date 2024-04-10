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
  map<int, vector<int>> m;
  FOR(i, 1, n) {
    if (a[i - 1] > a[i]) m[a[i - 1] - a[i]].emplace_back(i);
  }
  vector<int> x(n + 1, n - 1);
  for (int i = n; i >= 1 && !m.empty(); --i) {
    x[i] = m.rbegin()->second.back();
    m.rbegin()->second.pop_back();
    const int diff = m.rbegin()->first;
    if (m.rbegin()->second.empty()) m.erase(prev(m.end()));
    if (diff > i) m[diff - i].emplace_back(x[i]);
  }
  for (int i = 1; i <= n; ++i) {
    cout << x[i] + 1 << " \n"[i == n];
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}