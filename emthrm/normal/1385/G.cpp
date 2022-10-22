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
  int n; cin >> n;
  vector<int> a(n), b(n);
  vector<vector<pair<int, int>>> pos(n);
  REP(i, n) {
    cin >> a[i]; --a[i];
    pos[a[i]].emplace_back(0, i);
  }
  REP(i, n) {
    cin >> b[i]; --b[i];
    pos[b[i]].emplace_back(1, i);
  }
  REP(i, n) {
    if (pos[i].size() != 2) {
      cout << "-1\n";
      return;
    }
  }
  vector<int> ans;
  vector visited(n, false);
  REP(s, n) {
    if (visited[s]) continue;
    vector<bool> same;
    vector<int> idx;
    visited[s] = true;
    same.emplace_back(pos[s][0].first == pos[s][1].first);
    idx.emplace_back(pos[s][1].second);
    int i = pos[s][1].first, j = pos[s][1].second;
    while (true) {
      // cout << i << ' ' << j << '\n';
      int nx = i == 0 ? b[j] : a[j];
      if (visited[nx]) break;
      i ^= 1;
      visited[nx] = true;
      same.emplace_back(pos[nx][0].first == pos[nx][1].first);
      if (pos[nx][0].first == i && pos[nx][0].second == j) {
        i = pos[nx][1].first;
        j = pos[nx][1].second;
      } else {
        i = pos[nx][0].first;
        j = pos[nx][0].second;
      }
      idx.emplace_back(j);
    }
    int x = same.size();
    // REP(i, x) cout << same[i] << ' ';
    // cout << " : ";
    // REP(i, x) cout << idx[i] << " \n"[i + 1 == x];
    vector dp(x, vector(2, vector(2, INF)));
    vector prev(x, vector(2, vector(2, make_pair(-1, -1))));
    dp[0][same[0]][false] = 0;
    dp[0][!same[0]][true] = 1;
    FOR(i, 1, x) {
      REP(l, 2) {
        int cost = dp[i - 1][l][same[i]];
        if (cost < dp[i][l][false]) {
          dp[i][l][false] = cost;
          prev[i][l][false] = {same[i], false};
        }
      }
      // flip
      REP(l, 2) {
        int cost = dp[i - 1][l][!same[i]] + 1;
        if (cost < dp[i][l][true]) {
          dp[i][l][true] = cost;
          prev[i][l][true] = {!same[i], true};
        }
      }
    }
    int k;
    if (dp[x - 1][true][true] < dp[x - 1][false][false]) {
      j = k = true;
    } else {
      j = k = false;
    }
    for (int i = x - 1; i > 0; --i) {
      auto [nxk, flip] = prev[i][j][k];
      if (flip) ans.emplace_back(idx[i]);
      k = nxk;
    }
    if (k) ans.emplace_back(idx[0]);
  }
  int k = ans.size();
  cout << k << '\n';
  REP(i, k) cout << ans[i] + 1 << " \n"[i + 1 == k];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}