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
  int n; string s1, s2; cin >> n >> s1 >> s2;
  map<pair<char, char>, int> m;
  REP(i, n) ++m[minmax(s1[i], s2[n - 1 - i])];
  bool can_be_odd = (n % 2 == 1);
  for (const auto& [c1c2, num] : m) {
    if (num % 2 == 1) {
      if (can_be_odd && c1c2.first == c1c2.second) {
        can_be_odd = false;
      } else {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;

  const int n = 5;
  set<pair<string, string>> st{{"abcde", "ABCDE"}};
  queue<pair<string, string>> que({make_pair("abcde", "ABCDE")});
  while (!que.empty()) {
    const auto [s, t] = que.front(); que.pop();
    for (int k = 1; k <= n; ++k) {
      string ns = s, nt = t;
      REP(i, k) ns[i] = t[n - k + i];
      REP(i, k) nt[n - k + i] = s[i];
      if (st.emplace(ns, nt).second) que.emplace(ns, nt);
    }
  }
  //
  for (const auto& [s, t] : st) {
    cout << s << ' ' << t << '\n';
  }
  //
  set<vector<pair<char, char>>> constraints;
  for (const auto& [s, t] : st) {
    vector<pair<char, char>> tmp;
    REP(i, n) tmp.emplace_back(minmax(s[i], t[i]));
    sort(ALL(tmp));
    constraints.emplace(tmp);
  }
  //
  for (const auto& v : constraints) {
    for (const auto [c1, c2] : v) cout << '{' << c1 << c2 << '}';
    cout << '\n';
  }
  // string base = "ABCDEabcde";
  // do {
  //   const string s = base.substr(0, n), t = base.substr(n);
  //   if (!st.count({s, t})) cout << s << ' ' << t << '\n';
  // } while (next_permutation(ALL(base)));
}