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
struct SegmentTree {
  using Fn = function<Monoid(Monoid, Monoid)>;

  SegmentTree(int sz, Fn fn, const Monoid UNITY) : fn(fn), UNITY(UNITY) {
    init(sz);
    dat.assign(n << 1, UNITY);
  }

  SegmentTree(const vector<Monoid> &a, Fn fn, const Monoid UNITY) : fn(fn), UNITY(UNITY) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize(n << 1);
    REP(i, a_sz) dat[i + n] = a[i];
    for (int i = n - 1; i > 0; --i) dat[i] = fn(dat[i << 1], dat[(i << 1) + 1]);
  }

  void update(int node, Monoid val) {
    node += n;
    dat[node] = val;
    while (node >>= 1) dat[node] = fn(dat[node << 1], dat[(node << 1) + 1]);
  }

  Monoid query(int left, int right) const {
    Monoid l_res = UNITY, r_res = UNITY;
    for (left += n, right += n; left < right; left >>= 1, right >>= 1) {
      if (left & 1) l_res = fn(l_res, dat[left++]);
      if (right & 1) r_res = fn(dat[--right], r_res);
    }
    return fn(l_res, r_res);
  }

  Monoid operator[](const int idx) const { return dat[idx + n]; }

private:
  int n = 1;
  Fn fn;
  const Monoid UNITY;
  vector<Monoid> dat;

  void init(int sz) { while (n < sz) n <<= 1; }
};

int main() {
  int n, m, q; cin >> n >> m >> q;
  struct Node {
    int min, max;
    bool flag;
    Node(int min, int max, bool flag) : min(min), max(max), flag(flag) {}
  };
  auto f = [](Node a, Node b) {
    return Node(min(a.min, b.min), max(a.max, b.max), a.flag || b.flag || (a.min <= b.max));
  };
  SegmentTree<Node> seg(m, f, Node(n, -1, false));
  vector<set<int>> as(m), bs(m);
  while (q--) {
    int i, j; cin >> i >> j; --i; --j;
    if (i & 1) {
      if (bs[j / 2].count(i / 2) == 1) {
        bs[j / 2].erase(i / 2);
      } else {
        bs[j / 2].emplace(i / 2);
      }
    } else {
      if (as[j / 2].count(i / 2) == 1) {
        as[j / 2].erase(i / 2);
      } else {
        as[j / 2].emplace(i / 2);
      }
    }
    seg.update(j / 2, Node(as[j / 2].empty() ? n : *as[j / 2].begin(), bs[j / 2].empty() ? -1 : *bs[j / 2].rbegin(), !as[j / 2].empty() && !bs[j / 2].empty() && *as[j / 2].begin() <= *bs[j / 2].rbegin()));
    cout << (seg.query(0, m).flag ? "NO\n" : "YES\n");
  }
  return 0;
}