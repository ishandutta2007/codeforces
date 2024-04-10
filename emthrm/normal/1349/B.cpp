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
    if (dat[node] < val || right <= a || b <= left) return -1;
    if (right - left == 1) return node - (n - 1);
    int res_l = find(a, b, val, (node << 1) + 1, left, (left + right) >> 1);
    if (res_l != -1) return res_l;
    return find(a, b, val, (node << 1) + 2, (left + right) >> 1, right);
  }
};

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  if (count(ALL(a), k) == 0) {
    cout << "no\n";
    return;
  }
  if (n == 1) {
    cout << "yes\n";
    return;
  }
  function<bool()> solve = [&]() {
    RMQandRAQ<ll> rmq(n, -LINF);
    REP(i, n) rmq.add(i, n, a[i] >= k ? 1 : -1);
    REP(i, n) {
      rmq.add(i, n, a[i] >= k ? -1 : 1);
      if (a[i] >= k && rmq.query(i + 1, n) >= 0) {
        // cout << i << '\n';
        cout << "yes\n";
        return true;
      }
    }
    return false;
  };
  if (solve()) return;
  reverse(ALL(a));
  if (solve()) return;
  cout << "no\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}