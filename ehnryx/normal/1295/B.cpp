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



// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, x;
		cin >> n >> x;
		string t;
		cin >> t;
		if(x < 0) {
			x = -x;
			for(char& c : t) {
				if(c == '0') c = '1';
				else c = '0';
			}
		}

		vector<int> cnt(2*n+1);
		int res = 0;
		for(int i=0; i<n; i++) {
			cnt[res+n]++;
			if(t[i] == '0') res++;
			else res--;
		}

		if(res == 0) {
			if(0 <= x+n && x+n <= 2*n && cnt[x+n]) {
				cout << -1 << nl;
			} else {
				cout << 0 << nl;
			}
		} else if(res < 0) {
			ll ans = 0;
			for(int s=0; s>=-n; s+=res) {
				int val = x-s + n;
				if(0 <= val && val <= 2*n) {
					ans += cnt[val];
				}
			}
			cout << ans << nl;
		} else {
			ll ans = 0;
			int first = max(0, (x-n)/res * res);
			for(int s=first; s-x<=n; s+=res) {
				int val = x-s + n;
				if(0 <= val && val <= 2*n) {
					ans += cnt[val];
				}
			}
			cout << ans << nl;
		}
	}

	return 0;
}