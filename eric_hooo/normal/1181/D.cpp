#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, int> pii;

int cnt[500010];
pii a[500010];
vector <int> all[500010];

struct Treap{
	struct Node{
		int x, fix, size;
		Node *left, *right;
		Node(){}
		Node(int _x, Node *l = NULL, Node *r = NULL){
			x = _x, left = l, right = r, fix = rand(), size = 1;
		}
		int lsize(){return left ? left->size : 0;}
		int rsize(){return right ? right->size : 0;}
		void pushup(){size = lsize() + rsize() + 1;}
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
	void Insert(int x){
		pnn t = split(T, x);
		T = merge(t.fi, merge(new Node(x), t.se));
	}
	int Find_kth(Node *T, int k){
		if (k <= T->lsize()) return Find_kth(T->left, k);
		if (k == T->lsize() + 1) return T->x;
		return Find_kth(T->right, k - T->lsize() - 1);
	}
	int Find_kth(int k){
		return Find_kth(T, k);
	}
	int size(){return T ? T->size : 0;}
}T;

int ans[500010];

int main(){
	srand((int)time(NULL));
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		cnt[x]++;
	}
	for (int i = 0; i < q; i++){
		scanf("%I64d", &a[i].fi);
		a[i].fi -= n;
		a[i].se = i;
	}
	sort(a, a + q);
	for (int i = 1; i <= m; i++){
		all[cnt[i]].push_back(i);
	}
	T.init();
	long long now = 0;
	int last = 0;
	for (int i = 0; i <= n; i++){
//		cout << "i:" << i << endl;
		for (int j = 0; j < all[i].size(); j++){
			int x = all[i][j];
			T.Insert(x);
		}
		int nxt = lower_bound(a + last, a + q, mp(now + T.size(), 0x3f3f3f3f)) - a;
		for (int j = last; j < nxt; j++){
//			cout << T.size() << " " << a[j].fi - now << endl;
			ans[a[j].se] = T.Find_kth(a[j].fi - now);
		}
		now += T.size(), last = nxt;
	}
	for (int i = last; i < q; i++){
		ans[a[i].se] = (a[i].fi - now - 1) % m + 1;
	}
	for (int i = 0; i < q; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}