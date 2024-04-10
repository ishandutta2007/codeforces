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

constexpr int C = 26;

void solve() {
  string s; cin >> s;
  sort(ALL(s));
  if (s.front() == s.back()) {
    cout << s << '\n';
    return;
  }
  int cnt[C]{};
  for (char c : s) ++cnt[c - 'a'];
  REP(i, C) {
    if (cnt[i] == 1) {
      s.erase(find(ALL(s), 'a' + i));
      cout << static_cast<char>('a' + i) << s << '\n';
      return;
    }
  }
  const int n = s.length();
  int b = 1;
  while (s[b] == s.front()) ++b;
  string ans = "";
  if (b - 1 > n - b + 1) {
    if (b + 1 < n && s.back() == s[b]) {
      ans += string(1, s.front()) + s.substr(b) + s.substr(1, b - 1);
    } else {
      ans += string(1, s.front()) + s[b] + s.substr(1, b - 1) + s.substr(b + 1);
      FOR(i, b + 1, n) {
        if (ans[i] != s[b]) {
          swap(ans[b + 1], ans[i]);
          break;
        }
      }
    }
  } else {
    ans += s.front();
    for (int l = 1, r = b; ans.length() < n; ++l, ++r) {
      if (l < b) ans += s[l];
      if (r < n) ans += s[r];
    }
  }
  // if (b == 1) {
  //   assert(ans == s);
  // } else {
  //   do {
  //     string pre = s.substr(0, 2);
  //     bool is_valid = true;
  //     FOR(i, 1, n - 1) {
  //       if (s.substr(i, 2) == pre) {
  //         is_valid = false;
  //         break;
  //       }
  //     }
  //     if (is_valid) {
  //       assert(ans == s);
  //       break;
  //     }
  //   } while (next_permutation(ALL(s)));
  // }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}