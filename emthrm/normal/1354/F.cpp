#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n), b(n); REP(i, n) cin >> a[i] >> b[i];
  if (k == 1) {
    cout << "1\n" << max_element(ALL(a)) - a.begin() + 1 << '\n';
    return;
  }
  vector<int> idx(n);
  iota(ALL(idx), 0);
  sort(ALL(idx), [&](int l, int r) { return b[l] < b[r]; });
  if (k == n) {
    cout << n << "\n";
    REP(i, n) cout << idx[i] + 1 << " \n"[i + 1 == n];
    return;
  }
  vector dp(n + 1, vector(k + 1, -INF)), prev(n + 1, vector(k + 1, -1));
  dp[0][0] = 0;
  REP(i, n) {
    int id = idx[i];
    REP(j, k + 1) {
      if (j + 1 <= k) {
        int p = dp[i][j] + a[id] + b[id] * j;
        if (p > dp[i + 1][j + 1]) {
          chmax(dp[i + 1][j + 1], p);
          prev[i + 1][j + 1] = 1;
        }
      }
      int p = dp[i][j] + b[id] * (k - 1);
      if (p > dp[i + 1][j]) {
        chmax(dp[i + 1][j], p);
        prev[i + 1][j] = 0;
      }
    }
  }
  int mx = 0, id;
  for (int i = n; i >= k; --i) {
    if (dp[i][k] > mx) {
      mx = dp[i][k];
      id = i;
    }
  }
  vector<int> ans;
  int j = k;
  for (int i = id; i > 0; --i) {
    if (prev[i][j] == 1) {
      ans.emplace_back(idx[i - 1] + 1);
      --j;
    }
  }
  reverse(ALL(ans));
  vector<bool> exist(n, false);
  for (int e : ans) exist[e - 1] = true;
  int last = ans.back();
  ans.pop_back();
  REP(i, n) {
    if (!exist[idx[i]]) {
      ans.emplace_back(idx[i] + 1);
      ans.emplace_back(-(idx[i] + 1));
    }
  }
  ans.emplace_back(last);
  int m = ans.size();
  cout << m << '\n';
  REP(i, m) cout << ans[i] << " \n"[i + 1 == m];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}