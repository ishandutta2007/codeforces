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

const int N = 1<<19;
int a[N], ans[N];
ll ldp[N], rdp[N];

int st[2*N];
void push(int i) {
	if(st[i] != -1) {
		st[2*i] = st[2*i+1] = st[i];
		st[i] = -1;
	}
}
void insert(int l, int r, int v, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) {
		st[i] = v;
		return;
	}
	push(i);
	int m = (s+e)/2;
	insert(l, r, v, 2*i, s, m);
	insert(l, r, v, 2*i+1, m+1, e);
}
int query(int x, int i=1, int s=0, int e=N-1) {
	if(st[i] != -1) return st[i];
	int m = (s+e)/2;
	if(x <= m) return query(x, 2*i, s, m);
	else return query(x, 2*i+1, m+1, e);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	map<int,int> rmp;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		rmp[a[i]];
	}
	int id = 0;
	for(auto& it : rmp) {
		it.second = ++id;
	}

	memset(st, -1, sizeof st);
	insert(0, id+1, 0);
	for(int i=1; i<=n; i++) {
		int j = query(rmp[a[i]]);
		ldp[i] = ldp[j] + (i-j) * (ll)a[i];
		insert(rmp[a[i]], id+1, i);
	}

	memset(st, -1, sizeof st);
	insert(0, id+1, n+1);
	for(int i=n; i>0; i--) {
		int j = query(rmp[a[i]]);
		rdp[i] = rdp[j] + (j-i) * (ll)a[i];
		insert(rmp[a[i]], id+1, i);
	}

	int best = 1;
	for(int i=1; i<=n; i++) {
		if(ldp[i] + rdp[i] - a[i] > ldp[best] + rdp[best] - a[best]) {
			best = i;
		}
	}

	for(int i=best, val=a[best]; i>0; i--) {
		val = min(val, a[i]);
		ans[i] = val;
	}
	for(int i=best, val=a[best]; i<=n; i++) {
		val = min(val, a[i]);
		ans[i] = val;
	}
	for(int i=1; i<=n; i++) {
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}