//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
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

const int N = 5e5 + 1;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	vector<int> primes;
	vector<bool> notp(N);
	int lim = sqrt(N) + 7;
	for(int i=2; i<lim; i++) {
		if(notp[i]) continue;
		for(int j=i*i; j<N; j+=i) {
			notp[j] = true;
		}
	}
	for(int i=2; i<N; i++) {
		if(!notp[i]) {
			primes.push_back(i);
		}
	}
	//cerr<<primes.size()<<" primes"<<nl;

	int n;
	cin >> n;
	vector<int> ans;
	for(int i=2; i<=n; i++) {
		for(int p : primes) {
			if(p*p > i) {
				ans.push_back(1);
				break;
			} else if(i%p == 0) {
				assert(i != p);
				ans.push_back(max(p, i/p));
				break;
			}
		}
	}
	sort(ans.begin(), ans.end());
	for(int it : ans) {
		cout << it << " ";
	}
	cout << nl;

	return 0;
}