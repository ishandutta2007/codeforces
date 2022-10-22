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
	string s;
	cin >> s;
	int bcnt = 0;
	int wcnt = 0;
	for (char c : s) {
		bcnt += (c == 'B');
		wcnt += (c == 'W');
	}

	if(wcnt % 2 == n % 2) {
		for (char& c : s) {
			c = (c == 'B' ? 'W' : 'B');
		}
		swap(wcnt, bcnt);
	}

	if(bcnt % 2 != n % 2) {
		cout << -1 << nl;
		return 0;
	}

	vector<int> ans;
	for(int i=1; i<n; i++) {
		if(s[i-1] != 'B') {
			ans.push_back(i);
			s[i-1] = (s[i-1] == 'B' ? 'W' : 'B');
			s[i] = (s[i] == 'B' ? 'W' : 'B');
		}
	}
	for(int i=n-1; i>0; i--) {
		if(s[i] != 'B') {
			ans.push_back(i);
			s[i] = (s[i] == 'B' ? 'W' : 'B');
			s[i-1] = (s[i-1] == 'B' ? 'W' : 'B');
		}
	}

	cout << ans.size() << nl;
	for(int it : ans) {
		cout << it << " ";
	}
	cout << nl;

	return 0;
}