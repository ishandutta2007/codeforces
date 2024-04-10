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

const int L = 61;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		ll n; int m;
		cin >> n >> m;
		vector<int> a(m);
		vector<int> cnt(L);
		for(int i=0; i<m; i++) {
			cin >> a[i];
			cnt[__builtin_ctz(a[i])]++;
		}

		int ans = 0;
		for(int i=0; i+1<L; i++) {
			if(n & 1LL<<i) {
				if(cnt[i]) {
					cnt[i]--;
				} else {
					bool ok = false;
					for(int j=i; j<L; j++) {
						if(cnt[j]) {
							ok = true;
							cnt[j]--;
							break;
						} else {
							cnt[j]++;
							ans++;
						}
					}
					if(!ok) {
						goto sad;
					}
				}
			}
			cnt[i+1] += cnt[i]/2;
		}

		cout << ans << nl;

		continue;

		sad:
		cout << -1 << nl;
	}

	return 0;
}