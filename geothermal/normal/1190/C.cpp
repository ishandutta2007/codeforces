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

    int N, K; cin >> N >> K;
    string S; cin >> S;
    int lz = N, hz = 0, lo = N, ho = 0;
    F0R(i, N) {
        if (S[i] == '0') {
            ckmin(lz, i); ckmax(hz, i);
        } else {
            ckmin(lo, i); ckmax(ho, i);
        }
    }
    if (lz == N || lo == N) {
        cout << "tokitsukaze" << nl; return;
    }

    if (hz - lz < K || ho - lo < K) {
        cout << "tokitsukaze" << nl; return;
    }
    bool found = false;
    F0R(x, 2) {

        set<int> zer;
        F0R(i, N) {
            if (S[i] == '0') zer.ins(i);
        }

        F0R(i, N-K+1) {
            auto it1 = zer.lb(i);
            auto it2 = zer.lb(i+K);
            if (it1 != zer.begin() && it2 != zer.end()) {
                found = true;
            } else if (it1 != zer.begin()) {
                it1--;
                int L = *zer.begin(), R = *it1;
                if (R-L >= K) {
                    found = true;
                }
            } else if (it2 != zer.end()) {
                int L = *it2, R = *zer.rbegin();
                if (R-L >= K) {
                    found = true;
                }
            }
        }


        F0R(i, N) S[i] = '0' + '1' - S[i];
    }

    cout << (found?"once again":"quailty") << nl;

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343