#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int const INF = (int) 1e9 + 20;
int const LOG = 20;
int const N = (int) 1e5 + 20;

int rmq[N][LOG];
int lg[N];
int b[N];
int MIN;
int n, k;

int get_rmq(int l, int r) {
  auto k = lg[r - l];
  return min(rmq[l][k], rmq[r - (1 << k)][k]);
};

int get_rmq_big(int l, int r) {
  auto left_block = l / n;
  --r;
  auto right_block = r / n;
  if (left_block + 1 < right_block) {
    return MIN;
  }
  l %= n;
  r %= n;
  if (left_block == right_block) {
    return get_rmq(l, r + 1);
  }
  return min(get_rmq(l, n), get_rmq(0, r + 1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  MIN = INF;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    MIN = min(MIN, b[i]);
  }
  
  for (int i = 0; i < n; ++i) {
    rmq[i][0] = b[i];
  }
  for (int l = 1; l < LOG; ++l) {
    for (int i = 0; i + (1 << l) <= n; ++i) {
      rmq[i][l] = min(rmq[i][l - 1], rmq[i + (1 << (l - 1))][l - 1]);
    }
  }
  for (int i = 2; i <= n; ++i) {
    lg[i] = lg[i / 2] + 1;
  }
  struct node {
    int l;
    int r;
    int mn;
    node* left = nullptr;
    node* right = nullptr;
    int st = -1;

    node(int l, int r, int mn) : l(l), r(r), mn(mn) {}

    void init_children() {
      auto mid = (l + r) / 2;
      if (!left) {
        left = new node(l, mid, get_rmq_big(l, mid));
      }
      if (!right) {
        right = new node(mid, r, get_rmq_big(mid, r));
      }
    }

    void push() {
      if (st < 0) {
        return;
      }
      mn = st;
      if (l + 1 == r) {
        st = -1;
        return;
      }
      init_children();
      left->st = st;
      right->st = st;
      st = -1;
    }

    void pull() {
      mn = min(left->mn, right->mn);
    }
  };
  node* root = new node(0, k * n, MIN);

  function<void(node*, int, int, int)> _set =
    [&](node* v, int l, int r, int x) {
      auto tl = v->l;
      auto tr = v->r;
      v->push();
      if (tl >= r || l >= tr) {
        return;
      }
      if (l <= tl && tr <= r) {
        v->st = x;
        v->push();
        return;
      }
      v->init_children();
      _set(v->left, l, r, x);
      _set(v->right, l, r, x);
      v->pull();
    };
  function<int(node*, int, int)> _get =
    [&](node* v, int l, int r) {
      auto tl = v->l;
      auto tr = v->r;
      v->push();
      if (tl >= r || l >= tr) {
        return INF;
      }
      if (l <= tl && tr <= r) {
        return v->mn;
      }
      v->init_children();
      return min(_get(v->left, l, r),
                 _get(v->right, l, r));
    };
  auto tree_set = [&](int l, int r, int x) {
    _set(root, l, r, x);
  };
  auto tree_get = [&](int l, int r) {
    return _get(root, l, r);
  };
  int q;
  cin >> q;
  for (int qi = 0; qi < q; ++qi) {
    int t, l, r;
    cin >> t >> l >> r;
    --l;
    if (t == 1) {
      int x;
      cin >> x;
      tree_set(l, r, x);
    } else {
      cout << tree_get(l, r) << '\n';
    }
  }
  return 0;
}