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
struct RMQ {
  RMQ(int sz, const Monoid UNITY) : UNITY(UNITY) {
    init(sz);
    dat.assign((n << 1) - 1, UNITY);
  }

  RMQ(const vector<Monoid> &a, const Monoid UNITY) : UNITY(UNITY) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = max(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void update(int node, Monoid val) {
    node += n - 1;
    dat[node] = val;
    while (node > 0) {
      node = (node - 1) >> 1;
      dat[node] = max(dat[(node << 1) + 1], dat[(node << 1) + 2]);
    }
  }

  Monoid query(int a, int b) { return query(a, b, 0, 0, n); }

  int find(int a, int b, Monoid val) { return find(a, b, val, 0, 0, n); }

  Monoid operator[](const int idx) const { return dat[idx + n - 1]; }

private:
  int n = 1;
  const Monoid UNITY;
  vector<Monoid> dat;

  void init(int sz) { while (n < sz) n <<= 1; }

  Monoid query(int a, int b, int node, int left, int right) {
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node];
    return max(query(a, b, (node << 1) + 1, left, (left + right) >> 1), query(a, b, (node << 1) + 2, (left + right) >> 1, right));
  }

  int find(int a, int b, Monoid val, int node, int left, int right) {
    if (dat[node] < val || right <= a || b <= left) return -1;
    if (right - left == 1) return node - (n - 1);
    int res_l = find(a, b, val, (node << 1) + 1, left, (left + right) >> 1);
    if (res_l != -1) return res_l;
    return find(a, b, val, (node << 1) + 2, (left + right) >> 1, right);
  }
};

template <typename Monoid>
struct RMinQ {
  RMinQ(int sz, const Monoid UNITY) : UNITY(UNITY) {
    init(sz);
    dat.assign((n << 1) - 1, UNITY);
  }

  RMinQ(const vector<Monoid> &a, const Monoid UNITY) : UNITY(UNITY) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = min(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void update(int node, Monoid val) {
    node += n - 1;
    dat[node] = val;
    while (node > 0) {
      node = (node - 1) >> 1;
      dat[node] = min(dat[(node << 1) + 1], dat[(node << 1) + 2]);
    }
  }

  Monoid query(int a, int b) { return query(a, b, 0, 0, n); }

  int find(int a, int b, Monoid val) { return find(a, b, val, 0, 0, n); }

  Monoid operator[](const int idx) const { return dat[idx + n - 1]; }

private:
  int n = 1;
  const Monoid UNITY;
  vector<Monoid> dat;

  void init(int sz) { while (n < sz) n <<= 1; }

  Monoid query(int a, int b, int node, int left, int right) {
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node];
    return min(query(a, b, (node << 1) + 1, left, (left + right) >> 1), query(a, b, (node << 1) + 2, (left + right) >> 1, right));
  }

  int find(int a, int b, Monoid val, int node, int left, int right) {
    if (dat[node] > val || right <= a || b <= left) return -1;
    if (right - left == 1) return node - (n - 1);
    int res_l = find(a, b, val, (node << 1) + 1, left, (left + right) >> 1);
    if (res_l != -1) return res_l;
    return find(a, b, val, (node << 1) + 2, (left + right) >> 1, right);
  }
};

int main() {
  int n; cin >> n;
  vector<int> m(n); REP(i, n) cin >> m[i];
  vector<int> comp(m);
  comp.emplace_back(0);
  sort(ALL(comp));
  unique(comp);
  vector<int> a(n);
  REP(i, n) a[i] = lower_bound(ALL(comp), m[i]) - comp.begin();
  vector<ll> l(n), r(n + 1, 0);
  {
    RMQ<int> rmq(comp.size(), -INF);
    rmq.update(0, -1);
    REP(i, n) {
      if (i > 0 && m[i - 1] > m[i]) {
        int idx = rmq.query(0, a[i] + 1);
        l[i] = (idx != -1 ? l[idx] : 0) + 1LL * m[i] * (i - idx);
      } else {
        l[i] = (i > 0 ? l[i - 1] : 0) + m[i];
      }
      rmq.update(a[i], i);
    }
  }
  {
    RMinQ<int> rmq(comp.size(), INF);
    rmq.update(0, n);
    for (int i = n - 1; i >= 0; --i) {
      if (i + 1 < n && m[i] < m[i + 1]) {
        int idx = rmq.query(0, a[i] + 1);
        r[i] = r[idx] + 1LL * m[i] * (idx - i);
      } else {
        r[i] = r[i + 1] + m[i];
      }
      rmq.update(a[i], i);
    }
  }
  // REP(i, n) cout << r[i] << " \n"[i + 1 == n];
  int idx;
  ll mx = 0;
  REP(i, n) {
    ll here = l[i] + r[i] - m[i];
    if (here > mx) {
      mx = here;
      idx = i;
    }
  }
  vector<int> ans(n);
  ans[idx] = m[idx];
  {
    int mn = m[idx];
    for (int i = idx - 1; i >= 0; --i) {
      chmin(mn, m[i]);
      ans[i] = mn;
    }
  }
  {
    int mn = m[idx];
    FOR(i, idx + 1, n) {
      chmin(mn, m[i]);
      ans[i] = mn;
    }
  }
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
  return 0;
}