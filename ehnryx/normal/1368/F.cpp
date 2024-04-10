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

const int N = 1000 + 7;
bool on[N];

vector<int> query(int n, const vector<int>& v) {
	cout << v.size() << " ";
	for(int it : v) {
		on[it-1] = true;
		cout << it << " ";
	}
	cout << endl;
	int x;
	cin >> x;
	assert(x != -1);
	vector<int> rem;
	for(int j=0; j<v.size(); j++) {
		int i = (x-1 + j) % n;
		if(on[i]) {
			rem.push_back(i + 1);
			on[i] = false;
		}
	}
	return rem;
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	int h = floor(sqrt(n));
	vector<int> want;
	for(int i=1; i<=n; i++) {
		if(i%h == 0) continue;
		want.push_back(i);
	}
	assert(h <= want.size() || want.empty());

	vector<int> rem;
	int m = want.size();
	for(int i=0; i<m; i++) {
		vector<int> cur = rem;
		set<int> have(cur.begin(), cur.end());
		for(int j=i; cur.size()<h; j=(j+1)%m) {
			if(have.count(want[j])) continue;
			cur.push_back(want[j]);
		}
		rem = query(n, cur);
	}

	cout << 0 << endl;

	return 0;
}