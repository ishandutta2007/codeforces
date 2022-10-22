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
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename T>
std::vector<T> longest_increasing_subsequence(const std::vector<T> &a, bool is_strict = true) {
  const T inf = std::numeric_limits<T>::max();
  const int n = a.size();
  std::vector<int> idx(n);
  std::vector<T> tmp(n, inf);
  for (int i = 0; i < n; ++i) {
    if (is_strict) {
      idx[i] = std::distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), a[i]));
    } else {
      idx[i] = std::distance(tmp.begin(), std::upper_bound(tmp.begin(), tmp.end(), a[i]));
    }
    tmp[idx[i]] = a[i];
  }
  int res_size = std::distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), inf));
  std::vector<T> res(res_size--);
  for (int i = n - 1; res_size >= 0 && i >= 0; --i) {
    if (idx[i] == res_size) {
      res[res_size--] = a[i];
    }
  }
  return res;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<string> s(n); REP(i, n) cin >> s[i];
  vector<int> a[2]{};
  REP(j, m) for (int i = 0; i < n && j - i >= 0; ++i) {
    if (s[i][j - i] == '1') a[(i + j - i) & 1].emplace_back(j - i - i);
  }
  FOR(i, 1, n) for (int dj = 0; i + dj < n && m - 1 - dj >= 0; ++dj) {
    if (s[i + dj][m - 1 - dj] == '1') a[(i + dj + m - 1 - dj) & 1].emplace_back(m - 1 - dj - (i + dj));
  }
  cout << longest_increasing_subsequence(a[0]).size() + longest_increasing_subsequence(a[1]).size() << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}