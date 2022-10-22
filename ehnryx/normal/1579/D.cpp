%:include <bits/stdc++.h>
using namespace std;

// START #include "../../../lca/data_structure/splay_tree.h"

// START #include "simple_memory_pool.h"

template <class T, int N>
struct simple_memory_pool {
  array<T, N> memory;
  array<int, N> available;
  int pid;
  simple_memory_pool() {
    iota(begin(available), end(available), 0);
    pid = N;
  }
  T* allocate() {
    return &memory[available[--pid]];
  }
  void deallocate(T* x) {
    available[pid++] = (int)(x - &memory[0]);
  }
};
// END #include "simple_memory_pool.h"
// START #include "../misc/member_function_checker.h"

#define MEMBER_FUNCTION_CHECKER(function) \
  template <typename T> \
  struct _has_##function { \
    using other = struct { char x[2]; }; \
    template <typename C> static char test(decltype(&C::function)); \
    template <typename C> static other test(...); \
    enum { value = sizeof(test<T>(0)) == sizeof(char) }; \
  }

// END #include "../misc/member_function_checker.h"

template <class node_t, int max_size = 0>
struct splay_tree {
  MEMBER_FUNCTION_CHECKER(push);
  MEMBER_FUNCTION_CHECKER(pull);
  static constexpr bool has_push = _has_push<node_t>::value;
  static constexpr bool has_pull = _has_pull<node_t>::value;
  static node_t* const nil;

  static simple_memory_pool<node_t, max_size> memory;
  template <class... Args>
  inline node_t* new_node(const Args&... args) const {
    if constexpr (max_size == 0) {
      return new node_t(args...);
    } else {
      return new (memory.allocate()) node_t(args...);
    }
  }
  inline void del_node(node_t* x) const {
    if constexpr (max_size == 0) {
      delete x;
    } else {
      memory.deallocate(x);
    }
  }

  node_t* root;
  splay_tree(): root(nil) {}
  splay_tree(int n): root(nil) {
    for (int i = 0; i < n; i++) {
      node_t* to_add = new_node();
      to_add->size = 1;
      push_back(to_add);
    }
  }
  ~splay_tree() { if (root != nil) erase_tree(root); }
  void erase_tree(node_t* x) {
    if (x->left != nil) erase_tree(x->left);
    if (x->right != nil) erase_tree(x->right);
    del_node(x);
  }

  void clear() {
    if (root != nil) {
      erase_tree(root);
      root = nil;
    }
  }

  splay_tree dislodge() {
    node_t* ret = root;
    root = nil;
    return splay_tree(ret);
  }

  friend void swap(splay_tree& a, splay_tree& b) {
    swap(a.root, b.root);
  }

  splay_tree(const splay_tree&) = delete;
  splay_tree& operator = (const splay_tree&) = delete;
  splay_tree make_copy() const {
    if (root == nil) return splay_tree(nil);
    return splay_tree(make_copy_rec(root));
  }
  node_t* make_copy_rec(node_t* x) const {
    node_t* cur = new_node(*x);
    if (x->left != nil) {
      cur->left = make_copy_rec(x->left);
      cur->left->parent = cur;
    }
    if (x->right != nil) {
      cur->right = make_copy_rec(x->right);
      cur->right->parent = cur;
    }
    return cur;
  }

  int size() const { return root->size; }
  bool empty() const { return root == nil; }
  int rank(node_t* x) { return splay(x) == nil ? size() : x->left->size; }

  node_t* splay(node_t* x) {
    if (x == nil) return x;
    if constexpr (has_push) push_down_to(x);
    _splay_rec(x);
    pull(x);
    return root = x;
  }

  node_t* splay_to(node_t* x, node_t* to) {
    if (x == nil) return x;
    if (to == nil) return splay(x);
    if constexpr (has_push) push_down_to(x);
    _splay_to_rec(x, to);
    pull(x);
    return x;
  }

  void set_child(node_t* parent, node_t* child, bool left) {
    if (child != nil) {
      child->parent = parent;
    }
    if (parent != nil) {
      if (left) parent->left = child;
      else parent->right = child;
    }
  }
  bool is_left_child(node_t* x) const {
    return x != nil && x->is_left_child();
  }

  //---------------------------------------------------------------------------
  // iterators
  //---------------------------------------------------------------------------

