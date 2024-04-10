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
#define shandom_ruffle random_shuffle

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 200010; //check the limits, dummy

pi merge(pi A, pi B) {
	if (A == mp(-1, -1)) return B;
	if (B == mp(-1, -1)) return A;
	
	return mp(min(A.f, B.f), max(A.s, B.s));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
	int N, M; cin >> N >> M;
	
	int data[M]; F0R(i, M) cin >> data[i];
	F0R(i, M) data[i]--;
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}
	pi vals[MX];
	int basis = MX-N;
	ll ans = 0;
	
	F0R(i, MX) vals[i] = {-1, -1};
	F0R(i, N) vals[basis+i] = mp(i, i);
	
	F0R(i, M) {
		int pos = data[i] + basis - i - 1;
		vals[pos-1] = merge(vals[pos-1], vals[pos]);
		vals[pos] = mp(-1, -1);
	}
	
	pi ranges[N]; F0R(i, N) ranges[i] = {-1, -1};
	
	F0R(i, MX) {
		ll lo = max(0, i-basis);
		ll hi = min(N-1, i-basis+M+1);
		if (vals[i] != mp(-1, -1) && lo <= hi) {
			FOR(j, vals[i].f, vals[i].s+1) {
				ranges[j] = {max(lo, (ll) j), hi};
			}
		}
		//ll total = hi-lo+1;
		//if (total > 0) ans += total * vals[i];
		//if (vals[i] > 0) {
			//cout << lo << " " << hi << " " << vals[i] << " " << i-basis << " hi" << endl;
		//}
		//if (lo <= data[M-1] && hi >= data[M-1]) ans -= vals[i];
		
	}
	
	F0R(i, MX) vals[i] = {-1, -1};
	F0R(i, N) vals[i] = {i, i};
	
	F0R(i, M) {
		int pos = data[i] + i + 1;
		vals[pos+1] = merge(vals[pos+1], vals[pos]);
		vals[pos] = mp(-1, -1);
	}
	
	F0R(i, MX) {
		int lo = max(0, i-M-1);
		int hi = min(N-1, i);
		if (vals[i] != mp(-1, -1) && lo <= hi) {
			FOR(j, vals[i].f, vals[i].s+1) {
				ranges[j] = merge(ranges[j], {lo, min(hi, j)});
			}
		}
		/*ll total = hi-lo+1;
		if (total > 0) ans += total * vals[i];
		if (vals[i] > 0) {
			cout << lo << " " << hi << " " << vals[i] << " " << i << " lo" << endl;
		}*/
		//if (lo <= data[M-1] && hi >= data[M-1]) ans -= vals[i];
	}
	
	
	F0R(i, N) {
		if (ranges[i].s >= ranges[i].f) ans += (ll) (ranges[i].s - ranges[i].f + 1);
		//cout << ranges[i].f << " " << ranges[i].s << endl;
	}
	
	cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE