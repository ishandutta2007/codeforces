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
  vector<int> skills[2]{};
  REP(i, n) {
    int b; cin >> b;
    skills[a[i]].emplace_back(b);
  }
  REP(p, 2) sort(ALL(skills[p]), greater<int>());
  if (skills[0].size() < skills[1].size()) swap(skills[0], skills[1]);
  bool is_erased = false;
  ll ans = 0;
  while (skills[0].size() > skills[1].size()) {
    ans += skills[0].back();
    skills[0].pop_back();
    is_erased = true;
  }
  if (!is_erased) {
    assert(!skills[0].empty() && !skills[1].empty());
    if (skills[0].back() > skills[1].back()) swap(skills[0], skills[1]);
    ans += skills[0].back();
    skills[0].pop_back();
  }
  REP(p, 2) {
    while (!skills[p].empty()) {
      ans += skills[p].back() * 2;
      skills[p].pop_back();
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}