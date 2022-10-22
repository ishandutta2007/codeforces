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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		for(int bm=0; bm<1<<8; bm++) {
			if(bm & 1) continue;
			int A = 0;
			int B = 0;
			int C = 0;
			for(int j=1; j<8; j++) {
				if(bm & 1<<j) {
					if(j & 1<<0) A++;
					if(j & 1<<1) B++;
					if(j & 1<<2) C++;
				}
			}
			if(A<=a && B<=b && C<=c) {
				ans = max(ans, __builtin_popcount(bm));
			}
		}
		cout << ans << nl;
	}

	return 0;
}