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

const int N = 1 << 21;
int a[N], o[N], idx[N];

bool valid(int n, int m, int i) {
	int l = 2*i;
	int r = 2*i+1;
	if(!a[l] && !a[r]) {
		return i >= m;
	} else if(a[l] > a[r]) {
		return valid(n, m, l);
	} else {
		return valid(n, m, r);
	}
}

void remove(int n, int m, int i) {
	int l = 2*i;
	int r = 2*i+1;
	if(!a[l] && !a[r]) {
		a[i] = 0;
	} else if(a[l] > a[r]) {
		a[i] = a[l];
		idx[a[i]] = i;
		remove(n, m, l);
	} else {
		a[i] = a[r];
		idx[a[i]] = i;
		remove(n, m, r);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int h, g;
		cin >> h >> g;
		int n = 1<<h;
		int m = 1<<g;
		fill(a, a+2*n, 0);
		ll sum = 0;
		for(int i=1; i<n; i++) {
			cin >> a[i];
			o[i] = a[i];
			sum += a[i];
		}
		sort(o+1, o+n, greater<int>());
		for(int i=1; i<n; i++) {
			idx[a[i]] = i;
		}
		vector<int> ans;
		for(int i=1; i<n; i++) {
			if(valid(n, m, idx[o[i]])) {
				remove(n, m, idx[o[i]]);
				ans.push_back(idx[o[i]]);
				sum -= o[i];
			}
		}
		cout << sum << nl;
		for(int it : ans) {
			cout << it << " ";
		}
		cout << nl;
	}

	return 0;
}