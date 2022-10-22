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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; string s; cin >> n >> s;
  int zero = count(ALL(s), '0');
  if (s.back() == '0' || zero % 2 == 1) {
    cout << "NO\n";
    return;
  }
  int l = (n - zero) / 2;
  string a = "", b = "";
  bool is_a = true;
  int nest = 0;
  for (char c : s) {
    if (c == '0') {
      if (is_a) {
        a += '(';
        b += ')';
      } else {
        a += ')';
        b += '(';
      }
      is_a = !is_a;
    } else if (c == '1') {
      if (l > 0) {
        a += '(';
        b += '(';
        --l;
      } else {
        a += ')';
        b += ')';
      }
    }
    nest += (b.back() == '(' ? 1 : -1);
    if (nest < 0) {
      cout << "NO\n";
      return;
    }
  }
  assert(nest == 0);
  cout << "YES\n" << a << '\n' << b << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}