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

int query(vi& A, vi& B) {
    cout << "? " << sz(A) << " " << sz(B) << endl;
    F0R(i, sz(A)) cout << A[i] + 1 << " ";
    cout << endl;
    F0R(i, sz(B)) cout << B[i] + 1 << " ";
    cout << endl;

    string S; cin >> S;
    if (S == "WASTED") return -1;
    if (S == "SECOND") return 1;
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N, K; cin >> N >> K;
        uniform_int_distribution<int> dist(1, N-1);
        int lo = 0, hi = N-1;
        F0R(i, 30) {
            vi A = {0};
            vi B = {dist(rng)};
            int X = query(A, B);
            if (X == -1) return 0;
            if (X) {
                cout << "! " << 1 << endl; goto done;
            }
        }
        F0R(bit, 10) {
            if ((1 << (bit+1)) >= N) {
                lo = (1 << bit);
                hi = N-1;
                break;
            }
            vi A;
            F0R(i, (1 << bit)) {
                A.pb(i);
            }
            vi B;
            FOR(i, (1 << bit), (1 << (bit+1))) {
                if (i < N) B.pb(i);
            }
            int X = query(B, A);
            if (X == -1) return 0;
            if (X) {
                lo = (1 << bit);
                hi = (1 << (bit+1)) - 1;
                break;
            }
        }

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            vi B; FOR(i, lo, mid+1) B.pb(i);
            vi A;
            F0R(i, sz(B)) A.pb(i);
            int X = query(B, A);
            if (X == -1) return 0;
            if (X) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }

        cout << "! " << lo+1 << endl;


        done:
        ;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343