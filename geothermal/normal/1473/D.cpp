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
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy



void solve() {

    int N, M; cin >> N >> M;
    string S; cin >> S;
    int pref[N+1];
    pref[0] = 0;
    F0R(i, N) {
        pref[i+1] = pref[i];
        if (S[i] == '+') {
            pref[i+1]++; 
        } else pref[i+1]--;
    }

    int maxPref[N+1];
    maxPref[0] = 0;
    F0R(i, N) {
        maxPref[i+1] = max(maxPref[i], pref[i+1]);
    }
    int maxEnd[N+1];
    maxEnd[0] = 0;
    F0R(i, N) {
        maxEnd[i+1] = maxEnd[i];
        if (S[i] == '+') {
            maxEnd[i+1]++;
        } else {
            maxEnd[i+1]--; ckmax(maxEnd[i+1], 0);
        }
    }

    int suff[N+1];
    suff[N] = 0;
    F0Rd(i, N) {
        suff[i] = suff[i+1];
        if (S[i] == '+') {
            suff[i]++;
        } else {
            suff[i]--;
        }
    }

    int maxSuff[N+1]; maxSuff[N] = 0;
    F0Rd(i, N) {
        maxSuff[i] = max(maxSuff[i+1], suff[i]);
    }

    int maxStart[N+1];
    maxStart[N] = 0;
    F0Rd(i, N) {
        maxStart[i] = maxStart[i+1];
        if (S[i] == '+') {
            maxStart[i]++;
        } else {
            maxStart[i]--; ckmax(maxStart[i], 0);
        }
    }

    int minEnd[N+1]; minEnd[0] = 0;
    F0R(i, N) {
        minEnd[i+1] = minEnd[i];
        if (S[i] == '+') {
            minEnd[i+1]++; ckmin(minEnd[i+1], 0);
        } else {
            minEnd[i+1]--;
        }
    }

    int minPref[N+1]; minPref[0] = 0;
    F0R(i, N) {
        minPref[i+1] = minPref[i];
        ckmin(minPref[i+1], pref[i+1]);
    }

    int minStart[N+1]; minStart[N] = 0;
    F0Rd(i, N) {
        minStart[i] = minStart[i+1];
        if (S[i] == '+') {
            minStart[i]++; ckmin(minStart[i], 0);
        } else {
            minStart[i]--;
        }
    }

    int minSuff[N+1]; minSuff[N] = 0;
    F0Rd(i, N) {
        minSuff[i] = min(minSuff[i+1], suff[i]);
    }

    while(M--) {
        int L, R; cin >> L >> R;
        L--; R++;
        int hi = maxPref[L];
        ckmax(hi, pref[L] + maxStart[R-1]);
        int lo = minPref[L];
        ckmin(lo, pref[L] + minStart[R-1]);
        cout << hi-lo+1 << nl;
    }

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343