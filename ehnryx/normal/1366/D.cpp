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



// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	const int N = 1e7 + 7;
	vector<bool> np(N);
	for(int i=2; i*i<N; i++) {
		if(np[i]) continue;
		for(int j=i*i; j<N; j+=i) {
			np[j] = true;
		}
	}
	vector<int> primes;
	for(int i=2; i<N; i++) {
		if(!np[i]) {
			primes.push_back(i);
		}
	}

	int n;
	cin >> n;
	vector<int> other(n);
	for(int i=0; i<n; i++) {
		int v;
		cin >> v;
		int orig = v;
		vector<int> ps;
		for(int p : primes) {
			if(p*p > v) break;
			if(v % p == 0) {
				ps.push_back(p);
				if(p != 2 && orig%2 == 0) ps.push_back(2*p);
				while(v % p == 0) {
					v /= p;
				}
			}
		}
		if(v > 1) {
			ps.push_back(v);
			if(v != 2 && orig%2 == 0) ps.push_back(2*v);
		}
		bool ok = false;
		for(int a : ps) {
			if(ok) break;
			for(int b : ps) {
				if(ok) break;
				if(__gcd(a+b, orig) == 1) {
					cout << a << " ";
					other[i] = b;
					ok = true;
				}
			}
		}
		if(!ok) {
			cout << -1 << " ";
			other[i] = -1;
		}
	}
	cout << nl;

	for(int i=0; i<n; i++) {
		cout << other[i] << " ";
	}
	cout << nl;

	return 0;
}