  template <bool forward_it>
  struct iterator {
    const splay_tree* tree_ptr;
    node_t* ptr;
    iterator(): tree_ptr(nil), ptr(nil) {}
    iterator(const splay_tree* t, node_t* x): tree_ptr(t), ptr(x) {}
    iterator(const iterator<!forward_it> rev): tree_ptr(rev.tree_ptr), ptr(rev.ptr) {}
    operator node_t* () const { return ptr; }
    node_t* operator -> () const { return ptr; }
    typename node_t::out_t operator * () const { return ptr->get_value(); }
    iterator& operator ++ () {
      ptr = forward_it ? tree_ptr->next(ptr) : tree_ptr->prev(ptr);
      return *this;
    }
    iterator& operator ++ (int) { return operator ++ (); }
    iterator& operator -- () { return *this = ++iterator<!forward_it>(*this); }
    iterator& operator -- (int) { return operator -- (); }
    template <bool dir>
    bool operator == (const iterator<dir>& other) const { return ptr == other.ptr; }
    template <bool dir>
    bool operator != (const iterator<dir>& other) const { return ptr != other.ptr; }
    bool operator == (const node_t* other) const { return ptr == other; }
    bool operator != (const node_t* other) const { return ptr != other; }
  };
  iterator<true> begin() const {
    return iterator<true>(this, root != nil ? walk_left(root) : root);
  }
  iterator<true> end() const {
    return iterator<true>(this, nil);
  }
  iterator<false> rbegin() const {
    return iterator<false>(this, root != nil ? walk_right(root) : root);
  }
  iterator<false> rend() const {
    return iterator<false>(this, nil);
  }
  template <bool dir> friend iterator<dir> next(iterator<dir> it) { return ++it; }
  template <bool dir> friend iterator<dir> prev(iterator<dir> it) { return --it; }

  //---------------------------------------------------------------------------
  // binary search tree operations
  //---------------------------------------------------------------------------

  template <typename key_t>
  bool contains(const key_t& key) {
    return find(key) != nil;
  }

  template <typename key_t>
  int count(const key_t& key) {
    return rank(upper_bound(key)) - rank(lower_bound(key));
  }

  template <typename key_t, class... Args>
  node_t* insert(const key_t& key, const Args&... args) {
    return insert(new_node(key, args...));
  }

  template <typename key_t>
  void erase(const key_t& key) {
    if (node_t* x = find(key); x != nil) {
      erase(x);
    }
  }

  template <typename key_t, class... Args>
  node_t* insert_if_none(const key_t& key, const Args&... args) {
    if (contains(key)) return nil;
    return insert(new_node(key, args...));
  }

  template <typename key_t>
  void erase_all(const key_t& key) {
    for (node_t* x; (x = find(key)) != nil; ) { // should this be next?
      erase(x);
    }
  }

  node_t* insert(node_t* x) {
    if (node_t* u = upper_bound_path(x->key); u != nil) {
      set_child(u, x, x->key < u->key);
    }
    return splay(x);
  }

  void erase(node_t* x) {
    if (x == nil) return;
    splay(x); // splay should push x
    set_child(nil, x->left, true);
    if (x->right != nil) {
      set_child(nil, x->right, false);
      set_child(splay(walk_left(x->right)), x->left, true);
      pull(root);
    } else if (x->left != nil) {
      splay(x->left);
    } else {
      root = nil;
    }
    del_node(x);
  }

  template <bool dir> void erase(iterator<dir> it) {
    erase(it.ptr);
  }

  void erase_at(int i) {
    erase(at(i));
  }

  template <typename key_t>
  node_t* find(const key_t& key) {
    node_t* u = lower_bound(key); // lower_bound splays
    if (u == nil || u->key != key) return nil;
    return u;
  }

  template <typename key_t>
  node_t* lower_bound(const key_t& key) {
    node_t* u = lower_bound_path(key);
    if (u == nil || key <= u->key) return splay(u);
    return splay(next(u));
  }

  template <typename key_t>
  node_t* upper_bound(const key_t& key) {
    node_t* u = upper_bound_path(key);
    if (u == nil || key < u->key) return splay(u);
    return splay(next(u));
  }

  // goes to a leaf, chooseing left if <= node.key
  template <typename key_t>
  node_t* lower_bound_path(const key_t& key) const {
    if (root == nil) return root;
    node_t* u = root;
    while (true) {
      if constexpr (has_push) push(u);
      if (key <= u->key) {
        if (u->left == nil) {
          return u;
        }
        u = u->left;
      } else {
        if (u->right == nil) {
          return u;
        }
        u = u->right;
      }
    }
  }

