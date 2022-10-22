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

const int N = 1<<20;
pair<ll,int> st[2*N]; ll z[2*N];
int decmp[N];

void init() {
	for(int i=0;i<N;i++) {
		st[i+N].second = i;
	}
}

void push(int i) {
	if(z[i]) {
		z[2*i] += z[i];
		z[2*i+1] += z[i];
		st[2*i].first += z[i];
		st[2*i+1].first += z[i];
		z[i] = 0;
	}
}

void pull(int i) {
	st[i] = max(st[2*i], st[2*i+1]);
}

void insert(int l, int r, ll v, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) {
		z[i] += v;
		st[i].first += v;
		return;
	}
	push(i);
	int m = (s+e)/2;
	insert(l,r,v,2*i,s,m);
	insert(l,r,v,2*i+1,m+1,e);
	pull(i);
}

pair<ll,int> query(int l, int r, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return make_pair(-INFLL,-1);
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

	init();

	int n;
	cin >> n;
	int x[n], y[n], c[n];
	map<int,int> remap;
	map<int,ll> cnt;
	map<int,vector<int>> p;
	int maxv = 0;
	for(int i=0;i<n;i++) {
		cin >> x[i] >> y[i] >> c[i];
		maxv = max(maxv, max(x[i],y[i]));
		cnt[max(x[i],y[i])] += c[i];
		p[min(x[i],y[i])].push_back(i);
		remap[x[i]]; remap[y[i]];
	}

	int id = 0;
	for(auto& it:remap) {
		//cerr<<id<<" -> " << it.first << nl;
		insert(id, id, -it.first);
		decmp[id] = it.first;
		it.second = id++;
	}

	for(const auto& it:cnt) {
		insert(remap[it.first], id-1, it.second);
	}

	ll ans = 0;
	int left = -1;
	int right = -1;
	for(const auto& it:p) {
		int lb = it.first;
		pair<ll,int> res = query(remap[lb], id-1);
		//cerr<<"@ " << lb  << " -> " << res.first << " " << res.second << nl;
		ll cur = res.first + lb;
		if(cur > ans) {
			ans = cur;
			left = lb;
			right = decmp[res.second];
		}
		for(int j:it.second) {
			int ub = max(x[j],y[j]);
			insert(remap[ub], id-1, -c[j]);
		}
	}

	assert(ans >= 0);
	assert(left <= right);

	cout << ans << nl;
	if(ans == 0) {
		int big = 1234567890;
		cout << big << " " << big << " " << big << " " << big << nl;
	} else {
		cout << left << " " << left << " " << right << " " << right << nl;
	}

	return 0;
}