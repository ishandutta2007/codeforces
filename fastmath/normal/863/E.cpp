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

//#define int long long
#define rand() (rand()<<15+rand())
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

struct Node{
	int val, add;
	Node *l, *r;
};

Node *init(){
	Node *res = new Node();
	res->val = 0;
	res->add = 0;
	res->l = NULL;
	res->r = NULL;

	return res;
}

Node *push(Node *t){
	if (!t->l) t->l = init();
	if (!t->r) t->r = init();

	t->l->val += t->add;
	t->r->val += t->add;
	t->l->add += t->add;
	t->r->add += t->add;
	t->add = 0;

	return t;
}

Node *relax(Node *t){
	t->val = min(t->l->val, t->r->val) + t->add;
	return t;
}

Node *upd(Node *t, int tl, int tr, int l, int r){
	if (l > tr || tl > r) return t;

	if (tl >= l && tr <= r){
		t->val++;
		t->add++;
		return t;
	}

	int m = (tl + tr) / 2;
	t = push(t);
	t->l = upd(t->l, tl, m, l, r);
	t->r = upd(t->r, m + 1, tr, l, r);
	t = relax(t);
	return t;
}

pair <Node*, int> get(Node *t, int tl, int tr, int l, int r){
	if (tl > r || l > tr) return{ t, MOD };
	if (tl >= l && tr <= r) return{ t, t->val };

	int m = (tl + tr) / 2;
	t = push(t);

	auto tmp1 = get(t->l, tl, m, l, r);
	auto tmp2 = get(t->r, m + 1, tr, l, r);

	t->l = tmp1.first;
	t->r = tmp2.first;

	return{ t, min(tmp1.second, tmp2.second) + t->add };
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	Node *root = init();
	vector <pair <int, int> > a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i].first >> a[i].second;
		root = upd(root, 0, MOD, a[i].first, a[i].second);
	}

	for (int i = 0; i < n; ++i){
		auto tmp = get(root, 0, MOD, a[i].first, a[i].second);

		if (tmp.second > 1){
			cout << i + 1 << '\n';
			return 0;
		}

		root = tmp.first;
	}

	cout << "-1\n";
	return 0;
}