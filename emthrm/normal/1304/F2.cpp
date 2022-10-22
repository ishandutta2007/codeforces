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

template <typename Monoid>
struct RMQandRAQ {
  RMQandRAQ(int sz, const Monoid UNITY, const Monoid DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    init(sz);
    dat.assign((n << 1) - 1, DEFAULT);
  }

  RMQandRAQ(const vector<Monoid> &a, const Monoid UNITY, const Monoid DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = max(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void add(int a, int b, Monoid val) { add(a, b, val, 0, 0, n); }

  Monoid query(int a, int b) { return query(a, b, 0, 0, n); }

  Monoid operator[](const int idx) { return query(idx, idx + 1); }

  int find(int a, int b, Monoid val) { return find(a, b, val, 0, 0, n); }

private:
  int n = 1;
  const Monoid UNITY, DEFAULT;
  vector<Monoid> dat, lazy;

  void init(int sz) {
    while (n < sz) n <<= 1;
    lazy.assign((n << 1) - 1, DEFAULT);
  }

  inline void evaluate(int node) {
    if (lazy[node] != DEFAULT) {
      dat[node] += lazy[node];
      if (node < n - 1) {
        lazy[(node << 1) + 1] += lazy[node];
        lazy[(node << 1) + 2] += lazy[node];
      }
      lazy[node] = DEFAULT;
    }
  }

  void add(int a, int b, Monoid val, int node, int left, int right) {
    evaluate(node);
    if (right <= a || b <= left) return;
    if (a <= left && right <= b) {
      lazy[node] += val;
      evaluate(node);
    } else {
      add(a, b, val, (node << 1) + 1, left, (left + right) >> 1);
      add(a, b, val, (node << 1) + 2, (left + right) >> 1, right);
      dat[node] = max(dat[(node << 1) + 1], dat[(node << 1) + 2]);
    }
  }

  Monoid query(int a, int b, int node, int left, int right) {
    evaluate(node);
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node];
    return max(query(a, b, (node << 1) + 1, left, (left + right) >> 1), query(a, b, (node << 1) + 2, (left + right) >> 1, right));
  }

  int find(int a, int b, Monoid val, int node, int left, int right) {
    evaluate(node);
    if (dat[node] > val || right <= a || b <= left) return -1;
    if (right - left == 1) return node - (n - 1);
    int res_l = find(a, b, val, (node << 1) + 1, left, (left + right) >> 1);
    if (res_l != -1) return res_l;
    return find(a, b, val, (node << 1) + 2, (left + right) >> 1, right);
  }
};

int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int> > animal(n + 1, vector<int>(m, 0)); REP(i, n) REP(j, m) cin >> animal[i][j];
  vector<vector<int> > sum(n + 1, vector<int>(m + 1, 0));
  REP(i, n) REP(j, m) sum[i][j + 1] = animal[i][j];
  REP(i, n + 1) FOR(j, 1, m + 1) sum[i][j] += sum[i][j - 1];
  // REP(i, n + 1) REP(j, m + 1) cout << sum[i][j] << " \n"[j == m];
  vector<RMQandRAQ<int> > rmq(n, RMQandRAQ<int>(m - k + 1, -INF));
  REP(j, m - k + 1) rmq[0].add(j, j + 1, sum[0][j + k] - sum[0][j] + sum[1][j + k] - sum[1][j]);
  FOR(i, 1, n) {
    REP(j, k - 1) rmq[i - 1].add(0, j + 1, -animal[i][j]);
    FOR(j, k - 1, m) {
      rmq[i - 1].add(j - k + 1, j + 1, -animal[i][j]);
      int pos = j - k + 1, animals = sum[i][pos + k] - sum[i][pos] + sum[i + 1][pos + k] - sum[i + 1][pos];
      rmq[i].add(pos, pos + 1, rmq[i - 1].query(0, m - k + 1) + animals);
      rmq[i - 1].add(max(pos - k + 1, 0), pos + 1, animal[i][pos]);
    }
    FOR(j, m - k + 1, m) rmq[i - 1].add(j - k + 1, m - k + 1, animal[i][j]);
  }
  // REP(i, n) REP(j, m - k + 1) cout << rmq[i][j] << " \n"[j + 1 == m - k + 1];
  cout << rmq[n - 1].query(0, m - k + 1) << '\n';
  return 0;
}