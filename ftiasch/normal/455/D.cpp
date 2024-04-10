// #define DEBUG

#ifdef DEBUG
#include <cassert>
#endif

#include <random>
#include <tuple>
#include <vector>

template <typename T> struct NodeT {
  using Data = typename T::Data;

  NodeT *parent, *children[2];
  int rank, size;
  Data data;

  NodeT() : rank(0), size(0) {}

  NodeT(const Data &data)
      : parent(null()), rank(random()), size(1), data(data) {
    children[0] = children[1] = null();
  }

  int type() const {
    return parent == null() ? 2 : parent->children[1] == this;
  }

  NodeT *update() {
    size = children[0]->size + 1 + children[1]->size;
    return this;
  }

  NodeT *child(int t, NodeT *other) {
    children[t] = other;
    if (other != null()) {
      other->parent = this;
    }
    return this;
  }

  NodeT *unchild(int t) {
    NodeT *child = children[t];
    children[t] = null();
    if (child != null()) {
      child->parent = null();
    }
    return child;
  }

  // find a node with rank == target
  NodeT *find(int target) {
    typename T::Ranked p(this);
    while (true) {
      int r = p.get_rank();
      if (r == target) {
        return p.get();
      }
      p.go(r < target);
    }
  }

  int count() const {
    int result = children[0]->size;
    for (const NodeT *p = this, *pp; (pp = p->parent) != null(); p = pp) {
      if (p->type() == 1) {
        result += pp->children[0]->size + 1;
      }
    }
    return result;
  }

  NodeT *split_at() {
    NodeT *r = zip(unchild(0), unchild(1));
    NodeT *p = this;
    while (p->parent != null()) {
      int t = p->type() ^ 1;
      p = p->parent;
      r = p->child(t ^ 1, r)->update();
    }
    parent = null(), size = 1;
    return r;
  }

  // split the tree into two trees:
  // one has rank < target
  // other has rank >= target
  NodeT *split_and_zip(int target, NodeT *x) {
    NodeT *l, *r;
    std::tie(l, r) = recur(typename T::Ranked(this), target);
#ifdef DEBUG
    l->print();
    puts(" LEFT");
    r->print();
    puts(" RIGHT");
#endif
    return zip(l, zip(x, r));
  }

  static std::pair<NodeT *, NodeT *> recur(typename T::Ranked p, int target) {
    NodeT *x = p.get();
    if (x == null()) {
      return {null(), null()};
    }
    int t = p.get_rank() < target;
    p.go(t);
    NodeT *part[2];
    std::tie(part[0], part[1]) = recur(p, target);
    part[t ^ 1] = x->child(t, part[t ^ 1])->update();
    return {part[0], part[1]};
  }

  static NodeT *null() {
    static NodeT n;
    return &n;
  }

  static int random() {
    static std::mt19937 gen;
    // int result = 1;
    // while (gen() & 1) {
    //   result++;
    // }
    return gen() | 1;
  }

#ifdef DEBUG
  void print() {
    if (this != null()) {
      assert(size == children[0]->size + 1 + children[1]->size);
      for (int t = 0; t < 2; ++t) {
        NodeT *p = children[t];
        assert(p == null() || p->parent == this);
      }
      putchar('(');
      children[0]->print();
      printf("%d", data.first);
      children[1]->print();
      putchar(')');
    }
  }
#endif
};

template <typename T> static NodeT<T> *zip(NodeT<T> *a, NodeT<T> *b) {
  if (a == NodeT<T>::null()) {
    return b;
  }
  if (b == NodeT<T>::null()) {
    return a;
  }
  if (a->rank > b->rank) {
    return a->child(1, zip(a->children[1], b))->update();
  } else {
    return b->child(0, zip(a, b->children[0]))->update();
  }
}

template <typename T> struct RankedBaseT {
  RankedBaseT(NodeT<T> *node) : node(node) {}

  void go(int t) { node = node->children[t]; }

  NodeT<T> *get() { return node; }

protected:
  NodeT<T> *node;
};

struct Val;

using ValNode = NodeT<Val>;

struct Seq {
  using Data = std::pair<int, ValNode *>;

  struct Ranked : public RankedBaseT<Seq> {
    Ranked(NodeT<Seq> *node) : RankedBaseT<Seq>(node), rank(0) {}

    void go(int t) {
      if (t == 1) {
        rank += node->children[0]->size + 1;
      }
      node = node->children[t];
    }

    int get_rank() const { return rank + node->children[0]->size; }

  private:
    int rank;
  };
};

using SeqNode = NodeT<Seq>;

struct Val {
  using Data = SeqNode *;

  struct Ranked : public RankedBaseT<Val> {
    Ranked(NodeT<Val> *node) : RankedBaseT<Val>(node) {}

    int get_rank() const { return node->data->count(); }
  };
};

int count(ValNode *p, int target) {
  if (p == ValNode::null()) {
    return 0;
  }
  int r = p->data->count();
  if (r < target) {
    return p->children[0]->size + 1 + count(p->children[1], target);
  }
  return count(p->children[0], target);
}

int main() {
  int n, q;
  while (scanf("%d", &n) == 1) {
    SeqNode *seq = SeqNode::null();
    std::vector<ValNode *> vals(n + 1, ValNode::null());
    for (int i = 0, a; i < n; ++i) {
      scanf("%d", &a);
      ValNode *vn = new ValNode(nullptr);
      SeqNode *sn = new SeqNode({a, vn});
      vn->data = sn;
      seq = zip(seq, sn);
      vals[a] = zip(vals[a], vn);
    }
#ifdef DEBUG
    seq->print();
    puts("");
#endif
    scanf("%d", &q);
    int last_ans = 0;
    while (q--) {
      int op, l, r, a;
      scanf("%d%d%d", &op, &l, &r);
      l = (l - 1 + last_ans) % n;
      r = (r - 1 + last_ans) % n;
      if (l > r) {
        std::swap(l, r);
      }
      if (op == 1) {
#ifdef DEBUG
        printf("%d %d %d\n", op, l, r);
#endif
        SeqNode *sn = seq->find(r);
        seq = sn->split_at();
#ifdef DEBUG
        assert(seq->size == n - 1);
#endif
        ValNode *vn;
        std::tie(a, vn) = sn->data;
        vals[a] = vn->split_at();
        vals[a] = vals[a]->split_and_zip(l, vn);
#ifdef DEBUG
        seq->print();
        puts("");
#endif
        seq = seq->split_and_zip(l, sn);
#ifdef DEBUG
        seq->print();
        return 0;
#endif
      } else {
        scanf("%d", &a);
        a = (a - 1 + last_ans) % n + 1;
#ifdef DEBUG
        printf("%d %d %d %d\n", op, l, r, a);
#endif
        last_ans = count(vals[a], r + 1) - count(vals[a], l);
        printf("%d\n", last_ans);
      }
    }
  }
}