#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

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
        root = merge(merge(t1, t), t2);
        size++;
    }
    void erase(ll k) {
        auto[t1, t2] = split(root, k);
        auto[t11, t12] = split(t1, k-1);
        root =  merge(t11, t2);
        size--;
    }
    ll nr(ll x) {
	    auto[t1, t2h] = split(root, x - 1);
	    auto[t2, t3] = split(t2h, x);
	    ll ans = get(t1) + get(t3);
	    root = merge(t1, merge(t2, t3));
	    return ans;
    }
    ll operator[](ll k) {
        k++;
        auto[t1, t2] = split_num(root, k-1);
        auto[t21, t22] = split_num(t2, 1);
        ll ans = t21->k;
        merge(t1, merge(t21, t22));
        return ans;
    }
    void clear() {
	    root = nullptr;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n, m, k;
		cin >> n >> m >> k;
		set<ll> x, y;
		for (ll i = 0; i < n; i++) {
			ll a;
			cin >> a;
			x.insert(a);
		}
		for (ll i = 0; i < m; i++) {
			ll a;
			cin >> a;
			y.insert(a);
		}
		vector<pair<ll, ll>> xs, ys;
		for (ll i = 0; i < k; i++) {
			ll a, b;
			cin >> a >> b;
			if (x.count(a) + y.count(b) == 2) {
				continue;
			}
			if (x.count(a) == 1) {
				xs.push_back({b, a});
			}
			if (y.count(b) == 1) {
				ys.push_back({a, b});
			}
		}
		vector<tuple<ll, ll, ll>> s1;
		for (auto i : y) {
			s1.push_back({i, 1, -1});
		}
		for (auto[a, b] : xs) {
			s1.push_back({a, 2, b});
		}
		ll ans = 0;
		cartesian_tree now;
		sort(s1.begin(), s1.end());
		for (ll i = 0; i < s1.size(); i++) {
			auto[a, p, b] = s1[i];
			if (p == 1) {
				now.clear();
				while (i < s1.size() && get<0>(s1[i]) == a) {
					i++;
				}
				i--;
			} else {
				ans += now.nr(b);
				now.insert(b);
			}
		}
		now.clear();
		s1.clear();
		for (auto i : x) {
			s1.push_back({i, 1, -1});
		}
		for (auto[a, b] : ys) {
			s1.push_back({a, 2, b});
		}
		sort(s1.begin(), s1.end());
		for (ll i = 0; i < s1.size(); i++) {
			auto[a, p, b] = s1[i];
			if (p == 1) {
				now.clear();
				while (i < s1.size() && get<0>(s1[i]) == a) {
					i++;
				}
				i--;
			} else {
				ans += now.nr(b);
				now.insert(b);
			}
		}
		cout << ans << '\n';
	}
}

/*
















*/