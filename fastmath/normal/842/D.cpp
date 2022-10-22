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
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;
const int BIT = 30;

bool want[BIT];

struct Node{
	int val;
	Node *l, *r;
};

Node *init(){
	Node *res = new Node();
	res->l = NULL;
	res->r = NULL;
	res->val = 0;

	return res;
}

Node *push(Node *t){
	if (!t->l) t->l = init();
	if (!t->r) t->r = init();
	return t;
}

int val(Node *t){
	if (!t) return 0;
	return t->val;
}

Node *upd(Node *t, int x, int i){
	if (i == -1){
		t->val = 1;
		return t;
	}

	push(t);
	if (!((x >> i) & 1)){
		t->l = upd(t->l, x, i - 1);
	}
	else{
		t->r = upd(t->r, x, i - 1);
	}

	t->val = val(t->l) + val(t->r);
	return t;
}

pair <Node*, int> get(Node *t, int bt){
	if (bt == -1){
		return{ t, 0 };
	}

	t = push(t);
	if (want[bt]){
		if (val(t->r) < (1 << bt)){
			auto tmp = get(t->r, bt - 1);
			t->r = tmp.first;
			return{ t, tmp.second };
		}
		else{
			auto tmp = get(t->l, bt - 1);
			t->l = tmp.first;
			return{ t, tmp.second + (1 << bt) };
		}
	}
	else{
		if (val(t->l) < (1 << bt)){
			auto tmp = get(t->l, bt - 1);
			t->l = tmp.first;
			return{ t, tmp.second };
		}
		else{
			auto tmp = get(t->r, bt - 1);
			t->r = tmp.first;
			return{ t, tmp.second + (1 << bt) };
		}
	}
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, x, q;
	cin >> n >> q;
	Node *root = init();
	for (int i = 0; i < n; ++i){
		cin >> x;
		root = upd(root, x, BIT - 1);
	}

	for (int i = 0; i < q; ++i){
		cin >> x;
		for (int bt = BIT - 1; bt >= 0; --bt){
			if ((x >> bt) & 1) want[bt] ^= 1;
		}

		auto tmp = get(root, BIT - 1);
		root = tmp.first;
		cout << tmp.second << '\n';
	}

	return 0;
}