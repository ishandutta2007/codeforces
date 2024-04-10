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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int X, Y; cin >> X >> Y;
        string S; cin >> S;
        vi A;
        int cur = 0;
        F0R(i, sz(S)) {
            if (S[i] == 'X') {
                if (cur > 0) A.pb(cur);
                cur = 0;
            } else cur++;
        }
        if (cur > 0) A.pb(cur);
        sort(all(A));
        reverse(all(A));
        //lose if: B zone exists, B zone can be created, or no move possible

        int cp = 0; F0R(i, sz(A)) if (A[i] >= X) cp++;
        int cg = 0; bool good[sz(A)]; 
        F0R(i, sz(A)) {
            good[i] = (A[i] < X && A[i] >= Y) || (A[i] >= 2*Y);
            if (good[i]) cg++;
        }

        F0R(i, sz(A)) {
            F0R(j, A[i] - X + 1) {
                int curp = cp-1;
                int curg = cg; if (good[i]) curg--;
                int k = A[i] - X - j;
                if (j >= X) {
                    curp++;
                }
                if (k >= X) {
                    curp++;
                }
                if ((j < X && j >= Y) || j >= 2*Y) curg++;
                if ((k < X && k >= Y) || k >= 2*Y) curg++;

                if (curg == 0 && curp % 2 == 0) {
                    cout << "YES" << nl; goto done;
                }
            }
        }
        cout << "NO" << nl; 

        done:
        ;



/*        if (A[0] < X) {
            cout << "NO" << nl; continue;
        }

        bool found = false;
        bool ok[sz(S) + 1]; F0R(i, sz(S) + 1) ok[i] = false;

        FOR(i, X, 2*Y+X-1) {
            if (i > sz(S)) break;
            ok[i] = true;
        }
        FOR(i, 2*X, 3*Y+X-1) {
            if (i > sz(S)) break;
            ok[i] = true;
        }
        FOR(i, 3*X, 4*Y+X-1) {
            if (i > sz(S)) break;
            ok[i] = true;
        }
        bool foundPos = false;
        FOR(i, 0, sz(A)) {
            if (A[i] < X && A[i] >= Y) {
                if (found || !ok[A[i]]) {
                    cout << "NO" << nl; goto done;
                }
                found = true;
            } else if (A[i] >= 2*Y) {
                if (found || !ok[A[i]]) {
                    cout << "NO" << nl; goto done;
                }
                found = true;
            }
            if (ok[A[i]]) foundPos = true;
        }
        if (!foundPos) {
            cout << "NO" << nl;
        } else {
            cout << "YES" << nl;
        }
        done:
        ;*/
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343