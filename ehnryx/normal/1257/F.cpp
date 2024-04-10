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

const ll P = 1789;
const ll P2 = 101;
const ll MOD2 = 1e9+9;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	int a[n], b[n];
	for(int i=0;i<n;i++) {
		cin >> a[i];
		b[i] = a[i] >> 15;
		a[i] &= (1<<15) - 1;
	}

	int acnt[1<<15][n], bcnt[1<<15][n];
	map<pair<ll,ll>,int> bvals;
	for(int bm=0;bm<1<<15;bm++) {
		ll ha = 0;
		ll ha2 = 0;
		for(int i=0;i<n;i++) {
			acnt[bm][i] = __builtin_popcount(bm ^ a[i]);
			bcnt[bm][i] = __builtin_popcount(bm ^ b[i]);
			ha = (ha*P + bcnt[bm][i]+7) % MOD;
			ha2 = (ha2*P2 + bcnt[bm][i]+7) % MOD2;
		}
		bvals[make_pair(ha,ha2)] = bm;
	}

	for(int bm=0;bm<1<<15;bm++) {
		for(int tot=0;tot<=30;tot++) {
			ll ha = 0;
			ll ha2 = 0;
			for(int i=0;i<n;i++) {
				if(tot < acnt[bm][i]) {
					ha = -1;
					break;
				}
				ha = (ha*P + (tot - acnt[bm][i]) + 7) % MOD;
				ha2 = (ha2*P2 + (tot - acnt[bm][i]) + 7) % MOD2;
			}
			auto hh = make_pair(ha, ha2);
			if(bvals.count(hh)) {
				int ans = bvals[hh] << 15 | bm;
				cout << ans << nl;
				//cerr << bitset<30>(ans) << nl;
				return 0;
			}
		}
	}

	cout << -1 << nl;

	return 0;
}