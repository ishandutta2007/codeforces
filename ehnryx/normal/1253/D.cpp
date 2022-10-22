#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_cxx;
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

const int N = 2e5+1;
int r[N], rb[N];
int find(int i) {
	if(r[i]==0) return i;
	return r[i] = find(r[i]);
}
int link(int i, int j) {
	i = find(i); j = find(j);
	if(i==j) return 0;
	r[i] = j;
	return 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n,m;
	cin>>n>>m;
	int g = n;
	for(int i=0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		g -= link(a,b);
	}

	for(int i=1;i<=n;i++) {
		rb[find(i)] = max(rb[find(i)], i);
	}

	int ub = 0;
	for(int i=1;i<=n;i++) {
		if(i>ub) {
			g--;
		}
		ub = max(ub, rb[find(i)]);
	}
	cout<<g<<nl;

	return 0;
}