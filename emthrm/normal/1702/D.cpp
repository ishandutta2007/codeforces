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

constexpr int C = 26;

void solve() {
  string s; int p; cin >> s >> p;
  const int n = s.length();
  vector<int> is_alive(n, true), pos[C]{};
  REP(i, n) pos[s[i] - 'a'].emplace_back(i);
  REP(c, C) p -= (c + 1) * pos[c].size();
  for (int c = C - 1; c >= 0 && p < 0; --c)  {
    while (p < 0 && !pos[c].empty()) {
      is_alive[pos[c].back()] = false;
      pos[c].pop_back();
      p += c + 1;
    }
  }
  REP(i, n) {
    if (is_alive[i]) cout << s[i];
  }
  cout << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}