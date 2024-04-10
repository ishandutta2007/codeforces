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
typedef double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e6 + 1;
ld ans[N];

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		int v;
		cin >> v;
		ans[i] = v;
	}

	stack<pair<int,int>> stk;
	stk.push(make_pair(0, 1));
	for(int i=1; i<=n; i++) {
		int cl = i;
		int cr = i+1;
		auto [l, r] = stk.top();
		while(ans[cl] <= ans[l]) {
			ld avg = ((ld)(r-l)*ans[l] + (ld)(cr-cl)*ans[cl]) / (cr-l);
			ans[l] = avg;
			cl = l;
			stk.pop();
			assert(!stk.empty());
			tie(l, r) = stk.top();
		}
		stk.push(make_pair(cl, cr));
	}

	while(!stk.empty()) {
		auto [l, r] = stk.top();
		stk.pop();
		for(int i=l+1; i<r; i++) {
			ans[i] = ans[l];
		}
	}

	for(int i=1; i<=n; i++) {
		cout << ans[i] << nl;
	}

	return 0;
}