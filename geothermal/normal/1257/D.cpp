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
const int MX = 100001; //check the limits, dummy

ll SZ = 262144;
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github


ll combine(ll a, ll b) { return max(a, b); }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 0, resR = 0; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	int T; cin >> T;
	F0R(testCase, T) {
		int N; cin >> N;
		int monsters[N]; F0R(i, N) cin >> monsters[i];
		F0R(i, N) update(i, monsters[i]);
		int M; cin >> M;
		int powers[M], endurance[M];
		int maxOver[N+1]; F0R(i, N+1) maxOver[i] = -1;
		F0R(i, M) {
			cin >> powers[i] >> endurance[i];
			maxOver[endurance[i]] = max(maxOver[endurance[i]], powers[i]);
		}
		
		
		F0Rd(i, N) {
			maxOver[i] = max(maxOver[i], maxOver[i+1]);
		}
		
		int nxt = 0;
		int ans = 0;
		while (nxt < N) {
			ans++;
			int lo = 0;
			int hi = N-nxt;
			if (monsters[nxt] > maxOver[0]) {
				cout << -1 << endl; goto done;
			}
			
			F0R(i, 20) {
				int mid = (lo+hi)/2;
				int biggestMonster = query(nxt, nxt+mid-1);
				if (biggestMonster > maxOver[mid]) {
					hi = mid-1;
				} else {
					lo = mid;
				}
			}
			
			
			int mid = max(lo, hi);
			int res = min(lo, hi);
			
			int biggestMonster = query(nxt, nxt+mid-1);
			if (biggestMonster <= maxOver[mid]) {
				res = max(lo, hi);
			}
			

			nxt += res;
		}
		
		cout << ans << endl;
		done:;
		
		
		F0R(i, N) update(i, 0);
		
		
	}
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343