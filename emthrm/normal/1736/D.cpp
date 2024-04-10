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
  int n; string s; cin >> n >> s;
  reverse(ALL(s));
  vector<int> p[2]{};
  for (int i = n * 2 - 1; i >= 0; --i) {
    p[s[i] - '0'].emplace_back(i);
  }
  if (p[0].size() % 2 == 1) {
    cout << "-1\n";
    return;
  }
  const char last = s.front();
  vector<int> b{0};
  b.reserve(n * 2);
  for (int i = 0; i < n * 2;) {
    REP(par, 2) {
      while (!p[par].empty() && p[par].back() <= i) p[par].pop_back();
    }
    if (i % 2 == 1) {
      if (p[s[i - 1] - '0'].empty()) {
        assert(last == s[i - 1]);
        s[i] = last;
        break;
      }
      s[i] = s[i - 1];
      i = p[s[i - 1] - '0'].back();
      b.emplace_back(i);
    } else {
      s[i] = s[i + 1];
      b.emplace_back(i + 1);
      ++i;
    }
  }
  // cerr << s << '\n';
  reverse(ALL(b));
  const int m = b.size();
  cout << m;
  REP(i, m) cout << ' ' << n * 2 - 1 - b[i] + 1;
  cout << '\n';
  REP(i, n) cout << i * 2 + 1 << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}