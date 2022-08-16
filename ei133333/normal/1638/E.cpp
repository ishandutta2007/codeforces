#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in: v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e: t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

template< typename T >
class RandomizedBinarySearchTree {
public:
  using F = function< T(T, T) >;

  struct Node {
    Node *l, *r;
    int idx, cnt;
    T key, sum;

    Node() = default;

    Node(int idx, const T &k) : idx(idx), cnt(1), key(k), sum(k), l(nullptr), r(nullptr) {}
  };

  inline int xor128() {
    static int x = 123456789;
    static int y = 362436069;
    static int z = 521288629;
    static int w = 88675123;
    int t;

    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }


  void dump(Node *t, typename vector< T >::iterator &it) const {
    if(!t) return;
    dump(t->l, it);
    *it = t->key;
    dump(t->r, ++it);
  }

  inline size_t count(const Node *t) const {
    return t ? t->cnt : 0;
  }

  inline T sum(const Node *t) const {
    return t ? t->sum : e;
  }

  inline Node *update(Node *t) {
    t->cnt = count(t->l) + count(t->r) + 1;
    t->sum = f(f(sum(t->l), t->key), sum(t->r));
    return t;
  }

  vector< Node > pool;
  int ptr;
  const F f;
  const T e;

  RandomizedBinarySearchTree(size_t sz, const F &f, const T &e) : pool(sz), f(f), ptr(0), e(e) {}

  inline Node *alloc(int idx, const T &v) {
    return &(pool[ptr++] = Node(idx, v));
  }

  Node *merge(Node *l, Node *r) {
    if(!l || !r) return l ? l : r;
    if(xor128() % (l->cnt + r->cnt) < l->cnt) {
      l->r = merge(l->r, r);
      return update(l);
    } else {
      r->l = merge(l, r->l);
      return update(r);
    }
  }

  template< typename... Args >
  Node *merge(Node *p, Args... args) {
    return merge(p, merge(args...));
  }

  pair< Node *, Node * > split(Node *t, int k) {
    if(!t) return {t, t};
    if(k < t->idx) {
      auto s = split(t->l, k);
      t->l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(t->r, k);
      t->r = s.first;
      return {update(t), s.second};
    }
  }

  void push_back(Node *&t, int idx, const T &v) {
    t = merge(t, alloc(idx, v));
  }

  size_t size(Node *t) const {
    return count(t);
  }

  bool empty(Node *t) const {
    return !t;
  }
};

int main() {
  int N, Q;
  cin >> N >> Q;
  using RBST = RandomizedBinarySearchTree< int64 >;
  auto f = [](int64 a, int64 b) { return a + b; };
  RBST rbst(3000000, f, 0);
  vector< vector< pair< int, int > > > addev(N + 1), delev(N + 1);
  vector< vector< int > > qs(N);
  vector< RBST::Node * > mp(N + 1, nullptr);
  for(int i = 0; i < Q; i++) {
    string s;
    cin >> s;
    if(s == "Color") {
      int l, r, c;
      cin >> l >> r >> c;
      --l;
      addev[l].emplace_back(i, c);
      delev[r].emplace_back(i, c);
    } else if(s == "Add") {
      int c, x;
      cin >> c >> x;
      rbst.push_back(mp[c], i, x);
    } else {
      int k;
      cin >> k;
      --k;
      qs[k].emplace_back(i);
    }
  }
  map< int, int > vs;
  vs[-1] = 1;
  vs[Q] = -1;
  vector< int64 > ans(Q, -1);
  RBST::Node *root = mp[1];
  mp[1] = nullptr;
  for(int i = 0; i < N; i++) {
    for(auto&[j, c]: delev[i]) {
      auto it = vs.lower_bound(j);
      auto pre = prev(it), nxt = next(it);
      // [pre, nxt) [it, nxt) -> [pre, nxt)
      if(pre->second != c) {
        auto[aaa, bbb]=rbst.split(mp[c], it->first);
        auto[AA, BB]=rbst.split(root, it->first);
        auto[CC, DD]=rbst.split(BB, nxt->first);
        auto[aa, bb]=rbst.split(mp[pre->second], it->first);
        auto[cc, dd]=rbst.split(bb, nxt->first);
        mp[c] = rbst.merge(aaa, CC, bbb);
        mp[pre->second] = rbst.merge(aa, dd);
        root = rbst.merge(AA, cc, DD);
      }
      vs.erase(it);
    }
    for(auto&[j, c]: addev[i]) {
      vs[j] = c;
      auto it = vs.lower_bound(j);
      auto pre = prev(it), nxt = next(it);
      // [pre, nxt) -> [pre, it) [it, nxt)
      if(pre->second != c) {
        auto[aaa, bbb]=rbst.split(mp[c], it->first);
        auto[ccc, ddd]=rbst.split(bbb, nxt->first);
        auto[AA, BB]=rbst.split(root, it->first);
        auto[CC, DD]=rbst.split(BB, nxt->first);
        auto[aa, bb]=rbst.split(mp[pre->second], it->first);
        mp[c] = rbst.merge(aaa, ddd);
        mp[pre->second] = rbst.merge(aa, CC, bb);
        root = rbst.merge(AA, ccc, DD);
      }
    }
    for(auto &j: qs[i]) {
      auto[AA, BB]=rbst.split(root, j);
      ans[j] = rbst.sum(AA);
      root = rbst.merge(AA, BB);
    }
  }
  for(auto &a: ans) if(~a) cout << a << "\n";
}