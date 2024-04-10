#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int Rand() {
  return rand() * RAND_MAX + rand();
}

typedef struct item * pitem;

struct item {
  item(long long _value) : value(_value), mn(_value), add(0), cnt(1), prior(Rand()), l(NULL), r(NULL), par(NULL) {};
  long long value, mn, add;
  int prior, cnt;
  pitem l, r, par;
};

int cnt(pitem it) {
  return it ? it->cnt : 0;
}

void upd_cnt(pitem it) {
  if (it) {
    it->cnt = cnt(it->l) + cnt(it->r) + 1;
    if (it->l) it->l->par = it;
    if (it->r) it->r->par = it;
    it->par = NULL;
  }
}

long long mn(pitem it) {
  return it ? it->mn + it->add : 1e+18;
}

void upd_mn(pitem it) {
  if (it) {
    it->mn = min(min(mn(it->l), mn(it->r)), it->value);
  }
}

void push (pitem it) {
  if (it && it->add) {
    it->value += it->add;
    it->mn += it->add;
    if (it->l) it->l->add += it->add;
    if (it->r) it->r->add += it->add;
    it->add = 0;
  }
}

void merge (pitem & t, pitem l, pitem r) {
  push (l);
  push (r);
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge (l->r, l->r, r), t = l;
  else
    merge (r->l, l, r->l), t = r;
  upd_cnt (t);
  upd_mn(t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
  if (!t) {
    l = r = NULL;
    return;
  }
  push (t);
  int cur_key = add + cnt(t->l);
  if (key <= cur_key)
    split (t->l, l, t->l, key, add), r = t;
  else
    split (t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
  upd_cnt (t);
  upd_mn(t);
}

void output (pitem t) {
  if (!t) return;
  push (t);
  output (t->l);
  printf ("(%lld %lld) ", t->value, t->mn);
  output (t->r);
}

pitem root[2];

int arr[200002];

vector<long long> all_numbers;

bool stupid(int l, int r) {
  vector<long long> v;
  for (int i = l; i <= r; ++i) {
    v.push_back(all_numbers[i]);
  }
  int pos = 0; v[pos]--;
  while (true) {
    if (pos > 0 && v[pos - 1] > 0) --pos, v[pos]--;
    else if (pos + 1 < v.size() && v[pos + 1] > 0) ++pos, v[pos]--;
    else break;
  }
  for (int i = 0; i < v.size(); ++i)
    if (v[i] != 0) return false;
  return pos == v.size() - 1;
}

int fixLess(int a, int b) {
  if ((a - b) % 2 != 0) --a;
  return a;
}

void fix(pitem a) {
  if (a->par) fix(a->par);
  push(a);
}

pitem who[200002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // srand(time(NULL));
  int n = 10;
  cin >> n;
  // cout << n << endl;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    // arr[i] = rand() % 5;
    // cout << arr[i] << " ";
    // all_numbers.push_back(arr[i]);
    --arr[i];
  }
  // cout << endl;
  long long s = 0;
  for (int i = 0; i < n; ++i) {
    s = arr[i] - s;
    // cout << s << endl;
    item *it = new item(s); who[i] = it;
    merge(root[i & 1], root[i & 1], it);
  }

  int q = 1000;
  cin >> q;
  while (q--) {
    // int t = rand() & 2, a = rand() % n, b = rand() % n, k = rand() % 2;
    // if (a > b) swap(a, b);
    int t, a, b, k;
    cin >> t >> a >> b;
    // cout << (2 - t) << "  " << a << " " << b;
    if (t == 1) {
      cin >> k;
      // cout << k << endl;
      // for (int i = a; i <= b; ++i)
      //   all_numbers[i] += k;
      {
        pitem A = NULL, B = NULL, C = NULL;
        split(root[a & 1], A, C, fixLess(b, a) / 2 + 1);
        split(A, A, B, a / 2);
        B->add += k;
        merge(A, A, B);
        merge(root[a & 1], A, C);
      }
      if ((b - a) % 2 == 0) {
        {
          pitem A = NULL, B = NULL, C = NULL;
          split(root[(b + 1) & 1], A, C, (b + 1) / 2);
          if (C) C->add -= k;
          merge(root[(b + 1) & 1], A, C);
        }
        {
          pitem A = NULL, B = NULL, C = NULL;
          split(root[(b + 2) & 1], A, C, (b + 2) / 2);
          if (C) C->add += k;
          merge(root[(b + 2) & 1], A, C);
        }
      }
    } else {
      // cout << endl;
      long long val = 0;
      if (a > 0) {
        // int ind = a - 1;
        // pitem A = NULL, B = NULL, C = NULL;
        // split(root[ind & 1], A, C, ind / 2);
        // split(C, B, C, 1);
        // val = B->value;
        // merge(root[ind & 1], A, B);
        // merge(root[ind & 1], root[ind & 1], C);
        // cout << val << endl;
        fix(who[a - 1]);
        val = who[a - 1]->value;
      }

      bool ok = true;
      {
        pitem A = NULL, B = NULL, C = NULL;
        split(root[a & 1], A, C, fixLess(b, a) / 2 + 1);
        split(A, A, B, a / 2);
        // output(B);
        if (B && B->mn + val < 0) ok = false;
        merge(A, A, B);
        merge(root[a & 1], A, C);
      }
      if (ok && a + 1 <= b){
        pitem A = NULL, B = NULL, C = NULL;
        split(root[(a + 1) & 1], A, C, fixLess(b, a + 1) / 2 + 1);
        split(A, A, B, (a + 1) / 2);
        // output(B);
        if (B && B->mn - val < 0) ok = false;
        merge(A, A, B);
        merge(root[(a + 1) & 1], A, C);
      }
      if (ok) {
        // pitem A = NULL, B = NULL, C = NULL;
        // split(root[b & 1], A, C, b / 2);
        // split(C, B, C, 1);
        fix(who[b]);
        if (who[b]->value + (b % 2 == a % 2 ? val : -val) != 0) ok = false;
        // merge(root[b & 1], A, B);
        // merge(root[b & 1], root[b & 1], C);
        // cout << val << endl;
      }
      cout << ok << endl;
      // cout << ok << " " << stupid(a, b) << endl;
      // if (ok != stupid(a, b)) break;
    }
  }

  return 0;
}