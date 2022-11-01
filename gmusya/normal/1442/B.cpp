#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>

using namespace std;

mt19937 gen(time(0));

struct node {
  int x, y, sz;
  node *l, *r;
  node(int _x) {
    x = _x;
    y = gen();
    sz = 1;
    l = r = nullptr;
  }
  static int getsz(node* p) {
    if (!p)
      return 0;
    return p->sz;
  }
  static void updsz(node* p) {
    if (!p)
      return;
    p->sz = 1 + getsz(p->l) + getsz(p->r);
  }
  static node* merge(node* l, node* r) {
    if (!l)
      return r;
    if (!r)
      return l;
    if (l->y > r->y) {
      l->r = merge(l->r, r);
      updsz(l);
      return l;
    }
    r->l = merge(l, r->l);
    updsz(r);
    return r;
  }
  static void insert(int x, node* &p) {
    node* t = new node(x);
    p = merge(p, t);
  }
  static void erase(int x, node* &p) {
    if (!p)
      return;
    int tmp = getsz(p->l) + 1;
    if (tmp == x)
      p = merge(p->l, p->r);
    if (tmp > x)
      erase(x, p->l);
    if (tmp < x)
      erase(x - tmp, p->r);
    updsz(p);
  }
  static int get(int x, node* &p) {
    if (!p)
      return -1;
    int tmp = getsz(p->l) + 1;
    if (tmp == x)
      return p->x;
    if (tmp > x)
      return get(x, p->l);
    else
      return get(x - tmp, p->r);
  }
};

struct fenwick {
  int n;
  vector <int> t;
  fenwick(int _n) {
    n = _n;
    t.resize(n);
  }
  void add(int pos, int val) {
    for (int x = pos; x < n; x |= x + 1)
      t[x] += val;
  }
  int get(int pos) {
    int res = 0;
    for (int x = pos; x != -1; x = (x & (x + 1)) - 1)
      res += t[x];
    return res;
  }
};

const int MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m), p(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      p[a[i]] = i;
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      b[i]--;
    }
    node *T = 0;
    for (int i = 0; i < n; i++)
      node::insert(a[i], T);
    set <int> s;
    for (int i = 0; i < m; i++)
      s.insert(b[i]);
    s.insert(-1);
    fenwick fenw(n);
    for (int i = 0; i < n; i++)
      fenw.add(i, 1);
    int ans = 1;
    for (int i = 0; i < m; i++) {
      vector <int> x;
      int pos = fenw.get(p[b[i]]);
      int val1 = node::get(pos - 1, T);
      if (s.find(val1) == s.end())
        x.push_back(pos - 1);
      int val2 = node::get(pos + 1, T);
      if (s.find(val2) == s.end())
        x.push_back(pos + 1);
      s.erase(b[i]);
      if (x.empty()) {
        ans = 0;
        break;
      }
      fenw.add(p[b[i]], -1);
      if (x.size() == 2) {
        ans *= 2;
        if (ans > MOD)
          ans -= MOD;
      }
      node::erase(x[0], T);
    }
    cout << ans << '\n';
  }
  return 0;
}