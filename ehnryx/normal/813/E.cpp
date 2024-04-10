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

const int N = 1<<17;
int a[N];
vector<int> idx[N];

vector<int> st[2*N];
int query(int l, int r, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return 0;
	if(l<=s && e<=r) {
		return lower_bound(st[i].begin(), st[i].end(), l) - st[i].begin();
	}
	int m = (s+e) / 2;
	return query(l, r, 2*i, s, m) + query(l, r, 2*i+1, m+1, e);
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		idx[a[i]].push_back(i);
	}

	for(int i=1; i<=n; i++) {
		if(idx[a[i]].front() != i) continue;
		for(int j=0; j<idx[a[i]].size(); j++) {
			st[N + idx[a[i]][j]].push_back(j<k ? -1 : idx[a[i]][j-k]);
		}
	}

	for(int i=N-1; i>0; i--) {
		st[i] = st[2*i];
		st[i].insert(st[i].end(), st[2*i+1].begin(), st[2*i+1].end());
		sort(st[i].begin(), st[i].end());
	}

	int m;
	cin >> m;
	int last = 0;
	for(int i=0; i<m; i++) {
		int l, r;
		cin >> l >> r;
		l = (l + last) % n + 1;
		r = (r + last) % n + 1;
		if(l > r) swap(l, r);
		last = query(l, r);
		cout << last << nl;
	}

	return 0;
}