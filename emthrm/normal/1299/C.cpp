#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<ll> sum(n + 1, 0);
  REP(i, n) sum[i + 1] = sum[i] + a[i];
  vector<int> s{0};
  FOR(i, 1, n) {
    s.emplace_back(i);
    while (s.size() >= 2) {
      int u = s[s.size() - 2], v = s.back();
      if ((sum[v] - sum[u]) * (i + 1 - u) < (sum[i + 1] - sum[u]) * (v - u)) break;
      s.pop_back();
    }
  }
  s.emplace_back(n);
  vector<double> ans(n);
  REP(i, s.size() - 1) {
    double val = 1.0 * (sum[s[i + 1]] - sum[s[i]]) / (s[i + 1] - s[i]);
    FOR(j, s[i], s[i + 1]) ans[j] = val;
  }
  REP(i, n) cout << ans[i] << '\n';
  return 0;
}