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

template <typename T>
struct CumulativeSum {
  CumulativeSum(int h, int w) { init(h, w); }

  template <typename U>
  CumulativeSum(const vector<vector<U>> &a) {
    init(a.size(), a.front().size());
    REP(i, h) REP(j, w) dat[i + 1][j + 1] = a[i][j];
  }

  void add(int y, int x, T val) { dat[y + 1][x + 1] += val; }

  void build() {
    REP(i, h) REP(j, w) dat[i + 1][j + 1] += dat[i + 1][j];
    FOR(j, 1, w + 1) FOR(i, 1, h) dat[i + 1][j] += dat[i][j];
  }

  T query(int y1, int x1, int y2, int x2) {
    if (y2 < y1 || x2 < x1) return (T)0;
    return dat[y2 + 1][x2 + 1] - dat[y2 + 1][x1] - dat[y1][x2 + 1] + dat[y1][x1];
  }

private:
  int h, w;
  vector<vector<T>> dat;

  void init(int h_, int w_) {
    h = h_;
    w = w_;
    dat.assign(h + 1, vector<T>(w + 1, 0));
  }
};

int main() {
  int h, w, k; cin >> h >> w >> k;
  vector<string> c(h); REP(i, h) cin >> c[i];
  vector hasu(h, vector(w, 0));
  REP(i, h) REP(j, w) hasu[i][j] = c[i][j] == '#';
  CumulativeSum<int> cs(hasu);
  cs.build();
  int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2; --y1; --x1; --y2; --x2;
  vector dist(h, vector(w, INF));
  dist[y1][x1] = 0;
  vector<set<int>> row(h), col(w);
  REP(i, h) REP(j, w) {
    row[i].emplace(j);
    col[j].emplace(i);
  }
  row[y1].erase(x1);
  col[x1].erase(y1);
  queue<pair<int, int>> que;
  que.emplace(y1, x1);
  while (!que.empty()) {
    auto [i, j] = que.front(); que.pop();
    vector<pair<int, int>> era_row, era_col;
    for (auto it = row[i].lower_bound(j); it != row[i].end(); ++it) {
      int x = *it;
      if (x - j > k || cs.query(i, j, i, x) > 0) break;
      dist[i][x] = dist[i][j] + 1;
      era_row.emplace_back(i, x);
      era_col.emplace_back(x, i);
      que.emplace(i, x);
    }
    {
      auto it = row[i].lower_bound(j);
      if (!row[i].empty() && it != row[i].begin()) {
        do {
          it = prev(it);
          int x = *it;
          if (j - x > k || cs.query(i, x, i, j) > 0) break;
          dist[i][x] = dist[i][j] + 1;
          era_row.emplace_back(i, x);
          era_col.emplace_back(x, i);
          que.emplace(i, x);
        } while (it != row[i].begin());
      }
    }
    for (auto it = col[j].lower_bound(i); it != col[j].end(); ++it) {
      int y = *it;
      if (y - i > k || cs.query(i, j, y, j) > 0) break;
      dist[y][j] = dist[i][j] + 1;
      era_row.emplace_back(y, j);
      era_col.emplace_back(j, y);
      que.emplace(y, j);
    }
    {
      auto it = col[j].lower_bound(i);
      if (!col[j].empty() && it != col[j].begin()) {
        do {
          it = prev(it);
          int y = *it;
          if (i - y > k || cs.query(y, j, i, j) > 0) break;
          dist[y][j] = dist[i][j] + 1;
          era_row.emplace_back(y, j);
          era_col.emplace_back(j, y);
          que.emplace(y, j);
        } while (it != col[j].begin());
      }
    }
    for (auto [y, x] : era_row) row[y].erase(x);
    for (auto [x, y] : era_col) col[x].erase(y);
    // cout << i << ' ' << j << endl;
  }
  // REP(i, h) REP(j, w) cout << dist[i][j] << " \n"[j + 1 == w];
  cout << (dist[y2][x2] == INF ? -1 : dist[y2][x2]) << '\n';
  return 0;
}