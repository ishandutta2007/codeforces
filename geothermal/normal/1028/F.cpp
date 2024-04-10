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
const int MX = 112910; //check the limits, dummy

ll getLong(pl X) {
	return X.f*MX+X.s;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	int Q; cin >> Q;
	
	unordered_map<ll, set<pl> , custom_hash> points;
	
	unordered_map<ll, ll, custom_hash> counts;
	int N = 0;
	
	F0R(i, Q) {
		int T; ll X, Y; cin >> T >> X >> Y;
		
		if (T == 3) {
			int ans = N;
			if (counts.count(getLong(mp(X/__gcd(X, Y), Y/__gcd(X, Y))))) ans -= counts[getLong(mp(X/__gcd(X, Y), Y/__gcd(X, Y)))];
			cout << ans << endl;
		} else if (T == 1) {
			ll val = X*X+Y*Y;
			
			points[val].insert(mp(X, Y));
			
			for (auto it = points[val].begin(); it != points[val].end(); it++) {
				pl cur = *it;
				pl res = {cur.f+X, cur.s+Y};
				ll G = __gcd(res.f, res.s);
				res.f /= G; res.s /= G;
				if (!counts.count(getLong(res))) counts.insert(mp(getLong(res), 0));
				counts[getLong(res)]++;
				if (cur != mp(X, Y)) counts[getLong(res)]++;
			}
			
			
			N++;
		} else {
			ll val = X*X+Y*Y;
			
			
			
			for (auto it = points[val].begin(); it != points[val].end(); it++) {
				pl cur = *it;
				pl res = {cur.f+X, cur.s+Y};
				ll G = __gcd(res.f, res.s);
				res.f /= G; res.s /= G;
				counts[getLong(res)]--;
				if (cur != mp(X, Y)) counts[getLong(res)]--;
			}
			points[val].erase(mp(X, Y));
			N--;
			
			
		}
	}
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343