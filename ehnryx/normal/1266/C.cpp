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

const int N = 500+1;
int g[N][N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	if(max(n,m) == 1) {
		cout << 0 << nl;
	} else {
		bool s = n<m;
		if(s) swap(n,m);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(s) g[j][i] = (i+m)*j;
				else g[i][j] = (i+m)*j;
			}
		}
		if(s) swap(n,m);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cout << g[i][j] << " ";
			}
			cout << nl;
		}
	}

	return 0;
}