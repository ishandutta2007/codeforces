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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename T = char, typename U = std::string>
std::vector<std::pair<T, int>> run_length_encoding(const U &s) {
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
  int n, k; ll x; cin >> n >> k >> x;
  string s; cin >> s;
  const auto rle = run_length_encoding(s);
  const int m = rle.size();
  string ans = "";
  vector<ll> w(m, 0);
  for (int i = m - 1; i >= 0; --i) {
    if (rle[i].first == '*') {
      const ll num = 1LL * k * rle[i].second + 1, r = (i + 2 < m ? w[i + 2] : 1);
      w[i] = (r > LINF / num ? LINF : r * num);
    }
  }
  REP(i, m) {
    if (rle[i].first == 'a') {
      ans += string(rle[i].second, 'a');
      continue;
    }
    const ll r = (i + 2 < m ? w[i + 2] : 1);
    const ll put = (x - 1) / r;
    x -= put * r;
    ans += string(put, 'b');
  }
  assert(x == 1);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}