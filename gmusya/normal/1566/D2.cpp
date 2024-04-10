#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <algorithm>

using namespace std;

mt19937 rnd(time(0));

struct node {
    int x, y;
    int sz;
    node *l, *r;
    node(int _x) {
      x = _x;
      sz = 1;
      y = rnd();
      l = r = nullptr;
    }
    static int get_sz(node* p) {
      if (!p)
        return 0;
      return p->sz;
    }
    static void upd(node* p) {
      if (!p)
        return;
      p->sz = 1 + get_sz(p->l) + get_sz(p->r);
    }
    static void heapify(node* p) {
      if (!p)
        return;
      node* mx = p;
      if (p->l && p->l->y > mx->y)
        mx = p->l;
      if (p->r && p->r->y > mx->y)
        mx = p->r;
      if (mx != p) {
        swap(mx->y, p->y);
        heapify(mx);
      }
    }
    static node* build(int l, int r, vector <int> &a) {
      if (l > r)
        return {};
      int m = (l + r) / 2;
      node* p = new node(a[m]);
      p->l = build(l, m - 1, a);
      p->r = build(m + 1, r, a);
      heapify(p);
      upd(p);
      return p;
    }
    static node* merge(node* l, node* r) {
      if (!l)
        return r;
      if (!r)
        return l;
      if (l->y > r->y) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
      } else {
        r->l = merge(l, r->l);
        upd(r);
        return r;
      }
    }
    static pair <node*, node*> split(int x, node* p) { // (-inf; x)
      if (!p)
        return {};
      if (x <= p->x) {
        pair <node*, node*> tmp = split(x, p->l);
        p->l = tmp.second;
        upd(p);
        return {tmp.first, p};
      } else {
        pair <node*, node*> tmp = split(x, p->r);
        p->r = tmp.first;
        upd(p);
        return {p, tmp.second};
      }
    }
    static void int_insert(int x, node* &p) {
      node* n = new node(x);
      pair <node*, node*> tmp = split(x, p);
      p = merge(tmp.first, merge(n, tmp.second));
    }
    static void node_insert(node* n, node* &p) {
      if (!p) {
        p = n;
      } else if (n->y > p->y) {
        pair <node*, node*> tmp = split(n->x, p);
        n->l = tmp.first, n->r = tmp.second;
        p = n;
      } else {
        node_insert(n, n->x < p->x ? p->l : p->r);
      }
      upd(p);
    }
    static void erase_many(int x, node* &p) {
      pair <node*, node*> tmp1 = split(x, p);
      pair <node*, node*> tmp2 = split(x + 1, p);
      p = merge(tmp1.first, tmp2.second);
    }
    static void erase_one(int x, node* &p) {
      if (!p)
        return;
      if (x == p->x)
        p = merge(p->l, p->r);
      else
        erase_one(x, x < p->x ? p->l : p->r);
      upd(p);
    }
    static void write(node* p) {
      if (!p)
        return;
      write(p->l);
      cout << p->x << ' ';
      write(p->r);
    }
    static int kth_element(int k, node* p) {
      if (!p)
        return -1;
      if (get_sz(p->l) + 1 == k)
        return p->x;
      if (get_sz(p->l) + 1 < k)
        return kth_element(k - get_sz(p->l) - 1, p->r);
      else
        return kth_element(k, p->l);
    }
    static int lower_than(int x, node* p) {
      if (!p)
        return 0;
      if (x <= p->x)
        return lower_than(x, p->l);
      else
        return get_sz(p->l) + 1 + lower_than(x, p->r);
    }
};

struct treap {
    node *T = 0;
    void build(vector <int> &a) {
      T = node::build(0, (int)a.size() - 1, a);
    }
    void insert(int x) {
      node* n = new node(x);
      node::node_insert(n, T);
    }
    void erase(int x) {
      node::erase_one(x, T);
    }
    int kth_element(int x) {
      return node::kth_element(x, T);
    }
    int lower_than(int x) {
      return node::lower_than(x, T);
    }
    void write() {
      node::write(T);
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n * m);
    vector<int> b(n * m);
    for (int i = 0; i < n * m; ++i) {
      cin >> a[i].first;
      b[i] = a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n * m; ++i) {
      a[i].first = i;
    }
    sort(a.begin(), a.end(), [&](pair<int, int> &a, pair<int, int> &b) {
      return a.second < b.second;
    });
    vector<treap> tr(n);
    int ans = 0;
    for (int i = 0; i < n * m; ++i) {
      int pos = a[i].first / m;
      int val = b[i];
      ans += tr[pos].lower_than(val);
      tr[pos].insert(val);
    }
    cout << ans << '\n';
  }
  return 0;
}