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
  int n; string s, t; cin >> n >> s >> t;
  string u = "", v = "";
  REP(i, n) {
    if (s[i] != 'b') u += s[i];
  }
  REP(i, n) {
    if (t[i] != 'b') v += t[i];
  }
  if (u != v) {
    cout << "NO\n";
    return;
  }
  vector<int> bs, bt, other;
  REP(i, n) (s[i] == 'b' ? bs : other).emplace_back(i);
  REP(i, n) {
    if (t[i] == 'b') bt.emplace_back(i);
  }
  vector<int> a(n, 0), c(n, 0);
  REP(i, n) a[i] = (i == 0 ? 0 : a[i - 1]) + (s[i] == 'a');
  REP(i, n) c[i] = (i == 0 ? 0 : c[i - 1]) + (s[i] == 'c');
  REP(i, bs.size()) {
    const int x = bs[i], y = bt[i];
    if (x < y) {
      auto it = lower_bound(ALL(other), x);
      if (other.end() - it < y - x || a[*next(it, y - x - 1)] - a[x] > 0) {
        cout << "NO\n";
        return;
      }
    } else if (x > y) {
      auto it = upper_bound(ALL(other), x);
      if (it - other.begin() < x - y || c[x] - (*prev(it, x - y) == 0 ? 0 : c[*prev(it, x - y) - 1]) > 0) {
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
}