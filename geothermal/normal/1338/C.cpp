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

    /*set<int> used;
    int curs = 1;
    vi vals;
    F0R(it, 100) {
        while (used.count(curs)) curs++;
        FOR(j, curs+1, 10000) {
            if (!used.count(j) && !used.count(curs ^ j)) {
                vals.pb(curs); vals.pb(j); vals.pb(curs ^ j);
                used.ins(curs); used.ins(j); used.ins(curs ^ j);
                break;
            }
        }
    }*/

    int T; cin >> T;
    F0R(testCase, T) {
        ll N; cin >> N;
        ll oN = N;
        ll pos = (N+2) % 3; N = (N-1)/3;
        ll cur = 1;
        ll ans = 0;
        while (cur <= N) {
            N -= cur;
            cur *= 4;
        }
        ans = cur * (pos+1);
        cur = 1;
        while (N > 0) {
            if (N % 4 != 0) {
                ll val = (pos + (N%4-1))%3 + 1;
                ans += val * cur;
            }
            cur *= 4; N /= 4;
        }

        cout << ans << nl;
    }
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343