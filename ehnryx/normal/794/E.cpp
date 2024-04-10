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
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	int a[n];
	int maxv = 0;
	vector<pair<int,int>> even, odd;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		maxv = max(maxv, a[i]);
		int elen = 2*min(i, n-1-i) + 1;
		even.push_back(make_pair(elen + 1, a[i]));
		if(i>0) {
			int olen = 2*min(i, n-i);
			odd.push_back(make_pair(olen + 1, min(a[i-1], a[i])));
		}
	}
	sort(even.begin(), even.end(), greater<pair<int,int>>());
	sort(odd.begin(), odd.end(), greater<pair<int,int>>());

	int ans[n];
	// even
	for(int i=n%2, j=0, cur=0; i<n; i+=2) {
		while(j < even.size() && even[j].first >= n-i) {
			cur = max(cur, even[j].second);
			j++;
		}
		ans[i] = cur;
	}
	// odd
	for(int i=(n%2)^1, j=0, cur=0; i<n; i+=2) {
		while(j < odd.size() && odd[j].first >= n-i) {
			cur = max(cur, odd[j].second);
			j++;
		}
		ans[i] = cur;
	}
	ans[n-1] = maxv;

	for(int i=0; i<n; i++) {
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}