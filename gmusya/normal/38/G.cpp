#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>

using namespace std;

mt19937 gen(time(0));

const int INF = 1e9;

vector <int> per;

struct node {
  int x, y;
  node *l, *r;
  int sz, max;
  node(int _x) {
    x = _x;
    y = gen();
    l = r = nullptr;
    sz = 1, max = x;
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
  static int getmax(node* p) {
    if (!p)
      return -1;
    return p->max;
  }
  static void updmax(node* p) {
    if (!p)
      return;
    if (p->max < getmax(p->l))
      p->max = p->l->max;
    if (p->max < getmax(p->r))
      p->max = p->r->max;
  }
  static pair <node*, node*> split(int x, node* p) {
    if (!p)
      return {nullptr, nullptr};
    if (x <= 0)
      return {nullptr, p};
    if (getsz(p->l) + 1 <= x) {
      pair <node*, node*> tmp = split(x - getsz(p->l) - 1, p->r);
      p->r = tmp.first;
      updsz(p);
      updmax(p);
      return {p, tmp.second};
    }
    pair <node*, node*> tmp = split(x, p->l);
    p->l = tmp.second;
    updsz(p);
    updmax(p);
    return {tmp.first, p};
  }
  static node* merge(node* l, node* r) {
    if (!l)
      return r;
    if (!r)
      return l;
    if (l->y > r->y) {
      l->r = merge(l->r, r);
      updsz(l);
      updmax(l);
      return l;
    }
    r->l = merge(l, r->l);
    updsz(r);
    updmax(r);
    return r;
  }
  static void insert(int pos, int val, node* &p) {
    pair <node*, node*> tmp = split(pos, p);
    node* t = new node(val);
    p = merge(tmp.first, merge(t, tmp.second));
  }
  static int firstlower(int h, node* p) {
    if (!p)
      return -1;
    if (p->max < h)
      return -1;
    int ans = firstlower(h, p->r);
    if (ans != -1)
      return ans + getsz(p->l) + 1;
    if (p->x > h)
      return getsz(p->l) + 1;
    return firstlower(h, p->l);
  }
  static void write(node* p) {
    if (!p)
      return;
    write(p->l);
    cout << per[p->x] << ' ';
    write(p->r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  node* T = nullptr;
  int n;
  cin >> n;
  per.resize(n + 1);
  for (int i = 0; i < n; i++) {
    int a, c;
    cin >> a >> c;
    per[a] = i + 1;
    int pos = node::firstlower(a, T);
    pos = max(pos, i - c);
    node::insert(pos, a, T);
  }
  node::write(T);
  return 0;
}