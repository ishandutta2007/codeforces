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

bool valid(char C) {
    return ('a' <= C && 'z' >= C) || ('A' <= C && 'Z' >= C) || ('0' <= C && '9' >= C) || C == '_';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    string S; cin >> S;
    int ap = -1;
    F0R(i, sz(S)) {
        if (S[i] == '@') {
            if (i == 0) {
                cout << "NO" << nl; return 0;
            }
            ap = i; break;
        }
        if (!valid(S[i])) {
            cout << "NO" << nl; return 0;
        }
    }
    if (ap == -1 || ap > 16) {
        cout << "NO" << nl; return 0;
    }

    int lst = ap;
    int sp = sz(S);
    FOR(i, ap+1, sz(S)) {
        if (S[i] == '.') {
            if (i - lst > 17 || i - lst == 1) {
                cout << "NO" << nl; return 0;
            }
        }
        if (S[i] == '/') {
            sp = i;
        } else if (S[i] == '.') {
            lst = i;
        } else if (!valid(S[i])) {
            cout << "NO" << nl; return 0;
        }
    }

    if (sp - lst > 17 || sp-lst == 1) {
        cout << "NO" << nl; return 0;
    }
    if (sz(S) - sp > 17 || sz(S)-sp==1) {
        cout << "NO" << nl; return 0;
    }
    FOR(i, sp+1, sz(S)) {
        if (!valid(S[i])) {
            cout << "NO" << nl; return 0;
        }
    }
    cout << "YES" << nl; return 0;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343