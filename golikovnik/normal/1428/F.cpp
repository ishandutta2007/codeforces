//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

#ifdef GOLIKOV
mt19937_64 rng(566);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

template <typename T>
T rnd_helper(T from, T to, true_type) {
  return uniform_int_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd_helper(T from, T to, false_type) {
  return uniform_real_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd(T from, T to) {
  return rnd_helper(from, to, is_integral<T>{});
}

struct treap {
  treap* l = nullptr;
  treap* r = nullptr;
  int val;
  int cnt_val;
  i64 subtree_sum;
  int subtree_cnt;
  i64 y;

  treap(int val, int cnt) : val(val), cnt_val(cnt), subtree_sum((i64) val *
  cnt),
  subtree_cnt(cnt), y
  (rnd<i64>(0,
                                                   numeric_limits<i64>::max())) {}
};

i64 subtree_sum(treap* t) {
  return t ? t->subtree_sum : 0;
}

int subtree_cnt(treap* t) {
  return t ? t->subtree_cnt : 0;
}

void update(treap* t) {
  t->subtree_cnt = t->cnt_val + subtree_cnt(t->l) + subtree_cnt(t->r);
  t->subtree_sum = (i64) t->val * t->cnt_val + subtree_sum(t->l) +
      subtree_sum(t->r);
}

treap* merge(treap* l, treap* r) {
  if (!l) {
    return r;
  }
  if (!r) {
    return l;
  }
  if (l->y > r->y) {
    l->r = merge(l->r, r);
    update(l);
    return l;
  } else {
    r->l = merge(l, r->l);
    update(r);
    return r;
  }
}

tuple<treap*, treap*, int> split(treap* t, int key) {
  if (!t) {
    return {nullptr, nullptr, 0};
  }
  if (t->val == key) {
    return make_tuple(t->l, t->r, t->cnt_val);
  }
  if (t->val > key) {
    auto[l, r, x] = split(t->l, key);
    t->l = r;
    update(t);
    return make_tuple(l, t, x);
  }
  auto[l, r, x] = split(t->r, key);
  t->r = l;
  update(t);
  return make_tuple(t, r, x);
}

treap* insert(treap* t, int val, int cnt_val) {
  auto[l, r, x] = split(t, val);
  return merge(l, merge(new treap(val, x + cnt_val), r));
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string s;
  cin >> s;
  treap* t = nullptr;

  int tail = 0;
  i64 ans = 0;
  for (char ch : s) {
    if (ch == '1') {
      tail++;
      ans += (i64) tail * (tail + 1) / 2;
      auto[l, r, x] = split(t, tail);
      ans += (i64) (subtree_cnt(l) + x) * tail;
      ans += subtree_sum(r);
      t = merge(l, merge(new treap(tail, x), r));
    } else {
      auto[l, r, x] = split(t, tail);
      treap* tt = merge(new treap(tail, subtree_cnt(l) + x), r);
      for (int i = 0; i <= tail; ++i) {
        tt = insert(tt, i, 1);
      }
      ans += subtree_sum(tt);
      tail = 0;
      t = tt;
    }
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}