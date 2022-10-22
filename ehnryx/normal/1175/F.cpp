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
vector<int> idx[N];

int st[2*N];

void insert(int x, int v, int i=1, int s=0, int e=N-1) {
	if(s==e) {
		st[i] = v;
		return;
	}
	int m = (s+e)/2;
	if(x<=m) insert(x,v,2*i,s,m);
	else insert(x,v,2*i+1,m+1,e);
	st[i] = max(st[2*i], st[2*i+1]);
}

int query(int l, int r, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l || st[i]==0) return -1;
	if(s==e) {
		return s;
	}
	int m = (s+e)/2;
	int left = query(l,r,2*i,s,m);
	if(left != -1) return left;
	int right = query(l,r,2*i+1,m+1,e);
	assert(right != -1);
	return right;
}

int rmq[2*N];
void rmq_build() {
	for(int i=N-1; i>0; i--) {
		rmq[i] = max(rmq[2*i], rmq[2*i+1]);
	}
}
int maxv(int l, int r) {
	int res = 0;
	for(l+=N, r+=N+1; l<r; l/=2, r/=2) {
		if(l&1) res = max(res, rmq[l++]);
		if(r&1) res = max(res, rmq[--r]);
	}
	return res;
}

int solve(const vector<int>& a) {
	int n = a.size();
	fill(idx, idx+N, vector<int>());
	memset(st, 0, sizeof st);

	for(int i=0; i<n; i++) {
		rmq[N+i] = a[i];
		idx[a[i]].push_back(i);
		if(idx[a[i]].size() > 1) {
			insert(i, 1);
		}
	}
	insert(n, 1);
	rmq_build();

	idx[1].push_back(n+1);
	int res = 0;
	for(int i=0; i<n; i++) {
		if(a[i] != 1) {
			int ub = query(i, n);
			int j = *upper_bound(idx[1].begin(), idx[1].end(), i);
			if(j < ub) {
				int len = maxv(i, j);
				if(j <= i+len-1 && i+len-1 < ub && maxv(i, i+len-1) == len) {
					res++;
				}
			}
		}
		auto it = upper_bound(idx[a[i]].begin(), idx[a[i]].end(), i);
		if(it != idx[a[i]].end()) {
			insert(*it, 0);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	vector<int> a(n);
	int ones = 0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		ones += (a[i] == 1);
	}

	int ans = ones;
	ans += solve(a);
	reverse(a.begin(), a.end());
	ans += solve(a);

	cout << ans << nl;

	return 0;
}