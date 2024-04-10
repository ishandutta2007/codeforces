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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int Te; cin >> Te;
    while(Te--) {
        int N; cin >> N;
        vi facs;
        vi pf;
        int tn = N;
        FOR(i, 2, 100000) {
            if (i*i > N) break;
            if (N % i == 0) {
                facs.pb(i);
                if (tn % i == 0) {
                    pf.pb(i); 
                    while (tn % i == 0) tn /= i;
                }
                if (N/i > i) facs.pb(N/i);
            }
        }
        if (tn > 1) pf.pb(tn);
        facs.pb(N);
        sort(all(pf));
        sort(all(facs));
        map<int, set<int> > rep;
        trav(a, facs) {
            trav(b, pf) {
                if (a % b == 0) {
                    rep[b].ins(a);
                    break;
                }
            }
        }
        if (sz(pf) == 1) {
            F0R(i, sz(facs)) {
                cout << facs[i] << " ";
            }
            cout << nl;
            cout << "0\n";
            continue;
        }
        F0R(i, sz(facs)) {
            if (facs[i] % pf[0] == 0 && facs[i] % pf[sz(pf) - 1] == 0 && facs[i] != pf[0] * pf[sz(pf) - 1]) {
                cout << facs[i] << " ";
                rep[pf[0]].erase(facs[i]);
                break;
            }
        }
        F0R(i, sz(pf)) {
            int val = -1;
            if (i != sz(pf) - 1) {
                val = pf[i] * pf[i+1];
                rep[pf[i]].erase(val);
            }
            trav(a, rep[pf[i]]) cout << a << " ";
            if (val != -1) cout << val << " ";
        }

        cout << nl;
        if (N == pf[0] * pf[1]) {
            cout << 1 << nl;
        } else {
            cout << 0 << nl;
        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343