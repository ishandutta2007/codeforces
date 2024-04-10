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
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1<<17;
vector<pair<int,int>> add[2*N];
int ans[N];

void add_range(int l, int r, pair<int,int> v, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) {
		add[i].push_back(v);
		return;
	}
	int m = (s+e) / 2;
	add_range(l, r, v, 2*i, s, m);
	add_range(l, r, v, 2*i+1, m+1, e);
}

int dsu[N], sz[N], dist[N];

pair<int,int> find(int i) {
	if(dsu[i] == 0) return make_pair(i, 0);
	auto [r, d] = find(dsu[i]);
	return make_pair(r, dist[i] + d);
}

bool link(int i, int j, vector<pair<int,int>>& memo) {
	int di, dj;
	tie(i, di) = find(i);
	tie(j, dj) = find(j);
	if(i == j) return (di + dj) % 2 == 1;
	if(sz[i] > sz[j]) swap(i, j);
	memo.emplace_back(i, j);
	dsu[i] = j;
	dist[i] = di + dj + 1;
	sz[j] += sz[i] + 1;
	return true;
}

void unlink(int i, int j) {
	dsu[i] = 0;
	sz[j] -= sz[i] + 1;
}

void solve(int l, int r, bool cur, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return;

	vector<pair<int,int>> memo;
	for(auto [a, b] : add[i]) {
		cur &= link(a, b, memo);
	}

	if(s == e) {
		ans[s] = cur;
	} else {
		int m = (s+e) / 2;
		solve(l, r, cur, 2*i, s, m);
		solve(l, r, cur, 2*i+1, m+1, e);
	}

	reverse(memo.begin(), memo.end());
	for(auto [a, b] : memo) {
		unlink(a, b);
	}
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	map<pair<int,int>,vector<int>> edges;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		edges[make_pair(a, b)].push_back(i);
	}

	for(auto& [e, it] : edges) {
		sort(it.begin(), it.end());
		int pre = -1;
		for(int i : it) {
			if(pre != -1) {
				add_range(pre, i-1, e);
				pre = -1;
			} else {
				pre = i;
			}
		}
		if(pre != -1) {
			add_range(pre, m-1, e);
		}
	}
	solve(0, m-1, true);

	for(int i=0; i<m; i++) {
		cout << (ans[i] ? "YES" : "NO") << nl;
	}

	return 0;
}