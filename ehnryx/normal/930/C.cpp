#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef mt19937 RNG;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;

namespace BIT {
	int length;
	vector<ll> freq;
	void init(int n) {
		length = n;
		freq.resize(n+1, 0);
	}
	void update(int x, int cnt) {
		for ( ; x <= length; x += x & -x)
			freq[x] += cnt;
	}
	void insert(int l, int r) {
		update(l, 1);
		update(r+1, -1);
	}
	ll query(int x) { 
		ll res = 0;
		for ( ; x > 0; x -= x & -x)
			res += freq[x];
		return res;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	BIT::init(m);

	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		BIT::insert(l, r);
	}

	int vals[2*m];
	for (int i = 1; i <= m; i++) {
		vals[2*i-1] = BIT::query(i);
		vals[2*i-2] = 2*n - vals[2*i-1];
	}

	int lis[2*m]; memset(lis, INF, sizeof lis);
	for (int i = 0; i < 2*m; i++) {
		*upper_bound(lis, lis+2*m, vals[i]) = vals[i];
	}
	cout << lower_bound(lis, lis+2*m, INF) - lis << nl;

	return 0;
}