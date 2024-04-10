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

const int N = 3e5 + 1;
const int M = 8;
int a[N][M];
int other[1<<M];

pair<int,int> solve(int n, int m, int v) {
	memset(other, 0, sizeof other);
	int all = (1<<m) - 1;
	for(int i=1; i<=n; i++) {
		int bm = 0;
		for(int j=0; j<m; j++) {
			if(a[i][j] >= v) {
				bm |= 1<<j;
			}
		}
		other[bm] = i;
		if(other[all]) {
			return make_pair(other[all], i);
		}
		for(int sm=bm; sm; sm=(sm-1)&bm) {
			if(other[all^sm]) {
				return make_pair(other[all^sm], i);
			}
		}
	}
	return make_pair(-1, -1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}

	int l = 0;
	int r = INF;
	while(l<r) {
		int v = (l+r+1)/2;
		if(solve(n, m, v).first != -1) {
			l = v;
		} else {
			r = v-1;
		}
	}
	auto [x, y] = solve(n, m, r);
	cout << x << " " << y << nl;

	return 0;
}