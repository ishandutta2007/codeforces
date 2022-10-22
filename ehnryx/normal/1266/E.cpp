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
int a[N], have[N];
unordered_map<int,int> cnt[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	ll tot = 0;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		tot += a[i];
	}

	int m;
	cin >> m;
	int ans = 0;
	for(int i=0; i<m; i++) {
		int s, t, u;
		cin >> s >> t >> u;
		if(cnt[s].count(t)) {
			int v = cnt[s][t];
			cnt[s].erase(t);
			if(have[v] <= a[v]) {
				ans--;
			}
			have[v]--;
			assert(have[v] >= 0);
		}
		if(u) {
			cnt[s][t] = u;
			if(have[u] < a[u]) {
				ans++;
			}
			have[u]++;
		}
		cout << tot - ans << nl;
	}

	return 0;
}