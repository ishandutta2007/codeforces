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
  int a, b; string s; cin >> a >> b >> s;
  int n = s.length();
  for (int i = 0; i < n - 1 - i; ++i) {
    if (s[i] != '?' && s[n - 1 - i] != '?') {
      if (s[i] != s[n - 1 - i]) {
        cout << "-1\n";
        return;
      }
    } else if (s[i] != '?') {
      s[n - 1 - i] = s[i];
    } else {
      s[i] = s[n - 1 - i];
    }
  }
  int cnt[2]{};
  REP(i, 2) cnt[i] = count(ALL(s), '0' + i);
  if (cnt[0] > a || cnt[1] > b) {
    cout << "-1\n";
    return;
  }
  if ((a - cnt[0]) & 1) {
    if (n % 2 == 0 || s[n / 2] != '?' || ((b - cnt[1]) & 1)) {
      cout << "-1\n";
      return;
    }
    ++cnt[0];
    s[n / 2] = '0';
  } else if ((b - cnt[1]) & 1) {
    if (n % 2 == 0 || s[n / 2] != '?') {
      cout << "-1\n";
      return;
    }
    ++cnt[1];
    s[n / 2] = '1';
  }
  for (int i = 0; i < n - 1 - i; ++i) {
    if (s[i] == '?') {
      int j = (a > cnt[0] ? 0 : 1);
      s[i] = s[n - 1 - i] = '0' + j;
      cnt[j] += 2;
    }
  }
  cout << s << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}