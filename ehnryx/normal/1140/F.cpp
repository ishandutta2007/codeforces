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

struct Range {
	int l, r; pii v;
	bool contains(int s, int e) const {
		return l <= s && e <= r;
	}
};

const int N = 3e5+1;
ll ans[N];

int dsu[2*N], xz[2*N], yz[2*N];
ll value;

void init_dsu() {
	value = 0;
	memset(dsu, -1, sizeof dsu);
	for(int i=0; i<N; i++) {
		xz[i] = yz[i+N] = 1;
	}
}

int find(int i) {
	if(dsu[i] == -1) return i;
	return find(dsu[i]);
}

void link(int i, int j, vector<pii>& memo) {
	i = find(i);
	j = find(j);
	if(i == j) return;
	if(xz[i]+yz[i] > xz[j]+yz[j]) swap(i,j);
	dsu[i] = j;
	value -= (ll)xz[i]*yz[i] + (ll)xz[j]*yz[j];
	xz[j] += xz[i];
	yz[j] += yz[i];
	value += (ll)xz[j]*yz[j];
	memo.push_back(pii(i,j));
}

void unlink(int i, int j) {
	value -= (ll)xz[j]*yz[j];
	xz[j] -= xz[i];
	yz[j] -= yz[i];
	value += (ll)xz[i]*yz[i] + (ll)xz[j]*yz[j];
	dsu[i] = -1;
}

void solve(int l, int r, const vector<Range>& ranges) {
	assert(l<=r);
	vector<pii> memo;
	for(const Range& it:ranges) {
		if(it.contains(l,r)) {
			link(it.v.first, it.v.second+N, memo);
		}
	}

	if(l == r) {
		ans[r] = value;
	} else {
		int m = (l+r)/2;
		vector<Range> left, right;
		for(const Range& it:ranges) {
			if(!it.contains(l,r)) {
				if(it.l <= m) left.push_back(it);
				if(it.r > m) right.push_back(it);
			}
		}
		solve(l, m, left);
		solve(m+1, r, right);
	}

	for(int i=memo.size()-1; i>=0; i--) {
		unlink(memo[i].first, memo[i].second);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	map<pii,int> cur;
	vector<Range> ranges;
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		pii v(x,y);
		if(cur.count(v)) {
			ranges.push_back({cur[v], i-1, v});
			cur.erase(v);
		} else {
			cur[v] = i;
		}
	}
	for(const auto& [v, i] : cur) {
		ranges.push_back({i, n-1, v});
	}

	init_dsu();
	solve(0, n-1, ranges);
	for(int i=0; i<n; i++) {
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}