#include <bits/stdc++.h>
using namespace std;

// START #include "../../../lca/data_structure/splay_tree.h"

struct splay_node {
  int size;
  splay_node *parent, *left, *right;
  splay_node(): size(1), parent(nullptr), left(nullptr), right(nullptr) {}
  bool left_child() const { return parent == nullptr || this == parent->get_child(true); }
  splay_node* get_child(bool is_left) const { return is_left ? left : right; }
};

template <typename T>
struct splay_node_comparable {
  T key;
  int size;
  splay_node_comparable *parent, *left, *right;
  splay_node_comparable(): key(), size(1), parent(nullptr), left(nullptr), right(nullptr) {}
  splay_node_comparable(const T& k):
    key(k), size(1), parent(nullptr), left(nullptr), right(nullptr) {}
  bool left_child() const { return parent == nullptr || this == parent->get_child(true); }
  splay_node_comparable* get_child(bool is_left) const { return is_left ? left : right; }
  bool operator < (const splay_node_comparable& other) const { return key < other.key; }
};

template <class node_t = splay_node>
struct splay_tree {
  node_t* root;
  splay_tree(): root(nullptr) {}

  node_t* splay(node_t* x) {
    if (x == nullptr) return x;
    return root = splay_rec(x);
  }

  node_t* insert(node_t* x) {
    if (x->parent || x->left || x->right) {
      throw invalid_argument("`insert(node_t*)` expects a singleton node");
    }
    if (node_t* u = upper_bound_path(x->key); u != nullptr) {
      if (x->key < u->key) assert(u->left == nullptr);
      else assert(u->right == nullptr);
      set_child(u, x, x->key < u->key);
    }
    return splay(x);
  }

  void erase(node_t* x) {
    if (x == nullptr) return;
    splay(x);
    set_child(nullptr, x->left, true);
    if (x->right) {
      set_child(nullptr, x->right, false);
      set_child(splay(walk_left(x->right)), x->left, true);
    } else if (x->left) {
      splay(x->left);
    } else {
      root = nullptr;
    }
    delete x;
  }

  template <typename T>
  node_t* find(const T& key) {
    node_t* u = lower_bound(key); // lower_bound splays
    if (u == nullptr || u->key != key) return nullptr;
    return u;
  }
  template <typename T>
  node_t* lower_bound(const T& key) {
    node_t* u = lower_bound_path(key);
    if (u == nullptr || key <= u->key) return splay(u);
    return splay(next(u));
  }
  template <typename T>
  node_t* upper_bound(const T& key) {
    node_t* u = upper_bound_path(key);
    if (u == nullptr || key < u->key) return splay(u);
    return splay(next(u));
  }

  static node_t* next(node_t* u) {
    if (u == nullptr) throw invalid_argument("next(nullptr) is not valid");
    if (u->right) return walk_left(u->right);
    while (u != nullptr && !left_child(u)) {
      u = u->parent;
    }
    return u ? u->parent : u;
  }

  int size() const { return get_size(root); }
  int rank(node_t* x) { return get_size(splay(x)->left); }

  struct iterator {
    node_t* ptr;
    iterator(node_t* x = nullptr): ptr(x) {}
    const node_t* operator -> () const { return ptr; }
    const node_t& operator * () const { return *ptr; }
    iterator& operator ++ () { ptr = splay_tree::next(ptr); return *this; }
    iterator& operator ++ (int) { ptr = splay_tree::next(ptr); return *this; }
    bool operator == (const iterator& o) const { return ptr == o.ptr; }
    bool operator != (const iterator& o) const { return ptr != o.ptr; }
  };
  iterator begin() const { return root ? walk_left(root) : root; }
  iterator end() const { return nullptr; }

  static void set_child(node_t* parent, node_t* child, bool left) {
    if (child != nullptr) {
      child->parent = parent;
    }
    if (parent != nullptr) {
      if (left) parent->left = child;
      else parent->right = child;
    }
  }
  static bool left_child(node_t* x) {
    return x != nullptr && x->left_child();
  }

  void pull(node_t* x) {
    x->size = get_size(x->left) + get_size(x->right) + 1;
  }

  template <typename T>
  node_t* lower_bound_path(const T& key) const {
    if (root == nullptr) return root;
    node_t* u = root;
    while (true) {
      if (key <= u->key) {
        if (u->left == nullptr) {
          return u;
        }
        u = u->left;
      } else {
        if (u->right == nullptr) {
          return u;
        }
        u = u->right;
      }
    }
  }

  template <typename T>
  node_t* upper_bound_path(const T& key) const {
    if (root == nullptr) return root;
    node_t* u = root;
    while (true) {
      if (key < u->key) {
        if (u->left == nullptr) {
          return u;
        }
        u = u->left;
      } else {
        if (u->right == nullptr) {
          return u;
        }
        u = u->right;
      }
    }
  }

  static node_t* walk_left(node_t* u) {
    assert(u != nullptr);
    while (u->left != nullptr) {
      u = u->left;
    }
    return u;
  }

  static node_t* walk_right(node_t* u) {
    assert(u != nullptr);
    while (u->right != nullptr) {
      u = u->right;
    }
    return u;
  }

  int get_size(node_t* x) { return x ? x->size : 0; }

private:
  node_t* splay_rec(node_t* x) {
    assert(x != nullptr); // not null
    if (x == nullptr || x->parent == nullptr) return x;
    rotate(left_child(x) == left_child(x->parent) ? x->parent : x);
    rotate(x);
    return splay_rec(x);
  }
  void rotate(node_t* x) {
    if (x->parent == nullptr) return;
    bool side = left_child(x);
    node_t* p = x->parent;
    set_child(p->parent, x, left_child(p));
    set_child(p, x->get_child(!side), side);
    set_child(x, p, !side);
    pull(x);
  }
};

// END #include "../../../lca/data_structure/splay_tree.h"
using node = splay_node_comparable<int>;

constexpr char nl = '\n';
using ll = long long;
int T = -1;

int main() {
  if(T < 0) { cin.tie(0)->sync_with_stdio(0); cin >> T; }
  if(--T) main();

  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  vector<int> small(n), big(n);
  splay_tree<node> hs, hb;
  for(int i=0, j=1; i<n; i++) {
    while(j <= a[i]) {
      hs.insert(new node(j));
      hb.insert(new node(j));
      j++;
    }

    if(i == 0 || a[i] != a[i-1]) {
      small[i] = big[i] = a[i];
      hs.erase(hs.find(a[i]));
      hb.erase(hb.find(a[i]));
    } else {
      small[i] = hs.begin()->key;
      hs.erase(hs.begin().ptr);
      big[i] = splay_tree<node>::walk_right(hb.root)->key;
      hb.erase(splay_tree<node>::walk_right(hb.root));
    }
  }

  for(int it : small) {
    cout << it << " ";
  }
  cout << nl;
  for(int it : big) {
    cout << it << " ";
  }
  cout << nl;

  return 0;
}