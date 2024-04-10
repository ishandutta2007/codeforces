#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const ll INF = 1LL << 60;

struct Node {
  int l, r;
  ll x, add, set;
  Node *ls, *rs;

  ll get() const { return add + (set ? set : x); }

  void upd() {
    x = min(ls->get(), rs->get());
  }

  void pd() {
    if (set) {
      x = set;
      ls->add = rs->add = 0;
      ls->set = rs->set = set;
      set = 0;
    }
    if (add) {
      x += add;
      ls->add += add;
      rs->add += add;
      add = 0;
    }
  }

  void fix() {
    if (get() >= 0) return;
    if (l == r) {
      add = set = 0;
      x = INF;
      return;
    }
    if (set) {
      add = 0;
      set = INF;
      return;
    }
    pd();
    ls->fix();
    rs->fix();
    upd();
  }

  void dec(int l, int r, int x) {
    if (this->l == l && this->r == r) {
      add -= x;
      return fix();
    }
    pd();
    if (r <= ls->r) ls->dec(l, r, x);
    else if (l >= rs->l) rs->dec(l, r, x);
    else {
      ls->dec(l, ls->r, x);
      rs->dec(rs->l, r, x);
    }
    upd();
  }

  void fill(int l, int r, ll x) {
    if (this->l == l && this->r == r) {
      add = 0;
      set = x;
      return;
    }
    pd();
    if (r <= ls->r) ls->fill(l, r, x);
    else if (l >= rs->l) rs->fill(l, r, x);
    else {
      ls->fill(l, ls->r, x);
      rs->fill(rs->l, r, x);
    }
    upd();
  }

  ll qry(int k) const {
    if (l == r || set) return get();
    return add + (k <= ls->r ? ls : rs)->qry(k);
  }
};

const int N = 100010, K = 10;

int a[N];
ll powers[K];
Node* segTree[K];

Node* build(int l, int r, ll x) {
  static Node pool[N * K * 2], *top = pool;
  Node* p = top++;
  p->l = l;
  p->r = r;
  if (l == r) {
    p->x = (a[l] < x) ? (x - a[l]) : INF;
    return p;
  }
  int mid = (l + r) >> 1;
  p->ls = build(l, mid, x);
  p->rs = build(mid + 1, r, x);
  p->upd();
  return p;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  powers[0] = 1;
  for (int i = 1; i < K; ++i) powers[i] = powers[i - 1] * 42;
  for (int i = 0; i < K; ++i)
    segTree[i] = build(1, n, powers[i]);
  while (q--) {
    int t, a, b, x;
    cin >> t >> a;
    if (t == 1)
      printf("%lld\n", powers[K - 1] - segTree[K - 1]->qry(a));
    else {
      cin >> b >> x;
      if (t == 2) {
        for (int i = 0; i < K; ++i)
          segTree[i]->fill(a, b, x < powers[i] ? (powers[i] - x) : INF);
      } else {
        bool f = true;
        while (f) {
          f = false;
          for (int i = 0; i < K; ++i) {
            segTree[i]->dec(a, b, x);
            if (segTree[i]->get() == 0)
              f = true;
          }
        }
      }
    }
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}