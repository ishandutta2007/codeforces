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
        map<char, pi> dir;
        dir.ins({'S', {1, 0}});
        dir.ins({'N', {-1, 0}});
        dir.ins({'E', {0, 1}});
        dir.ins({'W', {0, -1}});
        string S; cin >> S;
        set<pair<pi, bool> > used;
        int ans = 0;
        int x = 0, y = 0;
        F0R(i, sz(S)) {
            pi d = dir[S[i]];
            int nx = x+d.f, ny = y + d.s;
            int rx = min(x, nx), ry = min(ny, y);
            bool val = x == nx;
            if (used.count({{rx, ry}, val})) {
                ans++;
            } else ans += 5;
            x = nx; y = ny;
            used.ins({{rx, ry}, val});
        }
        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343