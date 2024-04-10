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

template <typename T>
struct CumulativeSum {
  CumulativeSum(int h, int w) { init(h, w); }

  template <typename U>
  CumulativeSum(const vector<vector<U> > &a) {
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
  vector<vector<T> > dat;

  void init(int h_, int w_) {
    h = h_;
    w = w_;
    dat.assign(h + 1, vector<T>(w + 1, 0));
  }
};

int main() {
  map<char, int> mp;
  mp['R'] = 0; mp['G'] = 1; mp['Y'] = 2; mp['B'] = 3;
  int n, m, q; cin >> n >> m >> q;
  vector<string> s(n); REP(i, n) cin >> s[i];
  vector<vector<vector<int> > > color(4, vector<vector<int> >(n, vector<int>(m, 0)));
  REP(i, n) REP(j, m) ++color[mp[s[i][j]]][i][j];
  vector<CumulativeSum<int> > cnt;
  REP(i, 4) {
    cnt.emplace_back(color[i]);
    cnt[i].build();
  }
  color.clear();
  color.shrink_to_fit();
  vector<vector<int> > memo(n, vector<int>(m, 0));
  REP(i, n) REP(j, m) {
    if (s[i][j] != 'R') continue;
    FOR(k, 1, 251) {
      if (i + k * 2 - 1 >= n || j + k * 2 - 1 >= m) break;
      if (cnt[0].query(i, j, i + k - 1, j + k - 1) < k * k) continue;
      if (cnt[1].query(i, j + k, i + k - 1, j + k * 2 - 1) < k * k) continue;
      if (cnt[2].query(i + k, j, i + k * 2 - 1, j + k - 1) < k * k) continue;
      if (cnt[3].query(i + k, j + k, i + k * 2 - 1, j + k * 2 - 1) < k * k) continue;
      memo[i][j] = k;
      break;
    }
  }
  // REP(i, n) REP(j, m) cout << memo[i][j] << " \n"[j + 1 == m];
  s.clear();
  s.shrink_to_fit();
  cnt.clear();
  cnt.shrink_to_fit();
  vector<vector<vector<int> > > sum(251, vector<vector<int> >(n, vector<int>(m, 0)));
  REP(i, n) REP(j, m) ++sum[memo[i][j]][i][j];
  memo.clear();
  memo.shrink_to_fit();
  FOR(i, 1, 251) {
    cnt.emplace_back(sum[i]);
    cnt[i - 1].build();
  }
  sum.clear();
  sum.shrink_to_fit();
  while (q--) {
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; --r1; --c1; --r2; --c2;
    for (int ans = 250; ans >= 0; --ans) {
      if (ans == 0) {
        cout << "0\n";
        break;
      }
      int R2 = r2 - ans * 2 + 1, C2 = c2 - ans * 2 + 1;
      if (R2 < r1 || C2 < c1) continue;
      if (cnt[ans - 1].query(r1, c1, R2, C2) > 0) {
        cout << ans * ans * 4 << '\n';
        break;
      }
    }
  }
  return 0;
}