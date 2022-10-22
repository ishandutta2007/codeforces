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

const int N = 3e5+1;
int lb[N], ub[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	int idx[n+1];
	ordered_set<int> ord;
	for(int i=1; i<=n; i++) {
		lb[i] = i;
		idx[i] = i;
		ord.insert(i);
	}

	int cid = 0;
	for(int i=0; i<m; i++) {
		int v;
		cin >> v;
		int j = idx[v];
		int k = ord.order_of_key(j);
		ub[v] = max(ub[v], k+1);
		ord.erase(j);
		idx[v] = cid--;
		ord.insert(idx[v]);
		lb[v] = 1;
	}

	for(int i=1; i<=n; i++) {
		ub[i] = max(ub[i], (int)ord.order_of_key(idx[i]) + 1);
		cout << lb[i] << " " << ub[i] << nl;
	}

	return 0;
}