  // goes to a leaf, chooseing left if < node.key
  template <typename key_t>
  node_t* upper_bound_path(const key_t& key) const {
    if (root == nil) return root;
    node_t* u = root;
    while (true) {
      if constexpr (has_push) push(u);
      if (key < u->key) {
        if (u->left == nil) {
          return u;
        }
        u = u->left;
      } else {
        if (u->right == nil) {
          return u;
        }
        u = u->right;
      }
    }
  }

  //---------------------------------------------------------------------------
  // next / previous
  //---------------------------------------------------------------------------

  node_t* next(node_t* u) const {
    if (u == nil) throw invalid_argument("next(nil) is not valid");
    if (u->right != nil) {
      if constexpr (has_push) push(u);
      return walk_left(u->right);
    }
    while (u != nil && !is_left_child(u)) {
      u = u->parent;
    }
    u = u != nil ? u->parent : u;
    return u;
  }

  node_t* prev(node_t* u) const {
    if (u == nil) throw invalid_argument("prev(nil) is not valid");
    if (u->left != nil) {
      if constexpr (has_push) push(u);
      return walk_right(u->left);
    }
    while (u != nil && is_left_child(u)) {
      u = u->parent;
    }
    u = u != nil ? u->parent : u;
    return u;
  }

  node_t* walk_left(node_t* u) const {
    assert(u != nil);
    while (u->left != nil) {
      if constexpr (has_push) push(u);
      u = u->left;
    }
    return u;
  }

  node_t* walk_right(node_t* u) const {
    assert(u != nil);
    while (u->right != nil) {
      if constexpr (has_push) push(u);
      u = u->right;
    }
    return u;
  }

  //---------------------------------------------------------------------------
  // rope operations
  //---------------------------------------------------------------------------

  template <class... Args>
  node_t* push_back(const Args&... args) {
    return push_back(new_node(args...));
  }
  template <class... Args>
  node_t* push_front(const Args&... args) {
    return push_front(new_node(args...));
  }
  template <class... Args>
  node_t* insert_before(int ref, const Args&... args) {
    return insert_before(at(ref), new_node(args...));
  }
  template <class... Args>
  node_t* insert_after(int ref, const Args&... args) {
    return insert_after(at(ref), new_node(args...));
  }
  splay_tree split_before(int x) { return split_before(at(x)); }
  splay_tree split_after(int x) { return split_after(at(x)); }

  node_t* first() { return root != nil ? splay(walk_left(root)) : root; }
  node_t* last() { return root != nil ? splay(walk_right(root)) : root; }

  node_t* at(int i) {
    if (i < 0 || i >= size()) return nil; // do we want to throw?
    node_t* u = root;
    while (true) {
      if constexpr (has_push) push(u);
      if (int ls = u->left->size; ls > i) {
        u = u->left;
      } else if (ls < i) {
        u = u->right;
        i -= ls + 1;
      } else {
        return splay(u); // requires splaying
      }
    }
  }

  typename node_t::out_t operator [] (int i)
      __attribute__((deprecated("splay_tree[i] = dereferencing splay_tree.at(i)"))) {
    return at(i)->get_value();
  }

  node_t* push_back(node_t* x) {
    if (root == nil) return root = x;
    node_t* at = last();
    if constexpr (has_push) push(at);
    set_child(at, x, false);
    return splay(x);
  }
  node_t* push_front(node_t* x) {
    if (root == nil) return root = x;
    node_t* at = first();
    if constexpr (has_push) push(at);
    set_child(at, x, true);
    return splay(x);
  }
  void pop_back() { erase(last()); }
  void pop_front() { erase(first()); }

  node_t* insert_before(node_t* ref, node_t* x) {
    if (splay(ref) == nil) {
      return push_back(x);
    }
    if (ref->left == nil) {
      if constexpr (has_push) push(ref);
      set_child(ref, x, true);
    } else {
      ref = prev(ref);
      if constexpr (has_push) push(ref);
      set_child(ref, x, false);
    }
    return splay(x);
  }

  node_t* insert_after(node_t* ref, node_t* x) {
    if (splay(ref) == nil) {
      return push_front(x);
    }
    if(ref->right == nil) {
      if constexpr (has_push) push(ref);
      set_child(ref, x, false);
    } else {
      ref = next(ref);
      if constexpr (has_push) push(ref);
      set_child(ref, x, true);
    }
    return splay(x);
  }

