#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

void pass(){
	return;
}

#define int long long
#define rand() (rand()<<15+rand())
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 2e5 + 7;

int a[MAXN];
int ans[MAXN];

struct Node{	
	int x, y, cnt;
	bool rev;
	Node *l, *r;
};

Node *init(int x, int y){
	Node *res = new Node();
	res->x = x;
	res->y = y;
	res->cnt = 1;
	res->rev = false;
	res->l = NULL;
	res->r = NULL;

	return res;
}

int cnt(Node *t){
	if (!t) return 0;
	return t->cnt;
}

Node *relax(Node *t){
	if (!t) return NULL;
	t->cnt = cnt(t->l) + cnt(t->r) + 1;
	return t;
}

Node *push(Node *t){
	if (!t) return NULL;

	if (t->rev){
		if (t->l) t->l->rev ^= true;
		if (t->r) t->r->rev ^= true;
		swap(t->l, t->r);
		t->rev = false;
	}

	return t;
}

Node *merge(Node *l, Node *r){
	if (!l) return r;
	if (!r) return l;

	if (l->y > r->y){
		l = push(l);
		l->r = merge(l->r, r);
		l = relax(l);
		return l;
	}
	else{
		r = push(r);
		r->l = merge(l, r->l);
		r = relax(r);
		return r;
	}
}

pair <Node*, Node*> split(Node *t, int k){
	if (!t) return{ NULL, NULL };
	
	t = push(t);
	if (cnt(t->l) >= k){
		auto tmp = split(t->l, k);
		t->l = tmp.second;
		t = relax(t);
		return{ tmp.first, t };
	}
	else{
		auto tmp = split(t->r, k - cnt(t->l) - 1);
		t->r = tmp.first;
		t = relax(t);
		return{ t, tmp.second };
	}
}

Node *upd1(Node *t, int l, int r){
	auto tmp1 = split(t, l - 1);
	auto tmp2 = split(tmp1.second, r - l + 1);
	auto tmp3 = split(tmp2.first, r - l);
	return merge(merge(merge(tmp1.first, tmp3.second), tmp3.first), tmp2.second);
}

Node *upd2(Node *t, int l, int r){
	auto tmp1 = split(t, l - 1);
	auto tmp2 = split(tmp1.second, r - l + 1);

	tmp2.first->rev ^= true;
	return merge(merge(tmp1.first, tmp2.first), tmp2.second);
}

void dfs(Node *t, int left){
	if (!t) return;

	t = push(t);
	int ind = left + cnt(t->l) + 1;
	ans[ind] = t->x;

	dfs(t->l, left);
	dfs(t->r, ind);
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, q, m;
	cin >> n >> q >> m;
	
	Node *root = NULL;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		root = merge(root, init(a[i], rnd()));
		pass();
	}

	int t, l, r;
	for (int i = 0; i < q; ++i){
		cin >> t >> l >> r;
		if (t == 1){
			root = upd1(root, l, r);
		}
		else{
			root = upd2(root, l, r);
		}
	}

	dfs(root, 0);
	vector <int> b(m);
	for (int i = 0; i < m; ++i){
		cin >> b[i];
		cout << ans[b[i]] << ' ';
	}
	
	return 0;
}