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

void solve() {
  int n; cin >> n;
  vector<int> pos(n);
  REP(i, n) {
    int p; cin >> p; --p;
    pos[p] = i;
  }
  set<int> st;
  REP(i, n) st.emplace(i);
  RMQ<int> rmq(n, -INF);
  REP(i, n) rmq.update(i, 1);
  REP(val, n) {
    int mx = rmq.query(0, n);
    if (rmq[pos[val]] != mx) {
      cout << "No\n";
      return;
    }
    st.erase(pos[val]);
    auto it = st.lower_bound(pos[val]);
    int l = it == st.begin() ? 0 : *prev(it) + 1;
    rmq.update(pos[val], rmq[pos[val]] - (pos[val] - l + 1));
    if (it != st.end()) rmq.update(*it, rmq[*it] + (pos[val] - l + 1));
    // REP(i, n) cout << rmq[i] << " \n"[i + 1 == n];
  }
  cout << "Yes\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}