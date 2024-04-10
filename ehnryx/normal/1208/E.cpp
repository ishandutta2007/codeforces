#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct SegTree {
	int n; int *st;
  SegTree(const vector<int>& v) {
		int len = v.size();
		n = 1<<(32-__builtin_clz(len));
    st = new int[2*n]; fill(st, st+2*n, -INF);
		for(int i=0;i<len;i++) {
			st[n+i] = v[i];
		}
		for(int i=n-1;i>0;i--) {
			st[i] = max(st[2*i], st[2*i+1]);
		}
	}
	int query(int l, int r) {
		int res = -INF;
		for(l+=n,r+=n+1;l<r;l/=2,r/=2) {
			if(l&1) res = max(res, st[l++]);
			if(r&1) res = max(res, st[--r]);
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n,m;
	cin>>n>>m;
	int k[n], maxv[n];
	vector<int> g[n];
	vector<int> le[m], re[m];
	SegTree* st[n];
	unordered_set<int> get;
	for(int i=0;i<n;i++) {
		cin>>k[i];
		maxv[i] = 0;
		for(int j=0;j<k[i];j++) {
			int v;
			cin>>v;
			g[i].push_back(v);
			maxv[i]=max(maxv[i],v);
		}
		st[i] = new SegTree(g[i]);
		if(k[i]<=m-1-k[i]) {
			le[k[i]-1].push_back(i);
			re[m-k[i]].push_back(i);
		}
		get.insert(i);
	}

	ll base = 0;
	for(int i=0;i<m;i++) {
		for(int j:le[i]) {
			get.erase(j);
			base += maxv[j];
		}
		ll cur = 0;
		for(int j:get) {
			int l = max(0,i-(m-k[j]));
			int r = min(k[j]-1,i);
			int res = st[j]->query(l,r);
			if(i-(m-k[j])<0 || i>k[j]-1) {
				res = max(res, 0);
			}
			cur += res;
		}
		cout<<base+cur<<" ";
		for(int j:re[i]) {
			get.insert(j);
			base -= maxv[j];
		}
	}
	cout<<nl;

	return 0;
}