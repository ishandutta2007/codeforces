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

struct MorrisPratt {
  std::string s;
  std::vector<int> border;

  explicit MorrisPratt(const std::string& s) : s(s), border({-1}), j(-1) {
    const int n = s.length();
    for (int i = 0; i < n; ++i) {
      solve(i);
    }
  }

  void add(const char c) {
    s += c;
    solve(s.length() - 1);
  }

  std::vector<int> match(const std::string& t) const {
    const int n = s.length(), m = t.length();
    std::vector<int> res;
    for (int i = 0, k = 0; i < m; ++i) {
      while (k >= 0 && t[i] != s[k]) k = border[k];
      if (++k == n) res.emplace_back(i - n + 1);
    }
    return res;
  }

  int period(const int idx) const { return idx - border[idx]; }

 private:
  int j;

  void solve(const int idx) {
    while (j >= 0 && s[idx] != s[j]) j = border[j];
    border.emplace_back(++j);
  }
};

void solve() {
  string s; cin >> s;
  string t = s;
  sort(ALL(t));
  t.erase(unique(ALL(t)), t.end());
  cout << (t.length() == s.length() || MorrisPratt(s).period(s.length()) == t.length() ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}