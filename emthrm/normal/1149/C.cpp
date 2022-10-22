#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
struct Node {
  int a = 0, b = 0, ab = 0, bc = 0, abc = 0;
};

template <typename Monoid, typename OperatorMonoid = Monoid>
struct LazySegTree {
  using MM = function<Monoid(Monoid, Monoid)>;
  using MOI = function<Monoid(Monoid, OperatorMonoid, int)>;
  using OO = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

  LazySegTree(int sz_, const MM mm_, const MOI moi_, const OO oo_, const Monoid &M_UNITY_, const OperatorMonoid &O_UNITY_)
    : mm(mm_), moi(moi_), oo(oo_), M_UNITY(M_UNITY_), O_UNITY(O_UNITY_) {
    init(sz_);
    dat.assign(sz << 1, M_UNITY);
  }

  LazySegTree(const vector<Monoid> &seq, const MM mm_, const MOI moi_, const OO oo_, const Monoid &M_UNITY_, const OperatorMonoid &O_UNITY_)
    :  mm(mm_), moi(moi_), oo(oo_), M_UNITY(M_UNITY_), O_UNITY(O_UNITY_) {
    int seq_sz = seq.size();
    init(seq_sz);
    dat.resize(sz << 1);
    REP(i, seq_sz) dat[i + sz] = seq[i];
    for (int i = sz - 1; i > 0; --i) dat[i] = mm(dat[i << 1], dat[(i << 1) + 1]);
  }

  void update(int a, int b, const OperatorMonoid &value) { update(a, b, value, 1, 0, sz); }

  Monoid query(int a, int b) { return query(a, b, 1, 0, sz); }

  int sz = 1;
  vector<Monoid> dat;
private:
  const MM mm;
  const MOI moi;
  const OO oo;
  const Monoid M_UNITY;
  const OperatorMonoid O_UNITY;
  vector<OperatorMonoid> lazy;
  vector<bool> need_to_be_eval;

  void init(int sz_) {
    while (sz < sz_) sz <<= 1;
    lazy.assign(sz << 1, O_UNITY);
    need_to_be_eval.assign(sz << 1, false);
  }

  inline void evaluate(int node, int len) {
    if (need_to_be_eval[node]) {
      dat[node] = moi(dat[node], lazy[node], len);
      if (node < sz) {
        lazy[node << 1] = oo(lazy[node << 1], lazy[node]);
        need_to_be_eval[node << 1] = true;
        lazy[(node << 1) + 1] = oo(lazy[(node << 1) + 1], lazy[node]);
        need_to_be_eval[(node << 1) + 1] = true;
      }
      lazy[node] = O_UNITY;
      need_to_be_eval[node] = false;
    }
  }

  void update(int a, int b, const OperatorMonoid &value, int node, int left, int right) {
    evaluate(node, right - left);
    if (right <= a || b <= left) return;
    if (a <= left && right <= b) {
      lazy[node] = oo(lazy[node], value);
      need_to_be_eval[node] = true;
      evaluate(node, right - left);
    } else {
      update(a, b, value, node << 1, left, (left + right) >> 1);
      update(a, b, value, (node << 1) + 1, (left + right) >> 1, right);
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
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, q; cin >> n >> q;
  n = 2 * n - 1;
  string s; cin >> s;
  vector<int> depth(n, 0);
  FOR(i, 1, n) depth[i] = depth[i - 1] + (s[i - 1] == '(' ? 1 : -1);
  auto mm = [](Node x, Node y) {
    Node res;
    res.a = max(x.a, y.a);
    res.b = max(x.b, y.b);
    res.ab = max({x.ab, y.ab, x.a + y.b});
    res.bc = max({x.bc, y.bc, x.b + y.a});
    res.abc = max({x.abc, y.abc, x.ab + y.a, x.a + y.bc});
    return res;
  };
  auto moi = [](Node x, int y, int len) {
    x.a += y;
    x.b -= 2 * y;
    x.ab -= y;
    x.bc -= y;
    return x;
  };
  auto oo = [](int x, int y) { return x + y; };
  Node unity;
  unity.a = unity.b = unity.ab = unity.bc = unity.abc = -INF;
  vector<Node> shoki;
  REP(i, n) {
    Node nd;
    nd.a = depth[i];
    nd.b = -2 * depth[i];
    nd.ab = nd.bc = -depth[i];
    nd.abc = 0;
    shoki.emplace_back(nd);
  }
  LazySegTree<Node, int> seg(shoki, mm, moi, oo, unity, 0);
  cout << seg.query(0, n).abc << '\n';
  while (q--) {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    if (s[a - 1] != s[b - 1]) {
      if (s[a - 1] == '(') seg.update(a, b, -2);
      else seg.update(a, b, 2);
    }
    cout << seg.query(0, n).abc << '\n';
    swap(s[a - 1], s[b - 1]);
  }
  return 0;
}