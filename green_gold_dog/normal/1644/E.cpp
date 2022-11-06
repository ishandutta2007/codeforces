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



struct node {
	ll mi, col, m, l, r;
	node *ul, *ur;
	node(ll l, ll r): l(l), r(r) {
		mi = 0;
		col = r - l;
		m = 0;
		ul = nullptr;
		ur = nullptr;
	}
	node *get_this() {
		return this;
	}
	void add(ll x) {
		m += x;
		mi += x;
	}
	node *get_l() {
		if (ul == nullptr) {
			ul = new node(l, (l + r) / 2);
		}
		return ul;
	}
	node *get_r() {
		if (ur == nullptr) {
			ur = new node((l + r) / 2, r);
		}
		return ur;
	}
	void push() {
		if (m != 0) {
			get_l()->add(m);
			get_r()->add(m);
			m = 0;
		}
	}
	void update() {
		if (ul == nullptr) {
			if (get_r()->mi > 0) {
				mi = 0;
				col = (((l + r) / 2) - l);
			} else {
				mi = 0;
				col = (((l + r) / 2) - l) + ur->col;
			}
			mi += m;
			return;
		}
		if (ur == nullptr) {
			if (get_l()->mi > 0) {
				mi = 0;
				col = (r - ((l + r) / 2));
			} else {
				mi = 0;
				col = (r - ((l + r) / 2)) + ul->col;
			}
			mi += m;
			return;
		}
		mi = min(get_l()->mi, get_r()->mi);
		col = (mi == get_l()->mi ? get_l()->col : 0) + (mi == get_r()->mi ? get_r()->col : 0);
		mi += m;
	}
	void change(ll ql, ll qr, ll x) {
		if (ql <= l && r <= qr) {
			add(x);
			return;
		}
		if (qr <= l || r <= ql) {
			return;
		}
		//push();
		ll mid = (l + r) / 2;
		if (!((qr <= l) || (mid <= ql))) {
			get_l()->change(ql, qr, x);
		}
		if (!((qr <= mid) || (r <= ql))) {
			get_r()->change(ql, qr, x);
		}
		update();
	}
};

struct segment_tree {
	node *root;
	ll size;
	segment_tree(ll x = 0) {
		size = x;
		root = new node(0, size);
	}
	ll get() {
		return size - root->col;
	}
	void change(ll l, ll r, ll x) {
		root->change(l, r, x);
	}
};

void solve() {
	ll n;
	cin >> n;
	n--;
	string s;
	cin >> s;
	ll colR = 0, colD = 0;
	for (auto i : s) {
		colR += i == 'R';
		colD += i == 'D';
	}
	ll lr = 0, rr = 0, ld = 0, rd = 0;
	vector<tuple<ll, ll, ll, ll>> all;
	for (auto i : s) {
		if (i == 'R') {
			lr++;
			rr++;
			if (lr == 1) {
				rr += n - colR;
			}
		} else {
			ld++;
			rd++;
			if (ld == 1) {
				rd += n - colD;
			}
		}
		all.push_back(make_tuple(lr, ld, rr + 1, rd + 1));
	}
	segment_tree st(200'000'000);
	vector<tuple<ll, ll, ll, ll>> arr;
	for (auto[x1, x2, y1, y2] : all) {
		arr.push_back({x2, 1, x1, y1});
		arr.push_back({y2, -1, x1, y1});
	}
	ll now = 0, ans = 0;
	sort(arr.begin(), arr.end());
	for (auto[num, t, l, r] : arr) {
		ans += (num - now) * st.get();
		now = num;
		st.change(l, r, t);
	}
	cout << ans + 1 << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
/*
















*/