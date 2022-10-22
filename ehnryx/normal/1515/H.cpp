#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

constexpr int L = 20;

struct node {
  node *left,  *right;
  int bit, suffix, lazy, ones, zeros, res;
  node(int i): left(nullptr), right(nullptr), bit(i), suffix((1 << (bit + 1)) - 1),
    lazy(0), ones(0), zeros(0), res(i == -1) {}
  void pull() {
    if (bit == -1) return;
    res = (left ? left->res : 0) + (right ? right->res : 0);
    ones = (left ? left->ones : 0) | (right ? right->ones : 0);
    zeros = (left ? left->zeros : 0) | (right ? right->zeros : 0);
    if (left) zeros |= 1 << bit;
    if (right) ones |= 1 << bit;
  }
  void push() {
    if (bit == -1 || !lazy) return;
    if (left) left->apply(lazy);
    if (right) right->apply(lazy);
    lazy = 0;
  }
  void apply(int v) {
    if (bit == -1) return;
    v &= suffix;
    lazy ^= v;
    int toggle = (ones ^ zeros) & v;
    ones ^= toggle;
    zeros ^= toggle;
    if (bit != -1 && v >> bit & 1) {
      swap(left, right);
    }
  }
  int diff() const { return ones & zeros; }
  void print(int prefix = 0) {
    if (bit == -1) {
      cerr << prefix << nl;
      return;
    }
    push();
    if (left) left->print(prefix);
    if (right) right->print(prefix | 1 << bit);
  }
};

node* make_trie(int v) {
  node* cur = new node(-1);
  for (int i = 0; i < L; i++) {
    node* parent = new node(i);
    if (v >> i & 1) {
      parent->right = cur;
    } else {
      parent->left = cur;
    }
    parent->pull();
    cur = parent;
  }
  return cur;
}

node* merge(node* a, node* b) {
  if (a == b) return a;
  if (!a) return b;
  if (!b) return a;
  a->push();
  b->push();
  a->left = merge(a->left, b->left);
  a->right = merge(a->right, b->right);
  a->pull();
  delete b;
  return a;
}

node* extract(node* cur, int l, int r, int s = 0, int e = (1 << L) - 1) {
  if (!cur || r < s || e < l) return nullptr;
  if (l <= s && e <= r) return cur;
  cur->push();
  node* dup = new node(cur->bit);
  int m = (s + e) / 2;
  dup->left = extract(cur->left, l, r, s, m);
  dup->right = extract(cur->right, l, r, m + 1, e);
  if (dup->left == cur->left) cur->left = nullptr;
  if (dup->right == cur->right) cur->right = nullptr;
  cur->pull();
  dup->pull();
  if (dup->res == 0) {
    delete dup;
    return nullptr;
  }
  return dup;
}

void do_xor(node* cur, int v) {
  if (!cur) return;
  cur->apply(v);
}

void do_or(node* cur, int v) {
  if (!cur) return;
  if (!(cur->diff() & v)) return do_xor(cur, v & cur->zeros);
  cur->push();
  do_or(cur->left, v);
  do_or(cur->right, v);
  if (v >> cur->bit & 1) {
    cur->right = merge(cur->left, cur->right);
    cur->left = nullptr;
  }
  cur->pull();
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int n, m;
  cin >> n >> m;
  node* root = nullptr;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    node* leaf = make_trie(a);
    assert(leaf->res == 1);
    root = merge(root, leaf);
  }

  int mask = (1 << L) - 1;
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      node* range = extract(root, l, r);
      if (!range) continue;
      do_xor(range, mask);
      do_or(range, x ^ mask);
      do_xor(range, mask);
      root = merge(root, range);
    } else if (t == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      node* range = extract(root, l, r);
      if (!range) continue;
      do_or(range, x);
      root = merge(root, range);
    } else if (t == 3) {
      int l, r, x;
      cin >> l >> r >> x;
      node* range = extract(root, l, r);
      if (!range) continue;
      do_xor(range, x);
      root = merge(root, range);
    } else {
      int l, r;
      cin >> l >> r;
      node* range = extract(root, l, r);
      cout << (range ? range->res : 0) << nl;
      root = merge(root, range);
    }
  }

  return 0;
}