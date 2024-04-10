//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const ll P = 1789;
const ll M = 1e9+123;

ll power(ll n, ll e, ll m) {
	ll r = 1;
	for(;e>0;e/=2) {
		if(e&1) r = r*n % m;
		n = n*n % m;
	}
	return r;
}

ll inverse(ll n, ll m) {
	return power(n, m-2, m);
}

const int N = 1<<18;
char s[N];
int first[N], last[N];

struct BIT {
	ll bit[N];
	void insert(int x, ll v, ll m=0) {
		for(++x; x<N; x+=x&-x) {
			bit[x] += v;
			if(m) bit[x] %= m;
		}
	}
	ll query(int x) {
		ll res = 0;
		for(++x; x>0; x-=x&-x) {
			res += bit[x];
		}
		return res;
	}
	ll query(int l, int r) {
		return query(r) - query(l-1);
	}
};

BIT all, odd, val;

#ifdef DEBUG
string substring(int l, int len) {
	string t;
	for(int i=0; i<len; i++) {
		t.push_back(s[l+i]);
	}
	return t;
}

string shift_left(string t) {
	for(bool changed=true; changed; ) {
		changed = false;
		for(int i=1; i+1<t.size(); i++) {
			if(t[i-1] == '0' && t[i] == '1' && t[i+1] == '1') {
				swap(t[i-1], t[i+1]);
				changed = true;
			}
		}
	}
	return t;
}
#endif

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> s[i];
	}
	s[0] = s[n+1] = '0';

	for(int i=1; i<=n; i++) {
		all.insert(i, s[i] == '1');
		if(s[i] == '1') {
			if(s[i-1] == '0') {
				first[i] = i;
			} else {
				first[i] = first[i-1];
			}
		}
	}
	for(int i=n; i>=1; i--) {
		if(s[i] == '1') {
			if(s[i+1] == '0') {
				last[i] = i;
				if((last[i] - first[i]) % 2 == 0) {
					odd.insert(i, 1);
					int v = all.query(i+1, n+1) - odd.query(i+1, n+1);
					val.insert(i, power(P, i + v, M), M);
					//cerr<<"val.insert "<<i+v<<" at "<<i<<nl;
				}
			} else {
				last[i] = last[i+1];
			}
		}
	}

	function<ll(int,int)> query = [=](int l, int r) {
		if(s[r] == '1' && first[r] <= l) return (ll)0;
		//cerr<<"QUERY "<<l<<" "<<r<<nl;
		ll res = 0;
		int v = all.query(r+1, n+1) - odd.query(r+1, n+1);
		//cerr<<"v to the right: "<<v<<nl;
		bool extra_odd = false;
		if(s[r] == '1' && (r - first[r]) % 2 == 0 && last[r] > r) {
			extra_odd = true;
			res += power(P, r-(l-1), M);
			//cerr<<"extra odd, += "<<r-(l-1)<<nl;
		}
		if(s[l] == '1' && (last[l] - l) % 2 == 0 && (last[l] - first[l]) % 2 != 0) {
			int add = all.query(last[l]+1, n+1) - odd.query(last[l]+1, n+1);
			add = add - v - extra_odd;
			res += power(P, last[l]-(l-1) + add, M);
			//cerr<<"extra odd on left side -> += "<<last[l]-(l-1)<<" + "<<add<<nl;
		}
		if(s[l] == '1' && (last[l] - l) % 2 != 0 && (last[l] - first[l]) % 2 == 0) {
			//cerr<<"here: "<<nl;
			int add = all.query(last[l]+1, n+1) - odd.query(last[l]+1, n+1);
			add = add - v - extra_odd;
			res -= power(P, last[l]-(l-1) + add, M);
			//cerr<<"minus odd on left side -> -= "<<last[l]-(l-1)<<" + "<<add<<nl;
		}
		ll value = val.query(l, r) % M;
		ll fix = inverse(power(P, extra_odd + v + l-1, M), M) % M;
		res += value * fix;
		//cerr<<"fix = - "<<extra_odd<<" - "<<v<<" - "<<l-1<<nl;
		res = (res % M + M) % M;
		return res;
	};

	int m;
	cin >> m;
	for(int i=0; i<m; i++) {
		int a, b, len;
		cin >> a >> b >> len;
#ifdef DEBUG
		string A = shift_left(substring(a, len));
		string B = shift_left(substring(b, len));
#endif
		int ra = a + len - 1;
		int rb = b + len - 1;
		if(all.query(a, ra) == all.query(b, rb) && query(a, ra) == query(b, rb)) {
			cout << "Yes" << nl;
#ifdef DEBUG
			if(A != B) {
				cerr<<"WRONG at "<<a<<" "<<b<<" "<<len<<": got 'yes' when expected 'no'"<<nl;
			}
#endif
		} else {
			cout << "No" << nl;
#ifdef DEBUG
			if(A == B) {
				cerr<<"WRONG at "<<a<<" "<<b<<" "<<len<<": got 'no' when expected 'yes'"<<nl;
			}
#endif
		}
	}

	return 0;
}