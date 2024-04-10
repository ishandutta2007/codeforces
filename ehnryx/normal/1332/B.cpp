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

	const int M = 1000;
	vector<int> ps;
	for(int i=2; i<M && ps.size()<11; i++) {
		bool ok = true;
		for(int j=2; j<i; j++) {
			ok &= (i%j > 0);
		}
		if(ok) ps.push_back(i);
	}

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<int> ans;
		unordered_map<int,int> idx;
		int m = 0;
		for(int i=0; i<n; i++) {
			int v;
			cin >> v;
			for(int p : ps) {
				if(v % p == 0) {
					if(!idx.count(p)) idx[p] = ++m;
					ans.push_back(idx[p]);
					break;
				}
			}
		}
		cout << m << nl;
		for(int i=0; i<n; i++) {
			cout << ans[i] << " ";
		}
		cout << nl;
	}

	return 0;
}