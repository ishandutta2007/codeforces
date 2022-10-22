//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}

		vector<int> left, right;
		right.push_back(0);
		int moves = 0;
		for(int l=0, r=n-1; l<=r; ) {
			int lsum = 0;
			while(l<=r && lsum<=right.back()) {
				lsum += a[l++];
			}
			left.push_back(lsum);
			moves += !!lsum;
			int rsum = 0;
			while(l<=r && rsum<=left.back()) {
				rsum += a[r--];
			}
			right.push_back(rsum);
			moves += !!rsum;
		}
		cout << moves << " ";
		cout << accumulate(left.begin(), left.end(), 0) << " ";
		cout << accumulate(right.begin(), right.end(), 0) << nl;
	}

	return 0;
}