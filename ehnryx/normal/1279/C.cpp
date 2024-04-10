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
int a[N], b[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		for(int i=1; i<=m; i++) {
			cin >> b[i];
		}
		unordered_set<int> seen;
		ll ans = 0;
		for(int i=1, j=1; i<=m; i++) {
			if(seen.count(b[i])) {
				ans += 1;
				seen.erase(b[i]);
			} else {
				while(j<=n && b[i]!=a[j]) {
					seen.insert(a[j]);
					j++;
				}
				assert(j <= n && b[i] == a[j]);
				ans += 2*seen.size() + 1;
				++j;
			}
		}
		cout << ans << nl;
	}

	return 0;
}