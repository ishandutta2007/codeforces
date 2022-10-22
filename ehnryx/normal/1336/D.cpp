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

unordered_map<int,int> ans;

int T, S;

pair<int,int> query(int i) {
	cout << "+ " << i << endl;
	int t, s;
	cin >> t >> s;
	int dt = t - T;
	int ds = s - S;
	T = t;
	S = s;
	return make_pair(dt, ds);
}

void answer(int n) {
	cout << "! ";
	for(int i=1; i<=n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int untriple(int x) {
	for(int v=2; (v-1)*(v-2)/2<=x; v++) {
		if((v-1)*(v-2)/2 == x) {
			return v;
		}
	}
	assert(false);
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n >> T >> S;

	vector<int> t(n), s(n);
	tie(t[0], s[0]) = query(1);
	tie(t[1], s[1]) = query(2);
	tie(t[2], s[2]) = query(3);
	tie(t[3], s[3]) = query(1);

	ans[1] = untriple(t[3]) - 2;
	ans[3] = (s[1] ? untriple(t[2]) - 1 : 0);
	ans[2] = s[3] / (ans[3]+1) - 1;
	s[2] -= (ans[1]+1) * (ans[2]+1);
	swap(s[2], s[3]);

	for(int i=4; i<n; i++) {
		tie(t[i], s[i]) = query(i);
		ans[i] = (s[i-1] ? untriple(t[i]) - 1 : 0);
		s[i] -= (ans[i-1]+1) * (ans[i-2]+1);
	}
	ans[n] = s[n-1] / (ans[n-2]+1);

	answer(n);

	return 0;
}