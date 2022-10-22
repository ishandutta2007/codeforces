#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pii;

const int INF = 0x3f3f3f3f;

int n, m;
int a[100010];
int last[100010];

struct Treap{
	struct Node{
		int x, fix, val;
		long long size, sum;
		Node *left, *right;
		Node(){}
		Node(int _x, int v, Node *l = NULL, Node *r = NULL){
			x = _x, val = v, left = l, right = r, size = 1, sum = val, fix = rand();
		}
		long long lsize(){return left ? left->size : 0;}
		long long rsize(){return right ? right->size : 0;}
		long long lsum(){return left ? left->sum : 0;}
		long long rsum(){return right ? right->sum : 0;}
		void pushup(){size = lsize() + rsize() + 1, sum = lsum() + rsum() + val;}
	}*T;
	typedef pair <Node *, Node *> pnn;
	void init(){T = NULL;}
	Node *merge(Node *l, Node *r){
		if (!l || !r) return l ? l : r;
		if (l->fix > r->fix){
			l->right = merge(l->right, r);
			l->pushup();
			return l;
		} else {
			r->left = merge(l, r->left);
			r->pushup();
			return r;
		}
	}
	pnn split(Node *T, int val){
		if (!T) return pnn(NULL, NULL);
		if (val < T->x){
			pnn t = split(T->left, val);
			T->left = t.se, T->pushup();
			return mp(t.fi, T);
		} else {
			pnn t = split(T->right, val);
			T->right = t.fi, T->pushup();
			return mp(T, t.se);
		}
	}
	void Insert(int x, int val){
		pnn t = split(T, x - 1);
		Node *tmp = new Node(x, val);
		tmp = merge(tmp, t.se);
		tmp = merge(t.fi, tmp);
		T = tmp;
	}
	void Erase(int x){
		pnn t1 = split(T, x - 1), t2 = split(t1.se, x);
		delete t2.fi;
		T = merge(t1.fi, t2.se);
	}
	long long get_val(int l, int r){
		pnn t1 = split(T, l - 1), t2 = split(t1.se, r);
		long long res = 0;
		if (t2.fi) res = t2.fi->sum;
		T = merge(t1.fi, merge(t2.fi, t2.se));
		return res;
	}
	int get_pre(Node *T, int x){
		if (!T) return -INF;
		if (T->x >= x) return get_pre(T->left, x);
		return max(get_pre(T->right, x), T->x);
	}
	int get_suc(Node *T, int x){
		if (!T) return INF;
		if (T->x <= x) return get_suc(T->right, x);
		return min(get_suc(T->left, x), T->x);
	}
	int get_pre(int x){
		int res = get_pre(T, x);
		return res == -INF ? -1 : res;
	}
	int get_suc(int x){
		int res = get_suc(T, x);
		return res == INF ? -1 : res;
	}
};

Treap all[100010];

struct Segment_tree{
	struct Node{
		Treap s;
	}T[400010];
	int val[100010];
	void init(){
		memset(val, -1, sizeof(val));
		for (int i = 0; i < 400000; i++){
			T[i].s.init();
		}
	}
	void Update(int now, int l, int r, int pos, int x){
		if (~val[pos]) T[now].s.Erase(val[pos]);
		if (~x) T[now].s.Insert(x, x - pos);
		if (l == r){
			val[pos] = x;
			return ;
		}
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos, x);
		else Update(now << 1 | 1, mid + 1, r, pos, x);
	}
	long long Query(int now, int l, int r, int L, int R, int x, int y){
		if (l == L && r == R) return T[now].s.get_val(x, y); 
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R, x, y);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R, x, y);
		return Query(now << 1, l, mid, L, mid, x, y) + Query(now << 1 | 1, mid + 1, r, mid + 1, R, x, y);
	}
}seg;

void work1(int pos, int x){
	int left = all[a[pos]].get_pre(pos), right = all[a[pos]].get_suc(pos);
	if (~left) seg.Update(1, 1, n, left, -1);
	if (~right) seg.Update(1, 1, n, pos, -1);
	if (~left && ~right) seg.Update(1, 1, n, left, right);
	all[a[pos]].Erase(pos), a[pos] = x, all[a[pos]].Insert(pos, 0);
	left = all[a[pos]].get_pre(pos), right = all[a[pos]].get_suc(pos);
	if (~left && ~right) seg.Update(1, 1, n, left, -1);
	if (~left) seg.Update(1, 1, n, left, pos);
	if (~right) seg.Update(1, 1, n, pos, right);
}

long long work2(int l, int r){
	return seg.Query(1, 1, n, l, r, l, r);
}

int main(){
	scanf("%d%d", &n, &m);
	seg.init();
	for (int i = 0; i <= 100000; i++){
		all[i].init();
	}
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if (last[a[i]]) seg.Update(1, 1, n, last[a[i]], i);
		last[a[i]] = i;
		all[a[i]].Insert(i, 0);
	}
	for (int i = 0; i < m; i++){
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) work1(x, y);
		else printf("%I64d\n", work2(x, y));
	}
	return 0;
}