  splay_tree split_before(node_t* x) {
    if (splay(x) == nil) return dislodge();
    if constexpr (has_push) push(x);
    set_child(nil, x->left, true);
    node_t* ret = x->left;
    x->left = nil;
    pull(x);
    return splay_tree(ret);
  }

  splay_tree split_after(node_t* x) {
    if (splay(x) == nil) return dislodge();
    if constexpr (has_push) push(x);
    set_child(nil, x->right, true);
    node_t* ret = x->right;
    x->right = nil;
    pull(x);
    return splay_tree(ret);
  }

  void append(splay_tree& second) {
    if (second.root == nil) return;
    if (root == nil) {
      root = second.root;
    } else {
      splay(last());
      if constexpr (has_push) push(root);
      set_child(root, second.root, false);
      pull(root);
      splay(second.root);
    }
    second.root = nil; // no more tree
  }

  //---------------------------------------------------------------------------
  // push / pull
  //---------------------------------------------------------------------------

  // range accumulate
  void pull(node_t* x) const {
    if (x == nil) return;
    x->size = x->left->size + x->right->size + 1;
    if constexpr (has_pull) x->pull();
  }

  // lazy update
  template <bool use = has_push, typename = enable_if_t<use>>
  void push(node_t* x) const {
    x->push();
  }

  template <bool use = has_push, typename = enable_if_t<use>>
  node_t* push_down_to(node_t* x) const {
    if (x != nil) {
      push_down_to(x->parent);
      push(x); // x itself gets pushed too
    }
    return x;
  }

  //---------------------------------------------------------------------------
  // range update / query
  //---------------------------------------------------------------------------

  // ranges are exclusive
  node_t* range(node_t* left, node_t* right) {
    if (left == nil) {
      if (right == nil) return root;
      else return splay(right)->left;
    } else if (right == nil) {
      return splay(left)->right;
    }
    if (left == right) return nil;
    splay(left);
    return splay_to(right, left)->left;
  }

  // should the input be checked ?
  node_t* range(int l, int r) {
    return range(at(l - 1), at(r + 1));
  }

  template <class... Args>
  void update_range(int l, int r, const Args&... args) {
    node_t* x = range(l, r);
    x->put(args...);
    splay(x); // pull to root
  }

  template <class... Args>
  auto query_range(int l, int r, const Args&... args) {
    return range(l, r)->get(args...);
  }

  //---------------------------------------------------------------------------
  // splay / rotate
  //---------------------------------------------------------------------------

private:

  void _splay_rec(node_t* x) {
    if (x->parent == nil) return;
    _rotate(is_left_child(x) == is_left_child(x->parent) ? x->parent : x);
    _rotate(x);
    return _splay_rec(x);
  }

  void _splay_to_rec(node_t* x, node_t* to) {
    if (x->parent == to) return;
    if (x->parent->parent == to) {
      return _rotate(x);
    }
    _rotate(is_left_child(x) == is_left_child(x->parent) ? x->parent : x);
    _rotate(x);
    return _splay_to_rec(x, to);
  }

  void _rotate(node_t* x) {
    if (x->parent == nil) return;
    node_t* p = x->parent;
    bool side = is_left_child(x);
    set_child(p->parent, x, is_left_child(p));
    set_child(p, x->get_child(!side), side);
    set_child(x, p, !side);
    pull(p); // now child of x
  }

  // private constructor
  splay_tree(node_t* other): root(other) {}
};

//-----------------------------------------------------------------------------
// node structs
//-----------------------------------------------------------------------------

template <typename derived_t>
struct splay_node_base_common {
  static derived_t* const nil;
  derived_t *parent, *left, *right;
  int size;
  splay_node_base_common(int s): parent(nil), left(nil), right(nil), size(s) {}
  bool is_left_child() const { return parent == nil || this == parent->left; }
  derived_t* get_child(bool is_left) const { return is_left ? left : right; }
};

template <typename derived_t, typename key_t, typename value_t, typename = void>
struct splay_node_base : splay_node_base_common<derived_t> {
  static_assert(!is_void_v<key_t> && !is_void_v<value_t>);
  using out_t = pair<key_t&, value_t&>; // store as tuple
  key_t key;
  value_t value;
  splay_node_base(): splay_node_base_common<derived_t>(0), key(), value() {}
  splay_node_base(const key_t& k, const value_t& v)
    : splay_node_base_common<derived_t>(1), key(k), value(v) {}
  bool operator < (const derived_t& other) const { return key < other.key; }
  out_t get_value() { return out_t(ref(key), ref(value)); }
};

