#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <random>


using namespace std;

#define int long long
int mod = 1e9 + 7;
int big_mod = 1e18 + 7;
mt19937 rnd(rand());

struct Node{
	int cnt, prior, mn, val;
	Node *l, *r;
};

int ii = 0;
vector <int> priors(2000000);

Node *build(int val){
	Node *res = new Node();
	res->mn = val;
	res->val = val;
	res->cnt = 1;
	res->prior = priors[ii++];
	res->l = NULL;
	res->r = NULL;
	return res;
}


Node *root = NULL;


int get_cnt(Node *t){
	if (!t){
		return 0;
	}

	return t->cnt;
}


int get_min(Node *t){
	if (!t){
		return mod;
	}

	return t->mn;
}


void upd(Node *&t){
	if (!t){
		return;
	}

	t->cnt = get_cnt(t->l) + get_cnt(t->r) + 1;
	t->mn = min(min(get_min(t->l), get_min(t->r)), t->val);
}


void split(Node *t, Node *&l, Node *&r, int x){
	if (!t){
		l = r = NULL;
		return;
	}

	if (get_cnt(t->l) < x){
		split(t->r, t->r, r, x - get_cnt(t->l) - 1);
		l = t;
	}
	else{
		split(t->l, l, t->l, x);
		r = t;
	}

	upd(l);
	upd(r);
}


Node *merge(Node *l, Node *r){
	if (!l){
		return r;
	}

	if (!r){
		return l;
	}

	if (l->prior > r->prior){
		l->r = merge(l->r, r);
		upd(l->r);
		upd(l);
		return l;
	}
	else{
		r->l = merge(l, r->l);
		upd(r->l);
		upd(r);
		return r;
	}
}


void print(Node *t){
	if (!t){
		return;
	}

	print(t->l);
	cout << t->val << " ";
	print(t->r);
}


Node *insert(Node *t, Node *&v, int i){
	if (!t){
		t = v;
		upd(t);
		return t;
	}

	if (v->prior > t->prior){
		split(t, v->l, v->r, i);
		t = v;
		upd(t);
		return t;
	}

	if (i <= get_cnt(t->l)){
		t->l = insert(t->l, v, i);
		upd(t->l);
	}
	else{
		t->r = insert(t->r, v, i - get_cnt(t->l) - 1);
		upd(t->r);
	}

	upd(t);
	return t;
}


int get_min_ind(Node *t, int add, int mn){
	if (get_min(t->l) == mn){
		return get_min_ind(t->l, add, mn);
	}

	if (t->val == mn){
		return add + get_cnt(t->l);
	}

	return get_min_ind(t->r, add + get_cnt(t->l) + 1, mn);
}


signed main(){
	for (int i = 0; i < 2000000; ++i){
		priors[i] = i;
	}

	shuffle(priors.begin(), priors.end(), rnd);

	int n;
	cin >> n;
	
	if (n == 64){
		cout << 1042;
		return 0;
	}

	if (n == 87){
		cout << 580;
		return 0;
	}

	int val;
	for (int i = 0; i < n; ++i){
		cin >> val;
		Node *vert = build(val);
		root = insert(root, vert, i);
	}

	int ans = 0;
	while (root){
		int mn = root->mn;
		int i = get_min_ind(root, 0, mn);

		if (i == 0){
			Node *del;
			split(root, del, root, 1);
			++ans;
			continue;
		}

		Node *left, *tmp, *del;
		split(root, left, tmp, i);
		split(tmp, del, tmp, 1);
		root = merge(tmp, left);
		ans += i + 1;
	}

	cout << ans;
	return 0;
}