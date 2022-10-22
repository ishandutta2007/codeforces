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

string solve1(vector<int> a) {
  int n = a.size();
  if (n == 1) return "";
  if (n == 2) return "*";
  vector<ll> mul(n);
  mul[0] = a[0];
  FOR(i, 1, n) mul[i] = min(mul[i - 1] * a[i], 1LL * INF);
  if (mul[n - 1] == INF) return string(n - 1, '*');
  vector<int> b;
  for (int i = 0; i < n;) {
    int j = i + 1;
    if (a[i] == 1) {
      while (j < n && a[j] == 1) ++j;
      b.emplace_back(j - i);
    } else {
      int mul = a[i];
      while (j < n && a[j] > 1) mul *= a[j++];
      b.emplace_back(mul);
    }
    i = j;
  }
  int m = b.size();
  assert(m % 2 == 1);
  vector<ll> dp(m, -LINF);
  vector<int> prev(m, -1);
  dp[0] = b[0];
  prev[0] = 0;
  for (int i = 2; i < m; i += 2) {
    dp[i] = dp[i - 2] + b[i - 1] + b[i];
    prev[i] = i;
    int mul = b[i];
    for (int j = i - 2; j >= 0; j -= 2) {
      mul *= b[j];
      if (dp[i] < (j == 0 ? 0 : dp[j - 2] + b[j - 1]) + mul) {
        dp[i] = (j == 0 ? 0 : dp[j - 2] + b[j - 1]) + mul;
        prev[i] = j;
      }
    }
  }
  int pos = m - 1;
  vector<bool> plus(m, true);
  while (pos >= 0) {
    FOR(i, prev[pos], pos) plus[i] = false;
    pos = prev[pos] - 2;
  }
  string ans = "";
  bool ast = true;
  for (int i = 0, idx = 0; i < n; ++idx) {
    int j = i;
    if (a[i] == 1) {
      while (j < n && a[j] == 1) {
        ans += ast ? '*' : '+';
        ++j;
      }
    } else {
      while (j < n && a[j] > 1) {
        ans += '*';
        ++j;
      }
      ans.pop_back();
      ast = !plus[idx];
      ans += ast ? '*' : '+';
    }
    i = j;
  }
  ans.pop_back();
  return ans;
}

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  string s; cin >> s;
  if (s.length() == 3) s = "*+";
  sort(ALL(s));
  if (s == "+-") s = "+";
  string ans = "";
  if (s.length() == 1) {
    ans = string(n - 1, s[0]);
  } else if (s == "*+") {
    for (int i = 0; i < n;) {
      if (a[i] == 0 || a[i] == 1) {
        ans += '+';
        ++i;
        continue;
      }
      int j = i + 1;
      while (j < n && a[j] >= 1) ++j;
      int k = j - 1;
      while (k >= i && a[k] == 1) --k;
      ans += solve1(vector<int>(a.begin() + i, a.begin() + k + 1));
      FOR(_, k, j) ans += '+';
      i = j;
    }
  } else if (s == "*-") {
    int i = 0;
    for (; i < n; ++i) {
      if (a[i] == 0) break;
      ans += '*';
    }
    if (i > 0) {
      ans.pop_back();
      ans += '-';
    }
    for (; i < n; ++i) ans += '*';
    ans.pop_back();
  }
  REP(i, n) cout << a[i] << (i + 1 == n ? '\n' : ans[i]);
  return 0;
}