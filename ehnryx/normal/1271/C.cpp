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



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, x, y;
	cin >> n >> x >> y;
	int a[n], b[n];
	vector<int> cnt(4, 0);
	for(int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
		if(a[i] < x) cnt[0]++;
		if(a[i] > x) cnt[1]++;
		if(b[i] < y) cnt[2]++;
		if(b[i] > y) cnt[3]++;
	}

	int maxv = max(max(cnt[0], cnt[1]), max(cnt[2], cnt[3]));
	cout << maxv << nl;
	if(maxv == cnt[0]) {
		cout << x-1 << " " << y << nl;
	} else if(maxv == cnt[1]) {
		cout << x+1 << " " << y << nl;
	} else if(maxv == cnt[2]) {
		cout << x << " " << y-1 << nl;
	} else {
		cout << x << " " << y+1 << nl;
	}

	return 0;
}