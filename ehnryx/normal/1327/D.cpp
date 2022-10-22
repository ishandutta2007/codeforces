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
const ld EPS = 1e-11;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 1;
int a[N], c[N];
bool vis[N];

bool check_jump(const vector<int>& v, int k) {
	int n = v.size();
	for(int i=0; i<k; i++) {
		int col = c[v[i]];
		bool ok = true;
		for(int j=k; j<n; j+=k) {
			int nc = c[v[(i+j)%n]];
			if(nc != col) {
				ok = false;
				break;
			}
		}
		if(ok) return true;
	}
	return false;
}

int solve_cycle(int s) {
	vector<int> v;
	for(int u=s; !vis[u]; u=a[u]) {
		v.push_back(u);
		vis[u] = true;
	}
	int n = v.size();
	int res = n;
	for(int d=1; d*d<=n; d++) {
		if(n%d == 0) {
			if(d < res && check_jump(v, d)) {
				res = d;
			}
			if(d != n/d && n/d < res && check_jump(v, n/d)) {
				res = n/d;
			}
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
			vis[i] = false;
		}
		for(int i=1; i<=n; i++) {
			cin >> c[i];
		}
		int ans = n;
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				ans = min(ans, solve_cycle(i));
			}
		}
		cout << ans << nl;
	}

	return 0;
}