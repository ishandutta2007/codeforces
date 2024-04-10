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
  int n; cin >> n;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i], --a[i];
  REP(i, n) cin >> b[i], --b[i];
  reverse(ALL(a));
  vector<pair<int, int>> rle_b = run_length_encoding<int>(b);
  vector<int> c(n, 0);
  for (const auto [v, num_] : run_length_encoding<int>(a)) {
    int num = num_;
    const int use = min(c[v], num);
    c[v] -= use;
    num -= use;
    if (!rle_b.empty() && rle_b.back().first == v && rle_b.back().second >= num) {
      c[v] += rle_b.back().second - num;
      rle_b.pop_back();
    } else if (num > 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}