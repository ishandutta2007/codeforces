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

template <typename Monoid, typename OperatorMonoid = Monoid>
struct LazySegmentTree {
  using MM = function<Monoid(Monoid, Monoid)>;
  using MOI = function<Monoid(Monoid, OperatorMonoid, int)>;
  using OO = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

  LazySegmentTree(int sz, MM mm, MOI moi, OO oo, const Monoid M_UNITY, const OperatorMonoid O_UNITY)
    : mm(mm), moi(moi), oo(oo), M_UNITY(M_UNITY), O_UNITY(O_UNITY) {
    init(sz);
    dat.assign(n << 1, M_UNITY);
  }

  LazySegmentTree(const vector<Monoid> &a, MM mm, MOI moi, OO oo, const Monoid M_UNITY, const OperatorMonoid O_UNITY)
    : mm(mm), moi(moi), oo(oo), M_UNITY(M_UNITY), O_UNITY(O_UNITY) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize(n << 1);
    REP(i, a_sz) dat[i + n] = a[i];
    for (int i = n - 1; i > 0; --i) dat[i] = mm(dat[i << 1], dat[(i << 1) + 1]);
  }

  void update(int a, int b, OperatorMonoid val) { update(a, b, val, 1, 0, n); }

  Monoid query(int a, int b) { return query(a, b, 1, 0, n); }

  Monoid operator[](const int idx) { return query(idx, idx + 1); }

private:
  int n = 1;
  MM mm;
  MOI moi;
  OO oo;
  const Monoid M_UNITY;
  const OperatorMonoid O_UNITY;
  vector<Monoid> dat;
  vector<OperatorMonoid> lazy;
  vector<bool> need_to_be_eval;

  void init(int sz) {
    while (n < sz) n <<= 1;
    lazy.assign(n << 1, O_UNITY);
    need_to_be_eval.assign(n << 1, false);
  }

  inline void evaluate(int node, int len) {
    if (need_to_be_eval[node]) {
      dat[node] = moi(dat[node], lazy[node], len);
      if (node < n) {
        lazy[node << 1] = oo(lazy[node << 1], lazy[node]);
        need_to_be_eval[node << 1] = true;
        lazy[(node << 1) + 1] = oo(lazy[(node << 1) + 1], lazy[node]);
        need_to_be_eval[(node << 1) + 1] = true;
      }
      lazy[node] = O_UNITY;
      need_to_be_eval[node] = false;
    }
  }

  void update(int a, int b, OperatorMonoid val, int node, int left, int right) {
    evaluate(node, right - left);
    if (right <= a || b <= left) return;
    if (a <= left && right <= b) {
      lazy[node] = oo(lazy[node], val);
      need_to_be_eval[node] = true;
      evaluate(node, right - left);
    } else {
      update(a, b, val, node << 1, left, (left + right) >> 1);
      update(a, b, val, (node << 1) + 1, (left + right) >> 1, right);
      dat[node] = mm(dat[node << 1], dat[(node << 1) + 1]);
    }
  }

  Monoid query(int a, int b, int node, int left, int right) {
    evaluate(node, right - left);
    if (right <= a || b <= left) return M_UNITY;
    if (a <= left && right <= b) return dat[node];
    return mm(query(a, b, node << 1, left, (left + right) >> 1), query(a, b, (node << 1) + 1, (left + right) >> 1, right));
  }
};

int main() {
  int n, q; cin >> n >> q;
  string s; cin >> s;
  struct Node {
    int l0, l1, l01, l10, r0, r1, r10, r01, len, ans, rev;
    Node(int l0 = 0, int l1 = 0, int l01 = 0, int l10 = 0, int r0 = 0, int r1 = 0, int r01 = 0, int r10 = 0, int len = 0, int ans = 0, int rev = 0) :
      l0(l0), l1(l1), l01(l01), l10(l10), r0(r0), r1(r1), r01(r01), r10(r10), len(len), ans(ans), rev(rev) {}
  };
  vector<Node> init;
  for (char c : s) {
    // >: 0
    // <: 1
    init.emplace_back(c == '>' ? Node(1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1) : Node(0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1));
  }
  function<Node(Node, Node)> mm = [](Node a, Node b) {
    Node node;
    node.l0 = a.l0 == a.len ? a.l0 + b.l0 : a.l0;
    node.l1 = a.l1 == a.len ? a.l1 + b.l1 : a.l1;
    if (a.l0 == a.len) {
      node.l01 = a.l0 + b.l01;
    } else if (a.l01 == a.len) {
      node.l01 = a.l01 + b.l1;
    } else {
      node.l01 = a.l01;
    }
    if (a.l1 == a.len) {
      node.l10 = a.l1 + b.l10;
    } else if (a.l10 == a.len) {
      node.l10 = a.l10 + b.l0;
    } else {
      node.l10 = a.l10;
    }
    node.r0 = b.r0 == b.len ? b.r0 + a.r0 : b.r0;
    node.r1 = b.r1 == b.len ? b.r1 + a.r1 : b.r1;
    if (b.r0 == b.len) {
      node.r10 = b.r0 + a.r10;
    } else if (b.r10 == b.len) {
      node.r10 = b.r10 + a.r1;
    } else {
      node.r10 = b.r10;
    }
    if (b.r1 == b.len) {
      node.r01 = b.r1 + a.r01;
    } else if (b.r01 == b.len) {
      node.r01 = b.r01 + a.r0;
    } else {
      node.r01 = b.r01;
    }
    node.len = a.len + b.len;
    node.ans = max({a.ans, b.ans, node.l01, node.r01});
    chmax(node.ans, max({a.r0 + b.l01, a.r01 + b.l1}));
    node.rev = max({a.rev, b.rev, node.l10, node.r10});
    chmax(node.rev, max({a.r1 + b.l10, a.r10 + b.l0}));
    return node;
  };
  function<Node(Node, int, int)> moi = [](Node m, int o, int i) {
    if (o) {
      swap(m.l0, m.l1);
      swap(m.l01, m.l10);
      swap(m.r0, m.r1);
      swap(m.r01, m.r10);
      swap(m.ans, m.rev);
    }
    return m;
  };
  function<int(int, int)> oo = [](int a, int b) { return a ^ b; };
  LazySegmentTree<Node, int> seg(init, mm, moi, oo, Node(), 0);
  while (q--) {
    int l, r; cin >> l >> r; --l; --r;
    seg.update(l, r + 1, 1);
    // FOR(i, l, r + 1) s[i] = s[i] == '<' ? '>' : '<';
    // cout << s << '\n';
    // REP(s, n) FOR(t, s, n) {
    //   Node node = seg.query(s, t + 1);
    //   cout << '[' << s << ',' << t << "] ";
    //   cout << "l0:" << node.l0 << ' '
    //        << "l1:" << node.l1 << ' '
    //        << "l01:" << node.l01 << ' '
    //        << "l10:" << node.l10 << ' '
    //        << "r0:" << node.r0 << ' '
    //        << "r1:" << node.r1 << ' '
    //        << "r01:" << node.r01 << ' '
    //        << "r10:" << node.r10 << ' '
    //        << "len:" << node.len << ' '
    //        << "ans:" << node.ans << ' '
    //        << "rev:" << node.rev << '\n';
    // }
    cout << seg.query(l, r + 1).ans << '\n';
  }
  return 0;
}