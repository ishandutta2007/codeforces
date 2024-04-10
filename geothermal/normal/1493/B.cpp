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

    int H, M; cin >> H >> M;
    int X; cin >> X;
    char C; cin >> C;
    int Y; cin >> Y;
    int rev[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
    /*FOR(x, X*M+Y, X*M+Y+H*M) {
        int t = x%(H*M);
        vi digs = {t/M/10, (t/M)%10, (t%M)/10, (t%M)%10};
        vi odigs = digs;
        F0R(i, 4) cout << digs[i];
        F0R(i, 4) {
            if (rev[digs[i]] == -1) goto bad;
            digs[i] = rev[digs[i]];
        }

        if (digs[3] * 10 + digs[2] < H && digs[1] * 10 + digs[0] < M) {
            //cout << odigs[0] << odigs[1] << ":" << odigs[2] << odigs[3] << nl; return;
            cout << " ";
            F0R(i, 4) {
                cout << digs[3-i];
            }
        }

        bad:
        ;
        cout << nl;

    }*/
    FOR(i, X*100+Y, 10000) {
        vi A; int cur = i;
        F0R(it, 4) {
            A.pb(cur%10); cur /= 10;
        }
        vi rA; F0R(i, 4) {
            if (rev[A[i]] == -1) goto bad;
            rA.pb(rev[A[i]]);
        }
        if (A[3] * 10 + A[2] < H && rA[0] * 10 + rA[1] < H && A[1] * 10 + A[0] < M && rA[2] * 10 + rA[3] < M) {
            cout << A[3] << A[2] << ":" << A[1] << A[0] << nl; return;
        }
        bad:
        ;

    }
    cout << "00:00" << nl;

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