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
const ld EPS = 1e-11;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1<<19;
int a[N], b[N];

int st[2*N], z[2*N];
void push(int i) {
	if(z[i]) {
		st[2*i] += z[i];
		st[2*i+1] += z[i];
		z[2*i] += z[i];
		z[2*i+1] += z[i];
		z[i] = 0;
	}
}
void pull(int i) {
	st[i] = max(st[2*i], st[2*i+1]);
}
void insert(int l, int r, int v, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) {
		st[i] += v;
		z[i] += v;
		return;
	}
	push(i);
	int m = (s+e)/2;
	insert(l,r,v,2*i,s,m);
	insert(l,r,v,2*i+1,m+1,e);
	pull(i);
}
int query(int l, int r, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return -INF;
	if(l<=s && e<=r) {
		return st[i];
	}
	push(i);
	int m = (s+e)/2;
	return max(query(l,r,2*i,s,m), query(l,r,2*i+1,m+1,e));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector<pair<int,int>> order;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		order.push_back(make_pair(a[i], i));
	}
	sort(order.begin(), order.end(), greater<pair<int,int>>());

	int ans = INF;
	for(int i=1, j=0; i<=n; i++) {
		cin >> b[i];
		while(query(1, n) <= 0) {
			auto [v, k] = order[j++];
			insert(1, k, 1);
			ans = v;
		}
		cout << ans << " ";
		insert(1, b[i], -1);
	}
	cout << nl;

	return 0;
}