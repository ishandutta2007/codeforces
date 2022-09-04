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

bool query1(int A, int B) {
    cout << "1 " << A << " " << B << endl;
    int X; cin >> X;
    if (X == -1) exit(0);
    return X;
}

bool query2(int A, set<int> &B) {
    if (B.count(A)) return true;
    cout << "2 " << A << " " << sz(B) << " ";
    trav(a, B) cout << a << " ";
    cout << endl;
    int X; cin >> X;
    if (X == -1) exit(0);
    return X;
}

void solve() {

    int N; cin >> N;
    vector<int> A;
    A.pb(0);
    FOR(i, 1, N) {
        int lo = 0, hi = sz(A);
        while(lo < hi) {
            int mid = (lo+hi)/2;
            if (query1(i, A[mid])) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        vi nA;
        F0R(j, lo) {
            nA.pb(A[j]);
        }
        nA.pb(i);
        FOR(j, lo, sz(A)) {
            nA.pb(A[j]);
        }
        A = nA;
    }

    /*F0R(i, N) {
        cout << A[i] << " ";
    }
    cout << "TEST" << nl;*/

    bool ans[N][N]; F0R(i, N) F0R(j, N) {
        if (i <= j) {
            ans[A[i]][A[j]] = true;
        } else {
            ans[A[i]][A[j]] = false;
        }
    }
    int lst = N;
    set<int> cur; F0R(i, N-1) cur.ins(A[i]);
    int p = N-1;
    FORd(i, 0, N) {
        while (p >= 0 && query2(A[i], cur)) {
            p--;
            if (p >= 0) cur.erase(A[p]);
        }
        if (p == i) {
            FOR(j, i, lst) {
                FOR(k, i, j) {
                    ans[A[j]][A[k]] = true;
                }
            }
            lst = i;
        }
    }
    //F0R(i, lst) F0R(j, i) ans[A[i]][A[j]] = true;

    cout << 3 << endl;
    F0R(i, N) {
        F0R(j, N) {
            if (ans[i][j]) {
                cout << 1;
            } else cout << 0;
        }
        cout << endl;
    }
    int X; cin >> X; if (X == -1) exit(0);


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