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
  int n, k; string s; cin >> n >> k >> s;
  if (count(ALL(s), 'W') == 0) {
    cout << (k == 0 ? 0 : 1 + (k - 1) * 2) << '\n';
    return;
  }
  vector<pair<int, int>> len;
  {
    int idx = 0;
    while (s[idx] == 'L') ++idx;
    while (idx < n) {
      while (idx < n && s[idx] == 'W') ++idx;
      if (idx < n) {
        int j = idx + 1;
        while (j < n && s[j] == 'L') ++j;
        if (j < n) len.emplace_back(j - idx, idx);
        idx = j;
      }
    }
  }
  sort(ALL(len), greater<pair<int, int>>());
  while (!len.empty() && k > 0) {
    auto [l, st] = len.back();
    len.pop_back();
    FOR(i, st, st + l) {
      if (k > 0) {
        s[i] = 'W';
        --k;
      }
    }
  }
  if (k > 0) {
    int r = n;
    while (s[r - 1] == 'L') --r;
    for (; r < n; ++r) {
      if (k > 0) {
        s[r] = 'W';
        --k;
      }
    }
    int l = -1;
    while (s[l + 1] == 'L') ++l;
    for (; l >= 0; --l) {
      if (k > 0) {
        s[l] = 'W';
        --k;
      }
    }
  }
  int ans = 0;
  REP(i, n) {
    if (s[i] == 'W') ans += i > 0 && s[i - 1] == 'W' ? 2 : 1;
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}