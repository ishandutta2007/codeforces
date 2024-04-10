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

	int n, m;
	cin >> n >> m;
	set<int> on[2];
	int bad = 0;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		--a;
		if(on[a].count(b)) {
			for(int j=b-1; j<=b+1; j++) {
				if(on[a^1].count(j)) bad--;
			}
			on[a].erase(b);
		} else {
			on[a].insert(b);
			for(int j=b-1; j<=b+1; j++) {
				if(on[a^1].count(j)) bad++;
			}
		}
		if(bad) {
			cout << "No" << nl;
		} else {
			cout << "Yes" << nl;
		}
	}

	return 0;
}