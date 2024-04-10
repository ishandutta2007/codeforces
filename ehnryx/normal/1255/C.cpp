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

	int n;
	cin >> n;

	set<int> range[n];
	set<int> idx[n+1];
	for(int i=2;i<n;i++) {
		for(int j=0;j<3;j++) {
			int v;
			cin >> v;
			range[i].insert(v);
			idx[v].insert(i);
		}
	}

	vector<int> ends;
	int other = -1;
	for(int i=1;i<=n;i++) {
		if(idx[i].size() == 1) {
			ends.push_back(i);
		}
	}
	int last = *idx[ends.back()].begin();
	for(int i=1;i<=n;i++) {
		if(idx[i].size()<3 && range[last].count(i)) {
			if(i!=ends.back()) other = i;
			for(int j=0;j<7;j++) {
				idx[i].insert(INF+j);
			}
		}
	}
	assert(ends.size() == 2 && other != -1);

	vector<int> ans;
	for(int v=ends.front(); !idx[v].empty(); ) {
		assert(idx[v].size() == 1);
		ans.push_back(v);
		int i = *idx[v].begin();
		for(int x:range[i]) {
			assert(idx[x].count(i));
			idx[x].erase(i);
			if(idx[x].size() == 1) {
				v = x;
			}
		}
	}
	ans.push_back(other);
	ans.push_back(ends.back());

	for(int it:ans) {
		cout<<it<<" ";
	}
	cout<<nl;

	return 0;
}