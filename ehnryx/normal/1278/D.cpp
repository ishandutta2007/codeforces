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
vector<int> st[2*N];

int dsu[N];
int find(int i) {
	if(dsu[i]==-1) return i;
	return dsu[i] = find(dsu[i]);
}
void link(int i, int j) {
	if(find(i)!=find(j)) dsu[find(i)] = find(j);
}

void build() {
	for(int i=N-1; i>0; i--) {
		st[i] = st[2*i];
		for(int j:st[2*i+1]) st[i].push_back(j);
		sort(st[i].begin(), st[i].end());
	}
}

void count(int i, int v, int& tot) {
	for(int j=(int)st[i].size()-1; tot>=0 && j>=0 && st[i][j]>v; j--) {
		link(v, st[i][j]);
		tot--;
	}
}

void query(int l, int r, int v, int& tot) {
	for(l+=N, r+=N; tot>=0 && l<r; l/=2, r/=2) {
		if(l&1) count(l++, v, tot);
		if(r&1) count(--r, v, tot);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	int l[n], r[n];
	for(int i=0; i<n; i++) {
		cin >> l[i] >> r[i];
		st[N+l[i]].push_back(r[i]);
	}
	build();

	memset(dsu,-1,sizeof dsu);
	int res = n-1;
	for(int i=0; i<n; i++) {
		query(l[i],r[i],r[i],res);
	}
	int roots = 0;
	for(int i=0; i<n; i++) {
		roots += (find(r[i]) == r[i]);
	}
	if(res==0 && roots==1) {
		cout << "YES" << nl;
	} else {
		cout << "NO" << nl;
	}

	return 0;
}