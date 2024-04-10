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

bool is_valid(const string& s) {
  int dep = 0;
  for (char c : s) {
    dep += (c == '(' ? 1 : -1);
    if (dep < 0) return false;
  }
  return dep == 0;
}

void solve() {
  string s; cin >> s;
  const int n = s.length();
  if (n % 2 == 1) {
    cout << "NO\n";
    return;
  }
  const int l = count(ALL(s), '('), r = count(ALL(s), ')');
  if (l > n / 2 || r > n / 2) {
    cout << "NO\n";
    return;
  }
  vector<int> p[2]{};
  REP(i, n) {
    if (s[i] == '?') p[l + p[0].size() == n / 2].emplace_back(i);
  }
  string t = s;
  for (int p_i : p[0]) t[p_i] = '(';
  for (int p_i : p[1]) t[p_i] = ')';
  if (!is_valid(t)) {
    cout << "NO\n";
    return;
  }
  if (p[0].empty() || p[1].empty()) {
    cout << "YES\n";
    return;
  }
  swap(t[p[0].back()], t[p[1].front()]);
  cout << (is_valid(t) ? "NO\n" : "YES\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}