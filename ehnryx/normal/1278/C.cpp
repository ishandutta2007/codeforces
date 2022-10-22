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

const int N = 1e5+1;
int lv[N], rv[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int tot = 0;
		for(int i=0; i<n; i++) {
			cin>>lv[i];
			tot += (lv[i]*2 - 3);
		}
		for(int i=0; i<n; i++) {
			cin>>rv[i];
			tot += (rv[i]*2 - 3);
		}
		reverse(lv,lv+n);

		unordered_map<int,int> lid, rid;
		int val = 0;
		lid[0] = 0;
		for(int i=0; i<n; i++) {
			val += lv[i]*2 - 3;
			if(!lid.count(val)) {
				lid[val] = i+1;
			}
		}
		val = 0;
		rid[0] = 0;
		for(int i=0; i<n; i++) {
			val += rv[i]*2 - 3;
			if(!rid.count(val)) {
				rid[val] = i+1;
			}
		}

		int ans = INF;
		for(const auto& [v,take] : lid) {
			if(rid.count(tot - v)) {
				ans = min(ans, take + rid[tot-v]);
			}
		}
		assert(ans<INF);
		cout << ans << nl;
	}

	return 0;
}