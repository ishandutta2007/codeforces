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
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
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

template <typename MeetSemilattice>
struct SparseTable {
  using Fn = function<MeetSemilattice(MeetSemilattice, MeetSemilattice)>;

  SparseTable() {}

  SparseTable(const vector<MeetSemilattice> &a, Fn fn, MeetSemilattice UNITY = 0) { init(a, fn); }

  void init(const vector<MeetSemilattice> &a, Fn fn_) {
    fn = fn_;
    int n = a.size(), table_h = 0;
    lg.assign(n + 1, 0);
    FOR(i, 2, n + 1) lg[i] = lg[i >> 1] + 1;
    while ((1 << table_h) <= n) ++table_h;
    dat.assign(table_h, vector<MeetSemilattice>(n));
    REP(j, n) dat[0][j] = a[j];
    FOR(i, 1, table_h) for (int j = 0; j + (1 << i) <= n; ++j) {
      dat[i][j] = fn(dat[i - 1][j], dat[i - 1][j + (1 << (i - 1))]);
    }
  }

  MeetSemilattice query(int left, int right) {
    assert(left < right);
    int h = lg[right - left];
    return fn(dat[h][left], dat[h][right - (1 << h)]);
  }

private:
  Fn fn;
  vector<int> lg;
  vector<vector<MeetSemilattice> > dat;
};

void solve(const vector<pair<pair<int, int>, pair<int, int> > > &ab) {
  int n = ab.size();
  vector<int> sb(n), eb(n);
  REP(i, n) tie(sb[i], eb[i]) = ab[i].second;
  SparseTable<int> mx(sb, [](int a, int b) { return max(a, b);}), mn(eb, [](int a, int b) { return min(a, b);});
  REP(i, n - 1) {
    int a, b, c, d;
    tie(a, b) = ab[i].first;
    tie(c, d) = ab[i].second;
    if (ab[i + 1].first.first > b) continue;
    int idx = lower_bound(ALL(ab), make_pair(make_pair(b + 1, -INF), make_pair(-INF, -INF))) - ab.begin();
    if (mx.query(i + 1, idx) > d || mn.query(i + 1, idx) < c) {
      cout << "NO\n";
      exit(0);
    }
  }
}

int main() {
  int n; cin >> n;
  vector<pair<pair<int, int>, pair<int, int> > > ab(n);
  REP(i, n) {
    int sa, ea, sb, eb; cin >> sa >> ea >> sb >> eb;
    ab[i] = {{sa, ea}, {sb, eb}};
  }
  sort(ALL(ab));
  solve(ab);
  REP(i, n) swap(ab[i].first, ab[i].second);
  sort(ALL(ab));
  solve(ab);
  cout << "YES\n";
  return 0;
}