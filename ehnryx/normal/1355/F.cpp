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
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

bool over(ll a, ll b, ll c) {
	return c/a < b || a*b > c;
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	const ld le9 = log(1e9);
	vector<int> ps;
	vector<ll> ask;
	ll cur = 1;
	for(int i=2; ask.size()<17; i++) {
		bool ok = true;
		for(int j=2; j*j<=i; j++) {
			ok &= (i % j > 0);
		}
		if(ok) {
			if(over(cur, i, 1e18)) {
				ask.push_back(cur);
				cur = 1;
			}
			cur *= i;
			ps.push_back(i);
		}
	}

	int T;
	cin >> T;
	while(T--) {
		vector<int> v;
		for(ll it : ask) {
			cout << "? " << it << endl;
			int in;
			cin >> in;
			for(int j : ps) {
				if(in % j == 0) {
					v.push_back(j);
				}
			}
		}
		if(v.size() % 2) v.push_back(7);

		ll lcm = 1;
		for(int i=0; i<v.size(); i+=2) {
			ll val = 1;
			for(int j=i; j<=i+1; j++) {
				for(int k=1; k<le9/log(v[j]); k++) {
					val *= v[j];
				}
			}
			cout << "? " << val << endl;
			int in;
			cin >> in;
			lcm = lcm * in / __gcd(lcm, (ll)in);
		}

		int cnt = 0;
		for(int i=1; i*i<=lcm; i++) {
			if(lcm % i == 0) {
				cnt += 1 + (i*i < lcm);
			}
		}
		cout << "! " << max(cnt + 7, cnt * 2) << endl;
	}

	return 0;
}