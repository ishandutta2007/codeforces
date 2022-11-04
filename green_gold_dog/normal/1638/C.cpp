#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

mt19937 rnd(time(0));

struct node {
	ll k, p, s = 1;
	node *l = nullptr, *r = nullptr;
	node(ll k): k(k), p(rnd()) {}
};

ll get(node *t) {
	if (t == nullptr) {
		return 0;
	}
	return t->s;
}

void upd(node *t) {
	t->s = 1+get(t->l)+get(t->r);
}

pair<node*, node*> split(node* t, ll k) {
	if (t == nullptr) {
		return {nullptr, nullptr};
	}
	if (t->k > k) {
		auto[t1, t2] = split(t->l, k);
		t->l = t2;
		upd(t);
		return {t1, t};
	} else {
		auto[t1, t2] = split(t->r, k);
		t->r = t1;
		upd(t);
		return {t, t2};
	}
}

node* merge(node* t1, node* t2) {
	if (t1 == nullptr) {
		return t2;
	}
	if (t2 == nullptr) {
		return t1;
	}
	if (t1->p > t2->p) {
		auto tn = merge(t1->r, t2);
		t1->r = tn;
		upd(t1);
		return t1;
	} else {
		auto tn = merge(t1, t2->l);
		t2->l = tn;
		upd(t2);
		return t2;
	}
}

pair<node*, node*> split_num(node* t, ll k) {
	if (t == nullptr) {
		return {nullptr, nullptr};
	}
	ll s = get(t->l);
	if (s >= k) {
		auto[t1, t2] = split_num(t->l, k);
		t->l = t2;
		upd(t);
		return {t1, t};
	} else {
		auto[t1, t2] = split_num(t->r, k-s-1);
		t->r = t1;
		upd(t);
		return {t, t2};
	}
}

struct cartesian_tree {
	node *root;
	ll size = 0;
	cartesian_tree(node *root): root(root) {}
	cartesian_tree() {
		root = nullptr;
	}
	void insert(ll k) {
		node *t = new node(k);
		auto[t1, t2] = split(root, k);
		if (t2 == nullptr) {
			root = merge(t1, t);
		} else {
			auto[t21, t22] = split_num(t2, t2->s - 1);
			root = merge(t1, t22);
		}
		size++;
	}
	void erase(ll k) {
		auto[t1, t2] = split(root, k);
		auto[t11, t12] = split(t1, k-1);
		root =  merge(t11, t2);
		size--;
	}
	ll operator[](ll k) {
		k++;
		auto[t1, t2] = split_num(root, k-1);
		auto[t21, t22] = split_num(t2, 1);
		ll ans = t21->k;
		merge(t1, merge(t21, t22));
		return ans;
	}
};

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cartesian_tree ct;
	for (auto i : arr) {
		ct.insert(i);
	}
	cout << ct.root->s << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		solve();
	}
}
/*
















*/