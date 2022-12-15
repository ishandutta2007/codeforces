#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef struct item * pitem;
struct item {
	int prior, idx, ans;
  pair<int, int> key;
  int lazyAns, lazyKey;
	pitem l, r;
};

const int ms = 2e5+5;

pair<int, int> shirt[ms];
int ans[ms];

void push (pitem it) {
	if (it && (it->lazyAns || it->lazyKey)) {
		it->ans += it->lazyAns;
    it->key.first += it->lazyKey;
		if (it->l)  {
      it->l->lazyAns += it->lazyAns;
      it->l->lazyKey += it->lazyKey;
    }
		if (it->r)  {
      it->r->lazyAns += it->lazyAns;
      it->r->lazyKey += it->lazyKey;
    }
    it->lazyAns = 0;
    it->lazyKey = 0;
	}
}

void merge (pitem & t, pitem l, pitem r) {
	push (l), push (r);
	if (!l || !r) t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
}

void split (pitem t, pitem & l, pitem & r, pair<int, int> key) {
	if (!t) return void( l = r = 0 );
	push (t);
	if (key <= t->key)
		split (t->l, l, t->l, key),  r = t;
	else
		split (t->r, t->r, r, key),  l = t;
}

void unite (pitem &t, pitem l, pitem r) {
	push(l), push(r);
	if (!l || !r) return void( t = l ? l : r );
	if (l->prior < r->prior)  swap (l, r);
	pitem lt, rt;
	split (r, lt, rt, l->key);
	unite (l->l, l->l, lt);
	unite (l->r, l->r, rt);
  t = l;
}

void getAns(pitem t) {
  if(!t) return;
  push(t);
  ans[t->idx] = t->ans;
  getAns(t->l); getAns(t->r);
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int c, q;
    cin >> c >> q;
    shirt[i] = {-q, c};
  }
  sort(shirt, shirt+n);
  int k;
  cin >> k;
  pitem t = 0;
  for(int i = 0; i < k; i++) {
    int b;
    cin >> b;
    pitem k = new item();
    k->idx = i;
    k->key = {b, i};
    k->prior = rng();
    pitem t1, t2;
    split(t, t1, t2, k->key);
    merge(t1, t1, k);
    merge(t, t1, t2);
  }
  for(int i = 0; i < n; i++) {
    pitem t1, t2, t3;
    split(t, t1, t2, {shirt[i].second, 0});
    if(t2) {
      t2->lazyAns += 1;
      t2->lazyKey -= shirt[i].second;
    }
    unite(t, t1, t2);
  }
  getAns(t);
  for(int i = 0; i < k; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}