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

struct WaveletTree {
	int lo, hi;
	WaveletTree *left, *right;
	vector<int> b;
	template<class T> WaveletTree(T s, T e):
		WaveletTree(s, e, *min_element(s,e), *max_element(s,e)) {}
	template<class T> WaveletTree(T s, T e, int l, int r): lo(l), hi(r) {
		if (lo == hi || s == e) { left = right = nullptr; return; }
		int mid = (lo+hi)/2;
		auto f = [&](int x) { return x <= mid; };
		b.reserve(distance(s,e)+1); b.push_back(0);
		for (auto it=s; it!=e; it++) b.push_back(b.back()+f(*it));
		auto m = stable_partition(s, e, f);
		left = new WaveletTree(s, m, lo, mid);
		right = new WaveletTree(m, e, mid+1, hi);
	}

	int solve(int l, int r, int lb) {
		if(r-l+1<=lb) return INF;
		if(lo==hi) return lo;
		int res = left->solve(b[l-1]+1,b[r],lb);
		return min(res, right->solve(l-b[l-1],r-b[r],lb));
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	WaveletTree wt(a,a+n);

	for(int i=0;i<m;i++) {
		int l,r,k;
		cin>>l>>r>>k;
		int ans = wt.solve(l,r,(r-l+1)/k);
		if(ans==INF) cout<<-1<<nl;
		else cout<<ans<<nl;
	}

	return 0;
}