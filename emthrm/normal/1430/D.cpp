#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

template <typename T = char, typename U = std::string>
std::vector<std::pair<T, int>> rle(const U &s) {
  int n = s.size();
  std::vector<std::pair<T, int>> res;
  T now = s[0];
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] != now) {
      res.emplace_back(now, cnt);
      cnt = 0;
    }
    now = s[i];
    ++cnt;
  }
  res.emplace_back(now, cnt);
  return res;
}

void solve() {
  int n; string s; cin >> n >> s;
  int ans = 0;
  auto rs = rle<>(s);
  reverse(ALL(rs));
  int fr = 0, pos = rs.size();
  while (rs.size() > fr) {
    while (pos >= rs.size()) --pos;
    while (pos > fr && rs[pos].second == 1) --pos;
    ++ans;
    --rs[pos].second;
    if (rs[pos].second == 0) {
      assert(fr == pos);
      ++fr;
      ++pos;
    }
    if (rs.size() > fr) rs.pop_back();
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}