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

template <typename T = char, typename U>
std::vector<std::pair<T, int>> run_length_encoding(const U& s) {
  const int n = s.size();
  std::vector<std::pair<T, int>> res;
  if (n == 0) return res;
  T ch = s.front();
  int num = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] != ch) {
      res.emplace_back(ch, num);
      num = 0;
    }
    ch = s[i];
    ++num;
  }
  res.emplace_back(ch, num);
  return res;
}

void solve() {
  int n; string s; cin >> n >> s;
  const auto rle = run_length_encoding(s);
  if (rle.size() == 1) {
    cout << n << '\n';
    return;
  }
  int y = 0, x = 0;
  ll ans = rle.front().second + 1;
  (rle.front().first == 'R' ? x : y) += rle.front().second;
  vector<pair<int, int>> unknown[2]{};
  FOR(i, 1, rle.size()) {
    const auto [ch, len] = rle[i];
    ans += len;
    if (ch == 'R') {
      unknown[0].emplace_back(len, n - 1 - y);
      x += len;
    } else if (ch == 'D') {
      unknown[1].emplace_back(len, n - 1 - x);
      y += len;
    }
  }
  ans += 1LL * (n - y) * (n - x) - 1;
  for (const auto [len, allow] : unknown[0]) {
    ans += 1LL * len * min(allow, n - 1 - y);
  }
  for (const auto [len, allow] : unknown[1]) {
    ans += 1LL * len * min(allow, n - 1 - x);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}