template <typename derived_t, typename key_t, typename value_t>
struct splay_node_base<derived_t, key_t, value_t,
    enable_if_t<is_void_v<key_t> && !is_void_v<value_t>>>
    : splay_node_base_common<derived_t> {
  using out_t = value_t&;
  value_t value;
  splay_node_base(): splay_node_base_common<derived_t>(0), value() {}
  splay_node_base(const value_t& v): splay_node_base_common<derived_t>(1), value(v) {}
  out_t get_value() { return value; }
};

template <typename derived_t, typename key_t, typename value_t>
struct splay_node_base<derived_t, key_t, value_t,
    enable_if_t<!is_void_v<key_t> && is_void_v<value_t>>>
    : splay_node_base_common<derived_t> {
  using out_t = key_t&;
  key_t key;
  splay_node_base(): splay_node_base_common<derived_t>(0), key() {}
  splay_node_base(const key_t& k): splay_node_base_common<derived_t>(1), key(k) {}
  bool operator < (const derived_t& other) const { return key < other.key; }
  out_t get_value() { return key; }
};

template <typename key_t, typename value_t>
struct splay_node final : splay_node_base<splay_node<key_t, value_t>, key_t, value_t> {
  using splay_node_base<splay_node<key_t, value_t>, key_t, value_t>::splay_node_base;
};

//-----------------------------------------------------------------------------
// nil initialization
//-----------------------------------------------------------------------------

template <typename derived_t>
derived_t* const splay_node_base_common<derived_t>::nil = new derived_t();

template <class node_t, int max_size>
node_t* const splay_tree<node_t, max_size>::nil = node_t::nil;

template <class node_t, int max_size>
simple_memory_pool<node_t, max_size>
splay_tree<node_t, max_size>::memory = simple_memory_pool<node_t, max_size>();

// END #include "../../../lca/data_structure/splay_tree.h"
// START #include "../../../lca/misc/fast_input.h"

template <int buf_size = 10000>
struct fast_input {
  char buf[buf_size], *S, *T, c;
  int positive;
  FILE* ifptr;
  fast_input(FILE* _in = stdin): S(buf), T(buf), ifptr(_in) {}

  inline char getc(void) {
    if (S == T) {
      T = (S = buf) + fread(buf, 1, buf_size, ifptr);
      if (S == T) return EOF;
    }
    return *S++;
  }

  inline void read(char& x) {
    while (isspace(x = getc()));
  }

  inline void read(string& x) {
    x.clear();
    while (isspace(c = getc()));
    for (; !isspace(c); c = getc()) {
      x.push_back(c);
    }
  }

  template <typename var_t, enable_if_t<is_integral_v<var_t>, bool> = true>
  inline void read(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc())) {
      positive = (c ^ '-');
    }
    for (; isdigit(c); c = getc()) {
      x = x * 10 + c - '0';
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename var_t, enable_if_t<is_floating_point_v<var_t>, bool> = true>
  inline void read(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc()) && c != '.') {
      positive = (c ^ '-');
    }
    if (c != '.') {
      for (; isdigit(c); c = getc()) {
        x = x * 10 + c - '0';
      }
    }
    if (c == '.') {
      static var_t div;
      div = 1;
      while (isdigit(c = getc())) {
        x = x * 10 + c - '0';
        div *= 10;
      }
      x /= div;
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename T>
  fast_input& operator >> (T& x) {
    read(x);
    return *this;
  }
};

// END #include "../../../lca/misc/fast_input.h"

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);

  fast_input cin;

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    splay_tree<splay_node<int, int>> a;
    for(int i=1; i<=n; i++) {
      int v;
      cin >> v;
      if(v) a.insert(v, i);
    }
    vector<pair<int, int>> ans;
    while(a.size() > 1) {
      pair<int, int> u = *a.rbegin();
      a.pop_back();
      pair<int, int> v = *a.rbegin();
      a.pop_back();
      ans.emplace_back(u.second, v.second);
      if(--v.first) a.insert(v.first, v.second);
      if(--u.first) a.insert(u.first, u.second);
    }
    cout << size(ans) << nl;
    for(auto [u, v] : ans) {
      cout << u << " " << v << nl;
    }
  }

  return 0;
}