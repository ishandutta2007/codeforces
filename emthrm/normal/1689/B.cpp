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

void solve() {
  int n; cin >> n;
  vector<int> p(n); REP(i, n) cin >> p[i];
  if (n == 1) {
    cout << "-1\n";
    return;
  }
  set<int> s;
  REP(i, n) s.emplace(p[i]);
  REP(i, n - 2) {
    if (*s.begin() == p[i]) {
      cout << *next(s.begin()) << ' ';
      s.erase(next(s.begin()));
    } else {
      cout << *s.begin() << ' ';
      s.erase(s.begin());
    }
  }
  if (set<int>{p[n - 2], p[n - 1]} == s) {
    cout << p[n - 1] << ' ' << p[n - 2] << '\n';
  } else if (*s.begin() == p[n - 2] || *next(s.begin()) == p[n - 1]) {
    cout << *next(s.begin()) << ' ' << *s.begin() << '\n';
  } else {
    cout << *s.begin() << ' ' << *next(s.begin()) << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}