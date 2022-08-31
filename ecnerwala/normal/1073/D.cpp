#include<bits/stdc++.h>
using namespace std;

using ll = long long;
struct node {
  node* ch[2];
  int sz;
  int pri;
  int val;
  ll sum;
  void update() {
    assert(val > 0);
    sz = 1 + (ch[0] ? ch[0]->sz : 0) + (ch[1] ? ch[1]->sz : 0);
    sum = ll(val) + (ch[0] ? ch[0]->sum : 0) + (ch[1] ? ch[1]->sum : 0);
  }
};
void merge(node* &r, node* a, node* b) {
  if (!a) r = b;
  else if (!b) r = a;
  else if (a->pri < b->pri) {
    r = a;
    merge(a->ch[1], a->ch[1], b);
    r->update();
  } else {
    r = b;
    merge(b->ch[0], a, b->ch[0]);
    r->update();
  }
}
void split(node* r, node* &a, node* &b, ll k) {
  assert(r);
  assert(0 <= k && k < r->sum);
  if (k < (r->ch[0] ? r->ch[0]->sum : 0)) {
    b = r;
    split(r->ch[0], a, b->ch[0], k);
    r->update();
    return;
  }
  k -= (r->ch[0] ? r->ch[0]->sum : 0);
  if (k < r->val) {
    a = r->ch[0], b = r->ch[1];
    return;
  }
  k -= r->val;
  a = r;
  split(r->ch[1], a->ch[1], b, k);
  r->update();
}

const int MAXN = 3e5;
int N;
ll T;
node pool[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N >> T;
  mt19937 mt{10295};
  for (int i = 0; i < N; i++) {
    cin >> pool[i].val;
    pool[i].pri = mt();
    pool[i].update();
  }
  node* root = nullptr;
  for (int i = 0; i < N; i++) merge(root, root, &pool[i]);

  ll res = 0;  
  while (root) {
    res += (T / root->sum) * root->sz;
    T %= root->sum;
    node* a;
    node* b;
    split(root, a, b, T);
    if (a) res += a->sz, T -= a->sum;
    merge(root, b, a);
  }
  cout << res << '\n';
}