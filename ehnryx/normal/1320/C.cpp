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

const int N = 1 << 18;
ll st[2*N], z[2*N];

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

void insert(int l, int r, ll v, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) {
		st[i] += v;
		z[i] += v;
		return;
	}
	push(i);
	int m = (s+e)/2;
	insert(l, r, v, 2*i, s, m);
	insert(l, r, v, 2*i+1, m+1, e);
	pull(i);
}

ll query(int l, int r, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return -INFLL;
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

	int n, m, k;
	cin >> n >> m >> k;
	vector<tuple<int,int,int>> event;
	vector<pair<int,int>> horiz;
	for(int i=0; i<n; i++) {
		int a, c;
		cin >> a >> c;
		event.push_back(make_tuple(a, 0, c));
	}
	for(int i=0; i<m; i++) {
		int b, c;
		cin >> b >> c;
		horiz.push_back(make_pair(b, c));
	}
	for(int i=0; i<k; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		event.push_back(make_tuple(x, y, c));
	}
	sort(event.begin(), event.end());
	sort(horiz.begin(), horiz.end());

	for(int i=0; i<m; i++) {
		insert(i, i, -horiz[i].second);
	}

	ll ans = -INFLL;
	for(const auto& [_, b, c] : event) {
		if(b == 0) {
			ans = max(ans, query(0, m-1) - c);
		} else {
			int s = lower_bound(horiz.begin(), horiz.end(), make_pair(b+1, 0)) - horiz.begin();
			if(s < m) insert(s, m-1, c);
		}
	}
	cout << ans << nl;

	return 0;
}