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

const int N = 2e5+1;
int a[N];

int price(int s, int n, int k) {
	int res = 0;
	for(int i=1; i<=n; i++) {
		res += a[s+i*k];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, p, k;
		cin >> n >> p >> k;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		sort(a+1, a+1+n);

		int ans = 0;
		for(int i=0, pre=0; i<k; i++) {
			pre += a[i];
			if(pre <= p) {
				int l = 0;
				int r = (n-i)/k;
				while(l < r) {
					int m = (l+r+1)/2;
					if(price(i,m,k) <= p-pre) {
						l = m;
					} else {
						r = m-1;
					}
				}
				ans = max(ans, i+r*k);
			}
		}
		cout << ans << nl;
	}

	return 0;
}