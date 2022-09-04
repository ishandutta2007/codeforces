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

    int A, B; cin >> A >> B;
    string S; cin >> S;
    int N = A+B;
    F0R(i, N/2) {
        if (S[i] == '0' || S[N-i-1] == '0') {
            if (S[N-i-1] == '1' || S[i] == '1') {
                cout << -1 << nl; return;
            } 
            S[i] = '0';
            S[N-i-1] = '0';
            A -= 2;
        } else if (S[i] == '1' || S[N-i-1] == '1') {
            S[i] = '1';
            S[N-i-1] = '1';
            B -= 2;
        } 
    }

    if (N%2) {
        if (S[N/2] == '0') {
            A--;
        } else if (S[N/2] == '1') {
            B--;
        }
    }
    if (A < 0 || B < 0) {
        cout << -1 << nl; return;
    }
    F0R(i, N/2) {
        if (S[i] == '?') {
            if (A >= 2) {
                S[i] = '0'; S[N-i-1] = '0'; A -= 2;
            } else if (B >= 2) {
                S[i] = '1'; S[N-i-1] = '1'; B -= 2;
            } else {
                cout << -1 << nl; return;
            }
        }
    }

    if (N%2) {
        if (S[N/2] == '?') {
            if (A > 0) {
                A--; S[N/2] = '0';
            } else {
                B--; S[N/2] = '1';
            }
        }
    }
    if (A != 0 || B != 0) {
        cout << -1 << nl; return;
    }
    cout << S << nl;



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