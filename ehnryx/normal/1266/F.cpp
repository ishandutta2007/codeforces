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
int rmq[2*N], dz[2*N];
int n;

void build_st() {
	for(int i=N-1; i>0; i--) {
		rmq[i] = max(rmq[2*i], rmq[2*i+1]);
	}
}

void push(int i) {
	if(dz[i]) {
		dz[2*i] += dz[i];
		dz[2*i+1] += dz[i];
		rmq[2*i] += dz[i];
		rmq[2*i+1] += dz[i];
		dz[i] = 0;
	}
}

void update(int l, int r, int v, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) {
		dz[i] += v;
		rmq[i] += v;
		return;
	}
	push(i);
	int m = (s+e)/2;
	update(l, r, v, 2*i, s, m);
	update(l, r, v, 2*i+1, m+1, e);
	rmq[i] = max(rmq[2*i], rmq[2*i+1]);
}

void complement(int l, int r, int v) {
	assert(r<=n-1);
	if(0<l) update(0, l-1, v);
	if(r<n-1) update(r+1, n-1, v);
}

int value(int l, int r, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return 0;
	if(l<=s && e<=r) {
		return rmq[i];
	}
	push(i);
	int m = (s+e)/2;
	return max(value(l, r, 2*i, s, m), value(l, r, 2*i+1, m+1, e));
}

int value_comp(int l, int r) {
	assert(r<=n-1);
	int res = 0;
	if(0<l) res = max(res, value(0, l-1));
	if(r<n-1) res = max(res, value(r+1, n-1));
	return res;
}


vector<int> adj[N];
int sz[N], start[N];
int ans[N];
int two = 0;

int pid = 0;
int build(int u, int p, int d) {
	rmq[pid+N] = d;
	start[u] = pid++;
	sz[u] = 1;
	for(int v:adj[u]) {
		if(v==p) continue;
		sz[u] += build(v, u, d+1);
	}
	return sz[u];
}


int depth[N];
vector<int> memo[N];

void merge(vector<int>& a, vector<int>& b) {
	if(a.size() < b.size()) swap(a,b);
	for(int j=0; j<b.size(); j++) {
		a[j] = max(a[j], b[j]);
	}
}

int solve(int u, int p) {
	depth[u] = 0;
	int second = 0;
	vector<int> ds = { 0 };
	vector<int> emma = { 1 };

	for(int v:adj[u]) {
		if(v==p) continue;
		update(start[v], start[v]+sz[v]-1, -1);
		complement(start[v], start[v]+sz[v]-1, 1);
		int cur = 1 + solve(v, u);
		if(cur > depth[u]) {
			second = depth[u];
			depth[u] = cur;
		} else if(cur > second) {
			second = cur;
		}
		merge(emma, memo[v]);
		update(start[v], start[v]+sz[v]-1, 1);
		complement(start[v], start[v]+sz[v]-1, -1);
		ds.push_back(depth[v] + 1);
	}
	sort(ds.begin(), ds.end());

	memo[u].resize(second+2, 0);
	for(int i=second+1, j=ds.size(); i>=0; i--) {
		while(j > 0 && ds[j-1] >= i) {
			j--;
		}
		memo[u][i] = (int)ds.size() - j;
	}

	int maxpar = value_comp(start[u], start[u]+sz[u]-1);
	two = max(two, depth[u] + max(maxpar, second));
	for(int k=1; k/2<=second; k++) {
		int half = k/2;
		int ocnt = memo[u][half+1];
		int hcnt = memo[u][half] - memo[u][half+1];
		if(k%2) {
			int res = max(ocnt + (maxpar>=half), ocnt + (maxpar>half) + (hcnt>0));
			ans[k] = max(ans[k], res);
		} else {
			int res = hcnt+ocnt + (maxpar>=half);
			ans[k] = max(ans[k], res);
			if(half < emma.size()) {
				ans[k] = max(ans[k], hcnt+ocnt + (maxpar>=half) + emma[half]-1);
			}
		}
	}

	return depth[u];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(1, 0, 0);
	build_st();

	fill(ans, ans+N, 1);
	solve(1, 0);

	for(int i=1; i<=n; i++) {
		if(i<=two) ans[i] = max(ans[i], 2);
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}