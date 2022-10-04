#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 998244353;

int sum(int a, int b) {
	a += b;
	if (a >= md) a -= md;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += md;
	return a;
}

int mul(int a, int b) {
	return ((ll)a * b) % md;
}

int power(int a, ll b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int inv(int a) {
	return power(a, md - 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    vector <int> p(n);
    for (int i = 0; i < n; ++i) {
    	cin >> p[i];
    	p[i] = mul(p[i], inv(100));
    }
    vector <int> pr(n + 1);
    pr[0] = 1;
    for (int i = 1; i <= n; ++i) {
    	pr[i] = mul(pr[i - 1], p[i - 1]);
    }
    vector <int> sm(n + 1);
    sm[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	sm[i] = sm[i - 1];
    	sm[i] = sum(sm[i], pr[i - 1]);
    }
    int ans = mul(sm[n], inv(pr[n]));
    auto add_seg = [&] (int l, int r) {
    	int cur = mul(sub(sm[r], sm[l]), inv(pr[l]));
    	int den = mul(pr[r], inv(pr[l]));
    	ans = sum(ans, mul(cur, inv(den)));
    };
    auto del_seg = [&] (int l, int r) {
    	int cur = mul(sub(sm[r], sm[l]), inv(pr[l]));
    	int den = mul(pr[r], inv(pr[l]));
    	ans = sub(ans, mul(cur, inv(den)));
    };
    set <int> hv;
    hv.insert(0);
    hv.insert(n);
    while (q--) {
    	int id;
    	cin >> id;
    	--id;
    	if (hv.count(id)) {
    		auto it = hv.find(id);
    		int l = *prev(it);
    		int r = *next(it);
    		del_seg(l, id);
    		del_seg(id, r);
    		hv.erase(id);
    		add_seg(l, r);
    	} else {
    		auto it = hv.lower_bound(id);
    		int r = *it;
    		int l = *prev(it);
    		del_seg(l, r);
    		hv.insert(id);
    		add_seg(l, id);
    		add_seg(id, r);
    	}
    	cout << ans << '\n';
    }
}