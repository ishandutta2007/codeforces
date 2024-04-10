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

const int N = 2e5+2;
pii t[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		int easy = 0;
		int hard = 0;
		for(int i=0; i<n; i++) {
			cin >> t[i].second;
			if(t[i].second) hard++;
			else easy++;
		}
		for(int i=0; i<n; i++) {
			cin >> t[i].first;
		}
		sort(t, t+n);
		t[n] = make_pair(m+1, 0);

		ll need = 0;
		int ans = 0;
		for(int i=0, j=0; i<=n; i++) {
			while(j<i) {
				need += (t[j].second ? b : a);
				if(t[j].second) hard--;
				else easy--;
				j++;
			}
			if(need >= t[i].first) continue;
			int have = t[i].first - need - 1;
			int adde = min(have/a, easy);
			have -= adde*a;
			int addh = min(have/b, hard);
			ans = max(ans, i + adde + addh);
		}
		cout << ans << nl;
	}

	return 0;
}