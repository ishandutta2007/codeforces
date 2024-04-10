#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        if (N < 4) {
            cout << -1 << nl; continue;
        }
        vi ans;
        F0R(i, (N-4)/4) {
            ans.pb(i*4+2); ans.pb(i*4+4); ans.pb(i*4+1); ans.pb(i*4+3);
        }
        int s = (N-4)/4; s *= 4;
        vector<vi> ends;
        ends.pb({2, 4, 1, 3});
        ends.pb({2, 4, 1, 3, 5});
        ends.pb({1, 4, 2, 6, 3, 5});
        ends.pb({1, 5, 3, 6, 2, 4, 7});
        vi use = ends[N%4];
        F0R(i, sz(use)) {
            ans.pb(s+use[i]);
        }
        F0R(i, N) {
            cout << ans[i] << " ";
        }
        cout << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343