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



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m, k;
	cin >> n >> m >> k;
	ostringstream out;
	for(int i=0; i<n; i++) {
		if(i>0) out << 'U';
		for(int j=1; j<m; j++) {
			if(i%2) out << 'R';
			else out << 'L';
		}
	}
	for(int i=n-1; i>=0; i--) {
		for(int j=1; j<m; j++) {
			if(i%2) out << 'L';
			else out << 'R';
		}
		if(i>0) out << 'D';
	}
	string s = out.str();
	cout << s.size() << nl;
	cout << s << nl;

	return 0;
}