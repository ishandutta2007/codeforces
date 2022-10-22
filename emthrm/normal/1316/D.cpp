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

int main() {
  map<int, char> dir;
  dir[0] = 'U'; dir[1] = 'R'; dir[2] = 'D'; dir[3] = 'L';
  int n; cin >> n;
  vector<vector<int> > y(n, vector<int>(n)), x(n, vector<int>(n));
  vector<vector<char> > ans(n, vector<char>(n, '#'));
  vector<pair<int, int> > vec;
  REP(i, n) REP(j, n) {
    cin >> y[i][j] >> x[i][j]; --x[i][j]; --y[i][j];
    if (y[i][j] == i && x[i][j] == j) {
      ans[i][j] = 'X';
      vec.emplace_back(i, j);
    }
  }
  for (auto pr : vec) {
    int sy, sx; tie(sy, sx) = pr;
    queue<pair<int, int> > que;
    que.emplace(sy, sx);
    while (!que.empty()) {
      int i, j; tie(i, j) = que.front(); que.pop();
      REP(k, 4) {
        int r = i + dy[k], c = j + dx[k];
        if (0 <= r && r < n && 0 <= c && c < n && ans[r][c] == '#' && y[r][c] == sy && x[r][c] == sx) {
          ans[r][c] = dir[k];
          que.emplace(r, c);
        }
      }
    }
  }
  REP(i, n) REP(j, n) {
    if (ans[i][j] != '#') continue;
    if (y[i][j] != -2) {
      cout << "INVALID\n";
      return 0;
    }
    int di = -1, ad_r = -1, ad_c = -1;
    REP(k, 4) {
      int r = i + dy[k], c = j + dx[k];
      if (0 <= r && r < n && 0 <= c && c < n && ans[r][c] == '#' && y[r][c] == -2 && x[r][c] == -2) {
        di = k;
        ad_r = r; ad_c = c;
        break;
      }
    }
    if (di == -1) {
      cout << "INVALID\n";
      return 0;
    }
    ans[i][j] = dir[(di + 2) % 4];
    ans[ad_r][ad_c] = dir[di];
    queue<pair<int, int> > que;
    que.emplace(i, j);
    que.emplace(ad_r, ad_c);
    while (!que.empty()) {
      int p, q; tie(p, q) = que.front(); que.pop();
      REP(k, 4) {
        int r = p + dy[k], c = q + dx[k];
        if (0 <= r && r < n && 0 <= c && c < n && ans[r][c] == '#' && y[r][c] == -2 && x[r][c] == -2) {
          ans[r][c] = dir[k];
          que.emplace(r, c);
        }
      }
    }
  }
  cout << "VALID\n";
  REP(i, n) {
    REP(j, n) cout << ans[i][j];
    cout << '\n';
  }
  return 0;
}