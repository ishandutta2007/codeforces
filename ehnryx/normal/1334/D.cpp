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

void print(int i, int s, int e) {
	for(int j=s; j<=e; j++) {
		if(j % 2 == 1) {
			cout << i << " ";
		} else {
			cout << i + j/2 << " ";
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n; ll l, r;
		cin >> n >> l >> r;
		ll cur = 0;
		for(int i=1; i<n; i++) {
			ll nxt = cur + 2*(n-i);
			if(cur < l && l <= nxt) {
				ll s = l - cur;
				ll e = min(r, nxt) - cur;
				print(i, s, e);
			} else if(cur < r && r <= nxt) {
				ll s = 1;
				ll e = r - cur;
				print(i, s, e);
			} else if(l <= cur && nxt < r) {
				ll s = 1;
				ll e = nxt - cur;
				print(i, s, e);
			}
			cur = nxt;
		}
		if(cur < r) {
			cout << 1 << " ";
		}
		cout << nl;
	}

	return 0;
}