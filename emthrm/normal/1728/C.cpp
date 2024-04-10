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
  int ans = 0;
  const auto f = [&ans](const int n) -> int {
    ++ans;
    return to_string(n).length();
  };

  int n; cin >> n;
  multiset<int> a, b;
  REP(i, n) {
    int a_i; cin >> a_i;
    a.emplace(a_i);
  }
  while (n--) {
    int b_i; cin >> b_i;
    const auto it = a.find(b_i);
    if (it == a.end()) {
      b.emplace(b_i < 10 ? b_i : f(b_i));
    } else {
      a.erase(it);
    }
  }
  while (!a.empty() && *a.rbegin() >= 10) {
    const int nxt = f(*a.rbegin());
    a.erase(prev(a.end()));
    a.emplace(nxt);
  }
  for (auto it = b.begin(); it != b.end();) {
    const auto a_it = a.find(*it);
    if (a_it == a.end()) {
      it = next(it);
    } else {
      a.erase(a_it);
      it = b.erase(it);
    }
  }
  a.erase(1);
  b.erase(1);
  cout << ans + a.size() + b.size() << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}