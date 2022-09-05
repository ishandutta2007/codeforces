#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int maxVal = 1000000001; //check the limits, dummy
const int MX = 262144;
 
pair<pi, pi> intersect(pair<pi, pi> a, pair<pi, pi> b) {
	pair<pi, pi> ans = {{max(a.f.f, b.f.f), max(a.f.s, b.f.s)}, {min(a.s.f, b.s.f), min(a.s.s, b.s.s)}};
	
	if (ans.f.f > ans.s.f || ans.f.s > ans.s.s) {
		ans = {{maxVal, maxVal}, {maxVal, maxVal}};
	}
	return ans;
}

ll SZ = 262144;
pair<pi, pi>* seg = new pair<pi, pi>[2*SZ]; //segtree implementation by bqi343's Github


pair<pi, pi> combine(pair<pi, pi> a, pair<pi, pi> b) { return intersect(a, b); }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, pair<pi, pi> value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

pair<pi, pi> query(int l, int r) {  // sum on interval [l, r]
    pair<pi, pi> resL = {{-1000000000, -1000000000}, {1000000000, 1000000000}}, resR = {{-1000000000, -1000000000}, {1000000000, 1000000000}}; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	vector<pair<pi, pi> > data(MX);
	int N; cin >> N;
	
	F0R(i, MX) {
		data[i] = {{-1000000000, -1000000000}, {1000000000, 1000000000}};
	}
	
	F0R(i, 2*SZ) {
		seg[i]  = {{-1000000000, -1000000000}, {1000000000, 1000000000}};
	}
	
	F0R(i, N) {
		int A, B, C, D; cin >> A >> B >> C >> D;
		update(i, {{A, B}, {C, D}});
	}
	
	F0R(i, N) {
		pair<pi, pi> ans = {{-1000000000, -1000000000}, {1000000000, 1000000000}};
		if (i > 0) ans = intersect(ans, query(0, i-1));
		ans = intersect(ans, query(i+1, SZ-1));
		
		if (ans.f.f != maxVal) {
			cout << ans.f.f << " " << ans.f.s << endl;
			return 0;
		} 
	}
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343