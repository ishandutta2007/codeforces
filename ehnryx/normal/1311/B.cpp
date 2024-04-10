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
const ll MOD = 1e9+7;
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
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(n), p(m);
		for(int i=0; i<n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b.begin(), b.end());

		for(int i=0; i<m; i++) {
			cin >> p[i];
		}
		sort(p.begin(), p.end());

		int first = p[0];
		for(int i=1; i<m; i++) {
			if(p[i]-p[i-1] > 1) {
				sort(a.begin()+first-1, a.begin()+p[i-1]+1);
				first = p[i];
			}
		}
		sort(a.begin()+first-1, a.begin()+p[m-1]+1);

		if(a == b) {
			cout << "YES" << nl;
		} else {
			cout << "NO" << nl;
		}
	}

	return 0;
}