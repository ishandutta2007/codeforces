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

int main() {
  constexpr int M = 6;
  vector<int> a(M); REP(i, M) cin >> a[i];
  sort(ALL(a));
  int n; cin >> n;
  vector<int> b(n); REP(i, n) cin >> b[i];
  sort(ALL(b));
  vector<pair<int, int>> d;
  REP(i, M) REP(j, n) d.emplace_back(b[j] - a[i], j);
  sort(ALL(d));
  map<int, int> mp;
  int ans = INF, j = 0;
  REP(i, d.size()) {
    while (mp.size() < n && j < d.size()) ++mp[d[j++].second];
    if (mp.size() == n) chmin(ans, d[j - 1].first - d[i].first);
    --mp[d[i].second];
    if (mp[d[i].second] == 0) mp.erase(d[i].second);
  }
  cout << ans << '\n';
  return 0;
}