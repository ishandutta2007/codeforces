#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

int mul(int a, int b) {
	return ((ll)a * b) % md;
}

void sub(int &a, int b) {
	a -= b;
	if (a < 0) a += md;
}

void add(int &a, int b) {
	a += b;
	if (a >= md) a -= md;
}

struct fenwick {
	vector <ll> f;
	int n;
	fenwick(int nn) {
		f.resize(nn);
		n = nn;
	}
	void modify(int x, ll y) {
		for (int i = x; i < n; i |= i + 1) f[i] += y;
	}
	ll get(int x) {
		ll sum = 0;
		for (int i = x; i >= 0; i &= i + 1, --i) {
			sum += f[i];
		}
		return sum;
	}
	ll sum(int l, int r) {
		return get(r) - get(l - 1);
	}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    fenwick fs(n), fw(n);
    vector <int> a(n), w(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	a[i] -= i;
    }
    for (int i = 0; i < n; ++i) {
    	cin >> w[i];
    	fw.modify(i, w[i]);
    }
    for (int i = 0; i < n; ++i) {
    	fs.modify(i, mul(w[i], a[i]));
    }
    while (q--) {
    	int x, y;
    	cin >> x >> y;
    	if (x < 0) {
    		x = -x;
    		--x;
    		fw.modify(x, -w[x]);
    		fw.modify(x, y);
    		fs.modify(x, -mul(w[x], a[x]));
    		fs.modify(x, mul(y, a[x]));
    		w[x] = y;
    	}
    	else {
    		--x, --y;
    		int l = x - 1, r = y;
    		ll sum = fw.sum(x, y);
    		while (r - l > 1) {
    			int m = (l + r) >> 1;
    			if (2 * fw.sum(x, m) <= sum) l = m;
    			else r = m;
    		}
    		++l;
    		int ans = mul(fw.sum(x, l) % md, a[l]);
    		sub(ans, ((fs.sum(x, l) % md) + md) % md);
			add(ans, ((fs.sum(l, y) % md) + md) % md);
			sub(ans, mul(fw.sum(l, y) % md, a[l]));
			cout << ans << '\n';
    	}
    }
}