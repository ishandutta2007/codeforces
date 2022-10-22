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

int main() {
  int n; ll x; cin >> n >> x;
  ll m = 1;
  REP(_, n - 1) m *= 10;
  --m;
  set<ll> st{x};
  vector<ll> que{x};
  for (int ans = 1; !que.empty(); ++ans) {
    vector<ll> nxt;
    for (ll a : que) {
      string s = to_string(a);
      sort(ALL(s), greater<char>());
      s.erase(unique(ALL(s)), s.end());
      while (!s.empty() && s.back() < '2') s.pop_back();
      for (char c : s) {
        const int y = c - '0';
        if (a > m / y) {
          cout << ans << '\n';
          return 0;
        }
        if (st.emplace(a * y).second) nxt.emplace_back(a * y);
      }
    }
    que.swap(nxt);
  }
  cout << "-1\n";
  return 0;
}