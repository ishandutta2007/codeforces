#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

template< typename Monoid >
struct PersistentSegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  struct Node {
    Monoid data;
    Node *l, *r;

    Node(const Monoid &data) : data(data), l(nullptr), r(nullptr) {}
  };


  int sz;
  const F f;
  const Monoid M1;

  PersistentSegmentTree(const F f, const Monoid &M1) : f(f), M1(M1) {}

  Node *build(vector< Monoid > &v) {
    sz = (int) v.size();
    return build(0, (int) v.size(), v);
  }

  Node *merge(Node *l, Node *r) {
    auto t = new Node(f(l->data, r->data));
    t->l = l;
    t->r = r;
    return t;
  }

  Node *build(int l, int r, vector< Monoid > &v) {
    if(l + 1 >= r) return new Node(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }

  Node *update(int a, const Monoid &x, Node *k, int l, int r) {
    if(r <= a || a + 1 <= l) {
      return k;
    } else if(a <= l && r <= a + 1) {
      return new Node(min(k->data,x));
    } else {
      return merge(update(a, x, k->l, l, (l + r) >> 1), update(a, x, k->r, (l + r) >> 1, r));
    }
  }

  Node *update(Node *t, int k, const Monoid &x) {
    return update(k, x, t, 0, sz);
  }

  Monoid query(int a, int b, Node *k, int l, int r) {
    if(r <= a || b <= l) {
      return M1;
    } else if(a <= l && r <= b) {

      return k->data;
    } else {
      return f(query(a, b, k->l, l, (l + r) >> 1),
               query(a, b, k->r, (l + r) >> 1, r));
    }
  }

  Monoid query(Node *t, int a, int b) {
    return query(a, b, t, 0, sz);
  }
};

const int INF = 1 << 30;

int main() {
  int N, M, K;
  int L[300000], R[300000], P[300000];

  scanf("%d %d %d", &N, &M, &K);
  vector< int > xs;
  for(int i = 0; i < K; i++) {
    scanf("%d %d %d", &L[i], &R[i], &P[i]);
    --L[i], --P[i];
    xs.emplace_back(L[i]);
  }

  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  vector< pair< int, int > > ev[300000];
  for(int i = 0; i < K; i++) {
    L[i] = lower_bound(begin(xs), end(xs), L[i]) - begin(xs);
    ev[L[i]].emplace_back(R[i], P[i]);
  }
  auto f = [](int a, int b) { return max(a, b); };
  using Seg = PersistentSegmentTree< int >;
  Seg seg(f, -1);
  vector< int > init(100000, INF);
  auto base = seg.build(init);
  vector< Seg::Node * > nodes;
  nodes.emplace_back(base);
  for(int i = xs.size() - 1; i >= 0; i--) {
    for(auto &p : ev[i]) base = seg.update(base, p.second, p.first);
    nodes.emplace_back(base);
  }
  reverse(begin(nodes), end(nodes));

  for(int i = 0; i < M; i++) {
    int a, b, x, y;
    scanf("%d %d %d %d", &a, &b, &x, &y);
    --a, --x;
    x = lower_bound(begin(xs), end(xs), x) - begin(xs);

    if(seg.query(nodes[x], a, b) > y) puts("no");
    else puts("yes");
    fflush(stdout);
  }
}